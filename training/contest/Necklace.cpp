#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = (1e9+7);

ll pot(ll x,ll y){
	if(y==0) return 1;
	if(y==1) return x;
	ll ans = 1;
	if(y&1) ans = x;
	ll val = pot(x,y/2);
	ans *= val;
	ans %= MOD;
	ans *= val;
	ans %= MOD;
	return ans;
}

ll inv(ll x){
	return pot(x,MOD-2);
}

void solve(int x){
	ll n,k;cin>>n>>k;
	ll ans = 0;
	for(int i=0;i<n;i++){
		ans+=pot(k,__gcd(n,(ll)i));
		ans %= MOD;
	}
	ans *= inv(n);
	ans %= MOD;
	cout<<"Case "<<x<<": "<<ans<<'\n';
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	for(int i=1;i<=t;i++) solve(i);

	return 0;
}

