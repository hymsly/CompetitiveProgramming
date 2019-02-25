#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (2e9);
const int N = (1e5);
ll C[N+2];
int n;
vector<int> G[N+2];
bool vis[N+2];
vector<int> COMP[N+2];

void addEdge(int x,int y){
	G[x].push_back(y);
	G[y].push_back(x);
}
void dfs(int x,int id){
    vis[x] = 1;
    COMP[id].push_back(x);
    for(int i=0;i<G[x].size();i++){
        if(vis[G[x][i]]) continue;
        dfs(G[x][i],id);
    }
}
ll id=0;
void group(){
	for(int i=1;i<=n;i++){
		if(!vis[i]) dfs(i,id++);	
	}
}

int main(){
	//ios_base::sync_with_stdio(0);
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>C[i];
	int a,b;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		addEdge(a,b);
	}
	group();
	ll ans = 0;
	for(int i=0;i<id;i++){
		ll mini = INF;
		for(int j=0;j<COMP[i].size();j++){
			mini = min(mini,C[COMP[i][j]]);
		}
		ans += mini;
	}
	cout<<ans<<'\n';
	
	return 0;
}

