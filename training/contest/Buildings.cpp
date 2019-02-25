#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = (1e9+7);

ll pot(ll x,ll y){
	if(y==0) return 1;
	if(y==1) return x;
	ll ans = 1;
	if(y&1) ans=x;
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

ll tot;int m;


int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	ll n,k;
	cin>>n>>m>>k;
	if(k==1){
		cout<<1<<'\n';
		return 0;
	}
	tot = pot(k,n*n);
	ll ans = 0;
	for(int i=0;i<m;i++){
		ans += pot(tot,__gcd(i,m));
		ans %= MOD;
	}
	ans *= inv(m);
	ans %= MOD;
	cout<<ans<<'\n';

	return 0;
}

