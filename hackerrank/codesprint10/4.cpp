#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(x) push_back(x)

#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
#define fi first
#define se second
#define sz(v) ((int)v.size())
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll MOD=(1e9+7);

ll n,k;
ll fact[3005];

ll pot(ll x,ll y){
	if(y==0) return 1;
	if(y==1) return x;
	ll ans=1;
	ll val= pot(x,y/2);
	if(y&1) ans*=x;
	ans*=val;
	ans%=MOD;
	ans*=val;
	ans%=MOD;
	return ans;
}

ll inv(ll x){
	return pot(x,MOD-2)%MOD;
}

ll comb(ll x,ll y){
	return ((fact[x]*inv(fact[y])%MOD)*inv(fact[x-y]))%MOD;
}

ll f(ll cnt,ll block){
	ll ans=1LL;
	ans%=MOD;
	ans*=comb(cnt+cnt-block+2,cnt);
	ans%=MOD;
	return ans;
}

int main(){
	//fast_io()
	fact[0]=1;
	for(ll i=1;i<=3000;i++){
		fact[i]=fact[i-1]*i;
		fact[i]%=MOD;
	}
	int t;cin>>t;
	while(t--){
		cin>>n>>k;
		ll ans=0;
		for(ll u=1;u<=n-k;u++){
			ans += f(n-u,u+1);
			ans%=MOD;
		}	
		cout<<ans<<endl;
	}
	
	return 0;
}

