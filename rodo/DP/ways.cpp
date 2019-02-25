#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll memo[30005][6];
ll d[6] = {0,1,5,10,25,50};


ll dp(int x,int y){
	if(x==0) return 1;
	if(memo[x][y] != -1) return memo[x][y];
	if(x < d[y]) return dp(x,y-1);
	ll &ans = memo[x][y] = 0;
	ans += dp(x-d[y],y);
	if(y>1){
		ans += dp(x,y-1);
	}
	return ans;
}

int main(){
	memset(memo,-1,sizeof memo);
	int t;
	while(cin>>t){
		ll ans = dp(t,5);
		if(ans==1) cout<<"There is only 1 way to produce "<<t<<" cents change.\n";
		else cout<<"There are "<<ans<<" ways to produce "<<t<<" cents change.\n";
	}

	return 0;
}

