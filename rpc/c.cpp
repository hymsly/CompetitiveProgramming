#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = (1e9+7);
const int N = (1e4);

ll memo[N+2][N+2];

ll dp(ll x,ll maxi){
	if(x==0) return 1LL;
	if(maxi==0) return 0LL;
	if(memo[x][maxi] != -1) return memo[x][maxi];
	ll &ans = memo[x][maxi] = 0;
	ans += dp(x,maxi-1);
	if(x>=maxi) ans += dp(x-maxi,maxi);
	ans %= MOD;
	return ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n;
	memset(memo,-1,sizeof memo);
	while(cin>>n){
		cout<<dp(n,n)<<'\n';
	}

	return 0;
}

