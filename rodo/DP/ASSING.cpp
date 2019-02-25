#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 20;

ll memo[(1<<N)];
ll d[N];
int n;

ll dp(int mask){
	if(mask+1 == (1<<n)) return 1;
	if(memo[mask] != -1) return memo[mask];
	int pos = __builtin_popcount(mask);
	ll &ans = memo[mask] = 0;
	for(int i=0;i<n;i++){
		if(mask & (1<<i)) continue;
		if(d[pos] & (1<<i)){
			ans += dp(mask + ( 1<<i ));
		}
	}
	return ans;
}

void solve(){
	cin>>n;
	memset(memo,-1,sizeof memo);
	memset(d,0,sizeof d);
	for(int i=0;i<n;i++){
		int num;
		for(int j=0;j<n;j++){
			cin>>num;
			if(num==1) d[i] += (1<<j);
		}
	}
	//for(int i=0;i<n;i++) cout<<d[i]<<(char)(i+1==n?10:32);
	cout<<dp(0)<<'\n';
}

int main(){
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}

