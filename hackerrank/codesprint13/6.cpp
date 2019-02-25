#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = (2e5);
const ll INF = (1e9);

ll LCA[N+2][25];
ll D[N+2][25];
int lvl[N+2];
ll G[N+2];
vector<int> GREV[N+2];
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
		D[i][0] = 1;
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

set<int> S;//caminos borrados

ll dist(int pa,int hi){
	if(pa==hi) return 0;
	set<int> :: iterator it;
	bool ok=1;
	for(it=S.begin();it!=S.end();it++){
		int p = (*it);
		if(p==pa) continue;
		if(lca(hi,p)==p) ok=0;
	}
	if(!ok) return -INF;
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

vector<int> tree[N+2];
bool used[N+2];
void root(int x){
	used[x] = 1;
	for(int i=0;i<tree[x].size();i++){
		int p = tree[x][i];
		if(used[p]) continue;
		GREV[x].push_back(p);
		G[p] = x;
		root(p);
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n;
	clear();
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	root(0);
	preprocess();
	int q;cin>>q;
	char type;
	while(q--){
		cin>>type;
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		if(type=='q'){
			int ancestro = lca(a,b);
			ll respuesta = dist(ancestro,a) + dist(ancestro,b);
			if(respuesta<0) cout<<"Impossible\n";
			else cout<<respuesta<<'\n'; 
		}else if(type=='d'){
			if(a==b) continue;
			if(G[a]==b){
				S.insert(a);
			}else if(G[b]==a){
				S.insert(b);
			}
		}else{
			if(a==b) continue;
			if(G[a]==b){
				S.erase(a);
			}else if(G[b]==a){
				S.erase(b);
			}
		}
	}

	return 0;
}

