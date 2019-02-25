#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const N=(1e4);
ll n,k,m,cnt;
vector< vector <ll> > memo;
ll dp(int pos,int cant){
	if(pos==n){
		if(cant==cnt) return 1LL;
		else return 0LL;
	}
	if(cant>=cnt) return 0LL;
	if(memo[pos][cant]!=-1) return memo[pos][cant];
	ll &ans = memo[pos][cant] = 0;
	for(int i=1;i<=k && pos+i<=n;i++){
		ans += dp(pos+i,cant+1);
		ans%=m;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;cin>>t;
	while(t--){
		cin>>n>>k>>m;
		cnt = n/k +(n%k>0);
		memo.resize(n);
		for(int i=0;i<n;i++){
			memo[i].resize(cnt);
			for(int j=0;j<cnt;j++) memo[i][j]=-1;
		}
		cout<<cnt<<" "<<dp(0,0)<<'\n';
	}
	
	return 0;
}

