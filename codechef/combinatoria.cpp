#include<bits/stdc++.h>
//calcula la cantidad de permutaciones de n valores en m grupos
using namespace std;
typedef long long ll;
const int N = (1e6);
const ll MOD = (998244353);


ll fact[N+2];

void init(){
	fact[0] = 1;
	for(int i=1;i<=N;i++) fact[i] = (i*fact[i-1])%MOD;
}

int M[N+2];

ll POT(ll x,ll y){
	if(y==0) return 1LL;
	ll ans = 1;
	if(y&1) ans = x;
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

ll C(ll x,ll y){
	ll ans = fact[x];
	ans *= inv(fact[y]);
	ans %= MOD;
	ans *= inv(fact[x-y]);
	ans %= MOD;
	return ans;
}

int main(){
	init();
	int t;cin>>t;
	int n;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) M[i] = 0;
		int num;
		bool ok=1;
		for(int i=1;i<=n;i++){
			cin>>num;
			M[num]++;
		}
		ll ans = 1;
		for(int i=2;i<=n;i++){
			if(M[i]==0) continue;
			if(M[i]%i!=0){
				ok=0;
				continue;
			}
			ll cnt = (M[i]/i);
			while(M[i]){
				ans *= fact[i-1];
				ans %= MOD;
				ans *= C(M[i],i);
				ans %= MOD;
				M[i] -= i;
			}
			ans *= inv(fact[cnt]);
			ans %= MOD;
		}
		if(ok) cout<<ans<<'\n';
		else cout<<"0\n";
	}

	return 0;
}

