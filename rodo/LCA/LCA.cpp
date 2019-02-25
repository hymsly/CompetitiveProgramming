#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = (1e5);

ll LCA[N+2][25];
ll D[N+2][25];
int lvl[N+2];
ll G[N+2];
vector<int> GREV[N+2];
ll C[N+2];
int n;

void dfs(int x,int level){
	lvl[x] = level;
	for(int i=0;i<GREV[x].size();i++) dfs(GREV[x][i],level+1);	
}

void preprocess(){
	for(int i=0;i<n;i++){
		for(int j=0;(1<<j)<n;j++){
			LCA[i][j] = -1;
			D[i][j] = 0;
		}
	}
	for(int i=0;i<n;i++){
		LCA[i][0] = G[i];
		D[i][0] = C[i];
	}
	for(int j=1;(1<<j)<n;j++){
		for(int i=0;i<n;i++){
			if(LCA[i][j-1] != -1){
				LCA[i][j] = LCA[LCA[i][j-1]][j-1];
				D[i][j] = D[i][j-1] + D[LCA[i][j-1]][j-1];
			}
		}
	}
	dfs(0,1);
}

void clear(){
	for(int i=0;i<=n;i++){
		GREV[i].clear();
		G[i] = 0;
		C[i] = 0;
		lvl[i] = 0;
	}
}

int lca(int u,int v){
	if(lvl[u] < lvl[v]) swap(u,v);
	int lg = 31 - (__builtin_clz(lvl[u]));
	for(int i=lg;i>=0;i--){
		if(lvl[u] - (1<<i) >= lvl[v]){
			u = LCA[u][i];
		}
	}
	if(u==v) return u;
	
	for(int i=lg;i>=0;i--){
		if(LCA[u][i] != -1 && LCA[u][i] != LCA[v][i]){
			u = LCA[u][i];
			v = LCA[v][i];
		}
	}
	return G[u];
}

ll dist(int pa,int hi){
	if(pa==hi) return 0;
	int sube = lvl[hi] - lvl[pa];
	ll ans = 0;
	for(int i=0;i<25;i++){
		if(sube & (1<<i)){
			ans += D[hi][i];
			hi = LCA[hi][i];
		}
	}
	return ans;
}

int main(){
	while(cin>>n){
		if(n==0) break;
		clear();
		for(int i=1;i<n;i++){
			cin>>G[i]>>C[i];
			GREV[G[i]].push_back(i);
		}
		preprocess();
		int q;cin>>q;
		vector<ll> ans;
		while(q--){
			int a,b;
			cin>>a>>b;
			int ancestro = lca(a,b);
			ans.push_back(dist(ancestro,a) + dist(ancestro,b));
		}
		for(int i=0;i<ans.size();i++) cout<<ans[i]<<(char)(i+1==ans.size()?10:32);
	}

	return 0;
}

