#include<bits/stdc++.h>
 
using namespace std;
 
struct node{
	int value,feq;
	int der,cnt1;
	int izq,cnt2;
	node(){value=-1;feq=0;der=-1;cnt1=0;izq=-1;cnt2=0;}
	node(int _value,int _feq,int _der,int _cnt1,int _izq,int _cnt2){
		value = _value;
		feq = _feq;
		der = _der;
		cnt1 = _cnt1;
		izq = _izq;
		cnt2 = _cnt2;
	}
	void show(){
		cout<<"valor mas frequente: "<<value<<endl;
		cout<<"frecuencia: "<<feq<<endl;
		cout<<"valor mas derecha: "<<der<<endl;
		cout<<"frecuencia: "<<cnt1<<endl;
		cout<<"valor mas izquierda: "<<izq<<endl;
		cout<<"frecuencia: "<<cnt2<<endl;
	}
};
 
node ST[100005][25];
int A[100005];
int n;
node merge(node x,node y){
	if(x.der==y.izq && x.der!=-1){
		int len1 = y.feq;
		int len2 = x.cnt1+y.cnt2;
		int len3 = x.feq;
		if(len1>=len2 && len1>=len3){
			return node(y.value,y.feq,y.der,y.cnt1,x.izq,x.cnt2);
		}else if(len1>=len2){
			return node(x.value,x.feq,y.der,y.cnt1,x.izq,x.cnt2);
		}else{
			return node(y.izq,len3,y.der,y.cnt1,x.izq,x.cnt2);
		}
	}else{
		
	}
}
 
void build(){
	for(int i=0;i<n;i++) ST[i][0] = node(A[i],1,-1,0,-1,0);
	for(int j=1;(1<<j)<=n;j++){
		for(int i=0;i+(1<<j)<=n;i++) ST[i][j] = merge(ST[i][j-1] , ST[i + (1<<(j-1))][j-1]);
	}
}
 
int query(int l,int r){
	node ans = node(-1,0,-1,0,-1,0);
	int d = r-l;
	for(int i=0;i<30;i++){
		if((1<<i) & d){
			ans = merge(ST[l][i],ans);
			l+=(1<<i);
		}
	}
	return ans.feq;
}
 
int main(){
	int q;
	cin>>n>>q;
	for(int i=0;i<n;i++) cin>>A[i];
	for(int i=0;i<n;i++) A[i] += 100000;
	build();
	for(int i=0;i<n;i++){
		for(int j=0;i+(1<<j)<=n;j++){
			cout<<"["<<i<<","<<i+(1<<j)<<">\n";
			ST[i][j].show();
		}
		cout<<endl;
	}
	int l,r;
	while(q--){
		cin>>l>>r;
		l--;
		cout<<query(l,r)<<'\n';
	}
 
	return 0;
}
