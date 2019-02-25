#include<bits/stdc++.h>

using namespace std;
const int N = (1e5);

vector<int> G[N+2];
vector<int> tree[N+2];
bool vis[N+2];

void root(int x){
	vis[x] = 1;
	for(int i=0;i<G[x].size();i++){
		if(vis[G[x][i]]) continue;
		tree[x].push_back(G[x][i]);
		root(G[x][i]);
	}
}

int memo[N+2][2];

int dp(int x,bool tome){
	if(memo[x][tome] != -1) return memo[x][tome];
	int &ans = memo[x][tome] = 0;
	if(tome){
		for(int i=0;i<tree[x].size();i++){
			ans += min(dp(tree[x][i],0) , 1 + dp(tree[x][i],1));
		}
	}else{
		ans += tree[x].size();
		for(int i=0;i<tree[x].size();i++){
			ans += dp(tree[x][i],1);
		}
	}
	return ans;
}

int main(){
	int n;cin>>n;
	int a,b;
	memset(memo,-1,sizeof memo);
	for(int i=1;i<n;i++){
		cin>>a>>b;
		//cout<<a<<" "<<b<<endl;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	root(1);
	cout<<min(dp(1,0),1+dp(1,1))<<'\n';

	return 0;
}

