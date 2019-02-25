#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
const int N = (1e5);
const int K = (18);
const int MAXN = (1<<K);
const int INF = (2*N);
vector<int> g[MAXN];int n;
bool tk[MAXN];
int fat[MAXN]; // father in centroid decomposition
int szt[MAXN]; // size of subtree
int calcsz(int x, int f){
	szt[x]=1;
	for(auto y:g[x])if(y!=f&&!tk[y])szt[x]+=calcsz(y,x);
	return szt[x];
}
void cdfs(int x=0, int f=-1, int sz=-1){ // O(nlogn)
	if(sz<0)sz=calcsz(x,-1);
	for(auto y:g[x])if(!tk[y]&&szt[y]*2>=sz){
		szt[x]=0;cdfs(y,f,sz);return;
	}
	tk[x]=true;fat[x]=f;
	for(auto y:g[x])if(!tk[y])cdfs(y,x);
}
void centroid(){memset(tk,false,sizeof(tk));cdfs();}

int F[K][1<<K],D[1<<K];
void lca_dfs(int x){
	fore(i,0,g[x].size()){
		int y=g[x][i];if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
	}
}
void lca_init(){
	D[0]=0;F[0][0]=-1;
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n)
		if(F[k-1][x]<0)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
}
int lca(int x, int y){
	if(D[x]<D[y])swap(x,y);
	for(int k=K-1;k>=0;--k)if(D[x]-(1<<k)>=D[y])x=F[k][x];
	if(x==y)return x;
	for(int k=K-1;k>=0;--k)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];
	return F[0][x];
}
int dist(int x, int y){return D[x]+D[y]-2*D[lca(x,y)];}
int c[MAXN];
multiset<int> w[MAXN];
int main(){
	cin>>n;
	int a,b;
	for(int i=1;i<n;i++){
		cin>>a>>b;
		a--;b--;
		g[a].pb(b);g[b].pb(a);
	}
	lca_init();
	centroid();
	int q;cin>>q;
	int t,x;
	while(q--){
		cin>>t>>x;
		x--;
		if(t==0){
			c[x]^=1;
			for(int y=x;y>=0;y=fat[y]){
				if(c[x])w[y].insert(dist(x,y));
				else w[y].erase(w[y].find(dist(x,y)));
			}
		}else{
			int ans = INF;
			for(int y=x;y>=0;y=fat[y]){
				if(!w[y].empty())ans = min(ans,(*w[y].begin()) + dist(y,x));
			}
			cout<<(ans==INF?-1:ans)<<'\n';
		}
	}
}
