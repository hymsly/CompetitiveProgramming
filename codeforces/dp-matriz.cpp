#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = (998244353LL);
const ll N = (500);
ll n,k;

ll memo[N+2][N+2];

ll dp2(ll x,ll maxi){
	if(x==n) return 1LL;
	if(memo[x][maxi]!=-1) return memo[x][maxi];
	ll ted = ((k-1)/maxi);
	ll &ans = memo[x][maxi] = 0;
	for(int i=1;i<=ted && x+i<=n;i++){
		ans += dp2(x+i,maxi);
		ans %= MOD;
	}
	return ans;
}

ll memo2[N+2][N+2][2];

ll dp1(ll x,ll maxi,bool ok){
	if(x==n) return ok;
	if(memo2[x][maxi][ok] != -1) return memo2[x][maxi][ok];
	ll &ans = memo2[x][maxi][ok] = 0;
	for(int i=1;i<=maxi && x+i<=n;i++){
		ans += dp1(x+i,maxi,ok|i==maxi);
		ans %= MOD;
	}
	return ans;
}

int main(){
	memset(memo,-1,sizeof memo);
	memset(memo2,-1,sizeof memo2);
	cin>>n>>k;
	ll ans = 0;
	for(int i=1;i<=n;i++){
		ll res = 2*dp1(0,i,0)*dp2(0,i);
		//cout<<"maximo fila: "<<i<<"es => "<<res<<endl;
		//cout<<"dividir columna en maximo "<<i<<" es=>"<<dp1(0,i,0)<<endl;
		//cout<<"dividir fila en maximo "<<i<<" es=>"<<dp2(0,i)<<endl;
		res %= MOD;
		ans += res;
		ans %= MOD;
	}
	cout<<ans<<'\n';

	return 0;
}

