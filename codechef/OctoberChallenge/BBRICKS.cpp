#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (1e3);
const ll MOD = (1e9+7);

ll pot(ll x,ll y){
	if(y==0) return 1LL;
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

ll C(ll x,ll y){
	ll ans = 1;
	for(int i=1;i<=y;i++){
		ans *= (x-i+1);
		ans %= MOD;
		ans *= inv(i);
		ans %= MOD;
	}
	return ans;
}

ll choose(int x,int y){
	if(y==0) return 1LL;
	int up = x-y+1;
	int down = y;
	if(down>up) return 0;
	return C(up,down);
}

void solve(){
	int n,k;
	cin>>n>>k;
	if(k>n) cout<<0<<'\n';
	else{
		ll ans = 0;
		for(int i=0;i<=k;i++){
			ans += choose(n,i)*choose(n-i+1,k-i);
			ans %= MOD;
		}
		cout<<ans<<'\n';
	}
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

