#include<bits/stdc++.h>

using namespace std;

vector<int> v;
vector<int> w;
int n;
int query(int x,int pos){
	int lo=0,hi=n-1;
	int mi;
	int a=0,b=0;//a abajo y b arriba
	int ans=0;
	while(lo<=hi){
		mi = (hi+lo)/2;
		if(mi==pos) break;
		else if(mi < pos){
			lo=mi+1;
			a++;
			if(v[mi] > x){
				ans++;
			}
		}else{
			hi=mi-1;
			b++;
			if(v[mi] < x){
				ans++;
			}
		}
	}
	int p = lower_bound(w.begin(),w.end(),x)-w.begin();
	if(p<a || (n-1-p)<b) return -1;
	return ans;
}
int q;

void solve(){
	cin>>n>>q;
	v.resize(n);
	for(int i=0;i<n;i++) cin>>v[i];
	w = v;
	sort(w.begin(),w.end());
	map<int,int> M;
	for(int i=0;i<n;i++) M[v[i]]=i;
	int num;
	while(q--){
		cin>>num;
		int p = query(num,M[num]);
		cout<<p<<'\n';
	}
}

int main(){
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

