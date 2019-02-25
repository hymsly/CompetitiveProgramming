#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(int i=a,to=b;i<to;i++)
#define pb push_back
typedef long long ll;
const int N = (1e5);
const int K = 18;
const int INF = (1e9);
vector<int> g[1<<K];int n;  // K such that 2^K>=n
vector<int> cost[1<<K];
int F[K][1<<K],D[1<<K],C[K][1<<K],DD[K][1<<K];
int total;
void lca_dfs(int x){
	fore(i,0,g[x].size()){
		int y=g[x][i];if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
		C[0][y]=cost[x][i];
		DD[0][y] = cost[x][i];
	}
}
void lca_init(){
	D[0]=0;F[0][0]=-1;
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n)
		if(F[k-1][x]<0)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]],C[k][x]=max(C[k-1][x],C[k-1][F[k-1][x]]),DD[k][x]=DD[k-1][x]+DD[k-1][F[k-1][x]];
}
int lca(int x, int y){
	if(D[x]<D[y])swap(x,y);
	for(int k=K-1;k>=0;--k)if(D[x]-(1<<k)>=D[y])x=F[k][x];
	if(x==y)return x;
	for(int k=K-1;k>=0;--k)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];
	return F[0][x];
}
int maxCost(int hijo,int padre){
	if(hijo==padre) return 0;
	int ans = 0;
	for(int k=K-1;k>=0;--k){
		if(D[hijo]-(1<<k)>=D[padre]){
			ans = max(ans,C[k][hijo]);
			hijo = F[k][hijo];
		}
	}
	return ans;
}
map<pair<int,int>,int> pesos;
int query(int x,int y){
	int padre = lca(x,y);
	int maximo = max(maxCost(x,padre),maxCost(y,padre));
	return total-maximo+pesos[make_pair(x,y)];
}
struct edge{
	int u,to;ll c;
	edge(int _u,int _to,ll _c){
		u = _u;to = _to;c = _c;
	}
};
bool operator<(const edge &a,const edge &b){
	return a.c<b.c;
}
int pa[N+2];
int Find(int x){
	return (x==pa[x]?x:pa[x]=Find(pa[x]));
}
int Union(int x,int y){
	int xx = Find(x),yy = Find(y);
	pa[xx] = yy;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int r;cin>>n>>r;
	for(int i=0;i<n;i++)pa[i] = i;
	int a,b;ll c;
	vector<edge> prim;
	while(r--){
		cin>>a>>b>>c;
		a--;b--;
		prim.push_back(edge(a,b,c));
		pesos[make_pair(a,b)]=c;
	}
	sort(prim.begin(),prim.end());
	for(int i=0;i<prim.size();i++){
		edge &cur = prim[i];
		if(Find(cur.u)==Find(cur.to)) continue;
		Union(cur.u,cur.to);
		total += cur.c;
		g[cur.u].push_back(cur.to);
		g[cur.to].push_back(cur.u);
		cost[cur.u].push_back(cur.c);
		cost[cur.to].push_back(cur.c);
	}
	lca_init();
	int q;cin>>q;
	while(q--){
		cin>>a>>b;
		a--;b--;
		int pad = lca(a,b);
		cout<<query(a,b)<<'\n';
	}

	return 0;
}

