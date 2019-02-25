#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = (2e5);
//GRAFO 1
ll LCA[N+2][25];//LCA el ancestro 
int lvl[N+2];//profundidad del nodo
ll G[N+2], T[N+2];//padres y valor del edge
vector<int> GREV[N+2];//hijos
vector< pair<int,int> >  graph[N+2];
//GRAFO 2
ll LCA2[N+2][25];//LCA el ancestro 
int lvl2[N+2];//profundidad del nodo
ll G2[N+2], T2[N+2];//padres y valor del edge
vector<int> GREV2[N+2];//hijos
vector< pair<int,int> >  graph2[N+2];
vector<int> posible[N+2];
int n;
int ans[N+2];
void dfs(int x,int level,vector<int> hijo[],int nivel[]){
	nivel[x] = level;
	for(int i=0;i<hijo[x].size();i++) dfs(hijo[x][i],level+1,hijo,nivel);
}

void preprocess(ll tsu[][25],ll pa[],bool first){
	for(int i=1;i<=n;i++){
		for(int j=0;(1<<j)<n;j++){
			tsu[i][j] = -1;
		}
	}
	for(int i=1;i<=n;i++){
		tsu[i][0] = pa[i];
	}
	for(int j=1;(1<<j)<n;j++){
		for(int i=1;i<=n;i++){
			if(tsu[i][j-1] != -1){
				tsu[i][j] = tsu[tsu[i][j-1]][j-1];
			}
		}
	}
	if(first) dfs(1,1,GREV,lvl);
	else dfs(1,1,GREV2,lvl2);
}

int lca(int u,int v,ll tsu[][25],int level[],ll pa[]){
	if(level[u] < level[v]) swap(u,v);
	int lg = 31 - (__builtin_clz(level[u]));
	for(int i=lg;i>=0;i--){
		if(level[u] - (1<<i) >= level[v]){
			u = tsu[u][i];
		}
	}
	if(u==v) return u;
	for(int i=lg;i>=0;i--){
		if(tsu[u][i] != -1 && tsu[u][i] != tsu[v][i]){
			u = tsu[u][i];
			v = tsu[v][i];
		}
	}
	return pa[u];
}

void clear(){
	for(int i=0;i<=n;i++){
		GREV[i].clear();
		graph[i].clear();
		G[i] = 0,T[i]=0,lvl[i]=0;
		GREV2[i].clear();
		graph2[i].clear();
		G2[i] = 0,T2[i]=0,lvl2[i]=0;
		posible[i].clear();
	}
	memset(ans,0,sizeof ans);
}

bool vis[N+2];

void root(int x,vector< pair<int,int> > grafo[],vector<int> hijo[],ll edge[],ll pa[]){
	vis[x] = 1;
	for(int i=0;i<grafo[x].size();i++){
		int p = grafo[x][i].first;
		if(vis[p]) continue;
		hijo[x].push_back(p);
		pa[p] = x;
		edge[p] = grafo[x][i].second;
		root(p,grafo,hijo,edge,pa);
	}
}

bool exist(vector<int> busca,int buscado){
	int p = lower_bound(busca.begin(),busca.end(),buscado) - busca.begin();
	if(p==busca.size()) return false;
	if(busca[p]==buscado) return true;
	return false;
}

bool path(int x,int y,int a,int b,ll tsu[][25],int level[],ll pa[]){//verifico si el edge x->y pertenece al camino a->b del arbol tsu,level,pa
	if(lca(y,b,tsu,level,pa)==y && lca(x,b,tsu,level,pa)==x) return true;
	return false;
}

void solve(){
	scanf("%d",&n);
	clear();
	int a,b;
	//PRIMER GRAFO
	for(int i=1;i<n;i++){
		scanf("%d %d",&a,&b);
		graph[a].push_back(make_pair(b,i));
		graph[b].push_back(make_pair(a,i));
	}
	memset(vis,0,sizeof vis);
	root(1,graph,GREV,T,G);
	preprocess(LCA,G,true);
	//SEGUNDO GRAFO
	for(int i=1;i<n;i++){
		scanf("%d %d",&a,&b);
		graph2[a].push_back(make_pair(b,i));
		graph2[b].push_back(make_pair(a,i));
	}
	memset(vis,0,sizeof vis);
	root(1,graph2,GREV2,T2,G2);
	preprocess(LCA2,G2,false);
	for(int i=2;i<=n;i++){
		//analizando al primer grafo
		a = G[i] , b = T[i];
		int padre = lca(a,i,LCA2,lvl2,G2);
		for(int j=2;j<=n;j++){//analizando edge aa
			int aa = G2[j] , bb = T2[j];
			int madre = lca(aa,j,LCA,lvl,G);
			if( (path(aa,j,padre,a,LCA2,lvl2,G2) || path(aa,j,padre,i,LCA2,lvl2,G2) ) && ( path(a,i,madre,aa,LCA,lvl,G) || path(a,i,madre,j,LCA2,lvl2,G2) ) ){
				ans[b]++;
			}
		}
	}
	for(int i=1;i<n;i++){
		printf("%d",ans[i]);
		if(i+1==n) printf("\n");
		else printf(" ");
	}
}

int main(){
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

