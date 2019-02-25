#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = (5000);

ll memo[N+2][N+2];
ll ans[N+2][N+2];
ll A[N+2];

ll dp(int l,int r){//rango [l,r]
	if(r<l) return 0;
	if(memo[l][r]!=-1) return memo[l][r];
	if(r==l) return A[r];
	ll &res = memo[l][r] = 0;
	res = dp(l,r-1);
	res ^= dp(l+1,r);
	return res;
}

ll query(int l,int r){
	if(r<l) return 0;
	if(ans[l][r]!=-1) return ans[l][r];
	ll &res = ans[l][r] = 0;
	res = max(res,query(l,r-1));
	res = max(res,query(l+1,r));
	res = max(res,dp(l,r));
	return res;
}

int main(){
	int n;cin>>n;
	memset(memo,-1,sizeof memo);
	memset(ans,-1,sizeof ans);
	for(int i=1;i<=n;i++) cin>>A[i];
	int q;cin>>q;
	int l,r;
	while(q--){
		cin>>l>>r;
		cout<<query(l,r)<<'\n';
	}

	return 0;
}

