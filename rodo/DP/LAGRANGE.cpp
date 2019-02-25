#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll memo[(1<<15)+1][5][205];


ll dp(int x,int cnt,int limit){
	if(x==0) return 1;
	if(cnt==0) return 0;
	if(memo[x][cnt][limit] != -1) return memo[x][cnt][limit];
	if(limit*limit > x && limit > 1) return dp(x,cnt,limit-1);
	ll &ans = memo[x][cnt][limit] = 0;
	ans += dp(x-limit*limit,cnt-1,limit);
	if(limit > 1) ans += dp(x,cnt,limit-1);
	return ans;
}

int main(){
	memset(memo,-1,sizeof memo);
	int n;
	while(cin>>n){
		if(n==0) break;
		cout<<dp(n,4,200)<<'\n';
	}
	return 0;
}

