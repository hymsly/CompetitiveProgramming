#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (1e3);
const ll MOD = (1e9+7);

ll memo[N+2][20*N+5];
ll A[N+2];
int n;

ll dp(int pos,ll sum){
	if(memo[pos][sum+10*N] != -1) return memo[pos][sum+10*N];
	ll &ans = memo[pos][sum+10*N] = (sum==0);
	if(pos>n) return ans;
	ans += dp(pos+1,sum+A[pos]);
	ans %= MOD;
	ans += dp(pos+1,sum-A[pos]);
	ans %= MOD;
	return ans;
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>A[i];
	memset(memo,-1,sizeof memo);
	ll ans = 0;
	for(int i=n;i>=1;i--) ans+=(dp(i,0)-1),ans%=MOD;
	cout<<ans<<'\n';

	return 0;
}

