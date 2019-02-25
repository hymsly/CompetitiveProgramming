#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define pb push_back
#define fore(i,a,b) for(int i=a,to=b;i<to;i++)
#define SZ(x) (int) x.size()
#define MAX 75001
using namespace std;
typedef long long ll;
const int MAXN = (3000+5);
const ll INF = (1e12);
// Min cut: nodes with dist>=0 vs nodes with dist<0
// Matching MVC: left nodes with dist<0 + right nodes with dist>0
int dist[MAXN],q[MAXN],work[MAXN];
struct edge {int to,rev;ll f,cap;};

struct Dinic{
	int nodes,src,dst; // remember to init nodes
	vector<edge> g[MAXN];
	Dinic(){}
	Dinic(int _nodes){
		nodes = _nodes;
	}
	void add_edge(int s, int t, ll cap){
		g[s].pb((edge){t,SZ(g[t]),0,cap});
		g[t].pb((edge){s,SZ(g[s])-1,0,0});
	}
	bool dinic_bfs(){
		fill(dist,dist+nodes,-1);dist[src]=0;
		int qt=0;q[qt++]=src;
		for(int qh=0;qh<qt;qh++){
			int u=q[qh];
			fore(i,0,SZ(g[u])){
				edge &e=g[u][i];int v=g[u][i].to;
				if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
			}
		}
		return dist[dst]>=0;
	}
	ll dinic_dfs(int u, ll f){
		if(u==dst)return f;
		for(int &i=work[u];i<SZ(g[u]);i++){
			edge &e=g[u][i];
			if(e.cap<=e.f)continue;
			int v=e.to;
			if(dist[v]==dist[u]+1){
				ll df=dinic_dfs(v,min(f,e.cap-e.f));
				if(df>0){e.f+=df;g[v][e.rev].f-=df;return df;}
			}
		}
		return 0;
	}
	ll max_flow(int _src,int _dst){
		ll result=0;
		src = _src;
		dst = _dst;
		while(dinic_bfs()){
			fill(work, work+nodes, 0);
			while(ll delta=dinic_dfs(src,INF))result+=delta;
		}
		return result;
	}
};

int main() {
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n,m;cin>>n>>m;
	int k;cin>>k;
	vector< pair<int,int> > v(k);
	for(int i=0;i<k;i++) cin>>v[i].first>>v[i].second;
	ll maximo = 0;
	for(int j=1;j<=n;j++){
		Dinic D(n+m+2);
		
		for(int i=1;i<=n;i++){
			if(i != j) D.add_edge(0, i, 1);
			else D.add_edge(0,i,3);
		}
		for(int i=1;i<=m;i++){
			D.add_edge(i+n, n+m+1, 1);
		}
		for(int i=0;i<k;i++){
			D.add_edge(v[i].first,v[i].second+n,1);			
		}
		ll resp = D.max_flow(0,n+m+1);
		maximo = max(resp,maximo);
	
	}
	cout<<maximo<<'\n';	
	
	

	return 0;
}
