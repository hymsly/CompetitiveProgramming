#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = (1e9+7);
const int N = (2e6);

ll f[N+2];//mod 
ll f2[N+2];//c

ll fibo[N+2];//mod
ll fibo2[N+2];//c

ll fact[N+2];//mod
ll fact2[N+2];//c

void fill(ll x){//modulo x
	memset(fact2,0,sizeof fact2);
	memset(fibo2,0,sizeof fibo2);
	memset(f2,0,sizeof f2);
	fibo2[1] = 1%x;
	fibo2[2] = 2%x;
	for(int i=3;i<=N;i++){
		fibo2[i] = (fibo2[i-1]+fibo2[i-2])%x;
	}
	fact2[1] = 1%x;
	for(int i=2;i<=N;i++) fact2[i] = (i*fact2[i-1])%x;
	for(int i=1;i<=N;i++){
		f2[i] = f2[i-1] + (fibo2[i]*fact2[i]);
		f2[i]%=x;
	}
}

void init(){
	fibo[1] = 1;
	fibo[2] = 2;
	for(int i=3;i<=N;i++){
		fibo[i] = (fibo[i-1]+fibo[i-2])%MOD;
	}
	fact[1] = 1;
	for(int i=2;i<=N;i++) fact[i] = (i*fact[i-1])%MOD;
	for(int i=1;i<=N;i++){
		f[i] = f[i-1] + (fibo[i]*fact[i]);
		f[i]%=MOD;
	}
}

ll POT(ll x,ll y){
	if(y==0) return 1;
	if(y==1) return x;
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
	return POT(x,MOD-2)%MOD;
}

int main(){
	init();
	int t;cin>>t;
	ll a,b,c;
	while(t--){
		cin>>a>>b>>c;
		fill(c);
		ll ans = f[b]-f[a-1];
		ans %= MOD;
		ans += MOD;
		ans %= MOD; 
		ans -= ((f2[b]-f2[a-1])%c+c)%c;
		ans %= MOD;
		ans += MOD;
		ans %= MOD;
		ans *= inv(c);
		ans %= MOD;
		cout<<ans<<'\n';
	}

	return 0;
}

