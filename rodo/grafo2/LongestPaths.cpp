#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (100);
int n,src;

vector<int> G[N+2];

int memo[N+2];
int dp(int x){
	if(memo[x]!=-1) return memo[x];
	int &ans = memo[x] = 0;
	for(int i=0;i<G[x].size();i++) ans = max(ans,dp(G[x][i]) + 1);
	return ans;
}

int rec(int x,int ans){
	if(ans==0) return x;
	int res = n+1;
	for(int i=0;i<G[x].size();i++){
		int p = G[x][i];
		if(memo[p]+1 == ans) res=min(rec(p,ans-1),res);
	}
	return res;
}
int caso;

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	bool ok=0;
	while(cin>>n){
		if(n==0) break;
		for(int i=1;i<=n;i++) G[i].clear();
		memset(memo,-1,sizeof memo);
		cin>>src;
		int p,q;
		while(cin>>p>>q){
			if(p==0 && q==0) break;
			G[p].push_back(q);
		}
		for(int i=1;i<=n;i++) sort(G[i].begin(),G[i].end());
		int len = dp(src);
		int last = rec(src,len);
		cout<<"Case "<<++caso<<": The longest path from "<<src<<" has length "<<len<<", finishing at "<<last<<".\n\n";
	}

	return 0;
}

