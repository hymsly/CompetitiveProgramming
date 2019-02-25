#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (3e5);

ll memo[N+2];
ll A[N+2];
int n,m;

ll dp(int pos){
	if(pos>=n) return 0LL;
	if(memo[pos] != -1) return memo[pos];
	ll &ans = memo[pos] = 0;
	ans = max(ans,dp(pos+1));
	ans = max(ans,A[pos] + dp(pos+m));
	return ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	memset(memo,-1,sizeof memo);
	for(int i=0;i<n;i++) cin>>A[i];
	cout<<dp(m)<<'\n';

	return 0;
}

