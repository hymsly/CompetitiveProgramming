#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll h;

vector<ll> v;

ll f(ll x){
	ll ans = 0;
	for(int i=0;i<n;i++){
		ans += (v[i]/x) + (v[i]%x>0);
	}
	return ans;
}

void solve(){
	cin>>n>>h;
	v.resize(n);
	for(int i=0;i<n;i++) cin>>v[i];
	ll lo=1,hi=(1e18);
	while((hi-lo)>1){
		ll mi = (hi+lo)/2;
		if(f(mi)>h) lo=mi;
		else hi=mi;
	}
	cout<<hi<<endl;
}

int main(){
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}

