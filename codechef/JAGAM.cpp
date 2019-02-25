#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	ll n,z1,z2;cin>>n>>z1>>z2;
	vector<ll> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	bool ok=0;
	for(int i=0;i<n;i++){
		if(abs(v[i])==abs(z1) || abs(v[i])==abs(z2)) ok=1;
	}
	if(ok){
		cout<<1<<'\n';
		return;
	}
	if(z1==0 || z2==0){
		cout<<2<<'\n';
		return;
	}
	set<int> s;
	for(int i=0;i<n;i++) s.insert(abs(v[i]));
	if(s.size()>2){
		cout<<0<<'\n';
		return;
	}
	if(z1+z2==0){
		int p = *s.begin(),q=*s.rbegin();
		if(abs(z1)==p+q){
			cout<<2<<'\n';
		}else{
			cout<<0<<'\n';
		}
	}else{
		cout<<0<<'\n';
		return;
	}
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

