#include <bits/stdc++.h>
using namespace std;


int n;
int N=1;
double pr[100000];
pair<double,double> seg[400000];
bool ze(double d){
	return (abs(d) <= 0.0000000001);
}
pair<double,double> merge(pair<double,double> a, pair<double,double> b){
	if(ze(a.first+1) && ze(a.second+1)) return b;
	if(ze(b.first+1) && ze(b.second+1)) return a;
	double l1 = a.first;
	double r1 = a.second;
	double l2 = b.first;
	double r2 = b.second;
	if(ze(((l2-1)*r1+1))) return make_pair(0,0);
	double le = l1*l2/((l2-1)*r1+1);
	double ri = r2+(r1*l2*(-r2+1))/(-r1*(-l2+1)+1);
	return make_pair(le,ri);
}
void build(){
	for(int i=N-1;i>0;i--) seg[i] = merge(seg[2*i],seg[2*i+1]);	
}
void update(int pos, double val){
	pos += N;
	seg[pos] = make_pair(val,val);
	while(pos>1){
		if(pos&1) seg[pos>>1] = merge(seg[pos-1],seg[pos]);
		else seg[pos>>1] = merge(seg[pos],seg[pos+1]);
		//seg[pos>>1] = merge(seg[pos],seg[pos^1]);
		pos >>=1;
	}
}
pair<double,double> query(int l, int r){
	l+=N;
	r+=N;
	vector<pair<double,double> > res1,res2;
	while(l<r){
		if(l&1) res1.push_back(seg[l++]);
		if(r&1) res2.push_back(seg[--r]);
		l>>=1;
		r>>=1;
	}
	reverse(res2.begin(),res2.end());
	for(int i=0;i<res2.size();i++) res1.push_back(res2[i]);
	pair<double,double> ans = res1[0];
	for(int i=1;i<res1.size();i++) ans = merge(ans,res1[i]);
	return ans;
}
int main(){
    int q;
	cin>>n>>q;
	while(N<n) N<<=1;
	for(int i=0; i < n; i++){
		int a,b;
		cin>>a>>b;
		seg[i+N] = make_pair((double)a / (double)b,(double)a / (double)b);
	}
	build();
	for(int que = 0; que < q; que++){
		int ty;
		int a;
		int b;
		cin>>ty>>a>>b;
		if(ty==1){
			int c;
			cin>>c;
			update(a-1,(double)b / (double)c);
		}
		else{
		    printf("%.5f\n", query(a-1,b).first);
		}
	}
	
	return 0;
}
