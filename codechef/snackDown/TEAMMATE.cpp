#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = (1e9+7);
const ll N = (1e5);

ll POT(ll x,ll y){
	if(y==0) return 1LL;
	if(y==1) return x;
	ll ans = 1;
	if(y&1) ans =x;
	ll val = POT(x,y/2);
	ans *= val;
	ans %= MOD;
	ans *= val;
	ans %= MOD;
	return ans;
}

ll inv(ll x){
	return POT(x,MOD-2);
}

ll F[N+2];

ll pairs(ll x,int ok){
	ll ans = F[x];
	if(ok)x--;
	ans *= inv(F[x/2]);
	ans %= MOD;
	ans *= inv(POT(2,x/2));
	ans %= MOD;
	return ans;
}

void init(){
	F[0]=1;
	for(ll i=1;i<=N;i++) F[i]=(F[i-1]*i)%MOD;
}

void solve(){
	int n;cin>>n;
	map<ll,ll> M;
	for(int i=0;i<n;i++){
		ll x;cin>>x;M[-x]++;
	}
	map<ll,ll> :: iterator it;
	vector<ll> can;
	for(it=M.begin();it!=M.end();it++) can.push_back((*it).second);
	int ok=0;
	ll ans = 1;
	for(int i=0;i<can.size();i++){
		ans*=pairs(can[i],ok);
		ans%=MOD;
		ok^=(can[i]%2);
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	init();
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

