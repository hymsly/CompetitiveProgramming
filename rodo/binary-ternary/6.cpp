#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=(1e18);
vector<ll> v;
ll n,l,a,b;

ll f(ll x){
	ll pos = x;
	ll ans=0;
	for(ll i=0;i<n;i++){
		ans+=abs(v[i]-pos);
		pos+=l;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n>>l>>a>>b;
		v.resize(n);
		for(int i=0;i<n;i++) cin>>v[i];
		sort(v.begin(),v.end());
		ll lo=a,hi=b-l*n;
		while((hi-lo)>2){
			ll mi1 = (2*lo + hi)/3;
			ll mi2 = (lo + 2*hi)/2;
			if(f(mi1) > f(mi2)) lo=mi1;
			else hi=mi2;
		}
		ll ans = INF;
		for(ll i=lo;i<=hi;i++){
			ans = min(ans,f(i));
		}
		cout<<ans<<'\n';
	}

	return 0;
}


