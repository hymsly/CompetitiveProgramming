#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fore(i,a,b) for(int i=a,to=b;i<to;i++)
#define SZ(z) (int) z.size()
#define pb push_back
const int N = (1000);
const int MAXN = (500);
const ll INF = (1e12);
struct edge{int to,rev;ll f,cap;};
struct Dinic{
	int nodes,src,dst;
	int dist[MAXN],q[MAXN],work[MAXN];
	vector<edge> g[MAXN];
	Dinic(){}
	Dinic(int _nodes,int _src,int _dst){
		nodes = _nodes;src = _src;dst = _dst;
	}
	void add_edge(int s,int t,ll cap){
		g[s].pb((edge){t,SZ(g[t]),0,cap});
		g[t].pb((edge){s,SZ(g[s])-1,0,0});
	}
	bool dinic_bfs(){
		fill(dist,dist+nodes,-1);dist[src] = 0;
		int qt = 0;q[qt++] = src;
		for(int qh=0;qh<qt;qh++){
			int u = q[qh];
			fore(i,0,SZ(g[u])){
				edge &e = g[u][i];int v = g[u][i].to;
				if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
			}
		}
		return dist[dst]>=0;
	}
	ll dinic_dfs(int u,ll f){
		if(u==dst) return f;
		for(int &i=work[u];i<SZ(g[u]);i++){
			edge &e = g[u][i];
			if(e.cap<=e.f) continue;
			int v = e.to;
			if(dist[v]==dist[u]+1){
				ll df=dinic_dfs(v,min(f,e.cap-e.f));
				if(df>0){
					e.f+=df;g[v][e.rev].f-=df;return df;
				}
			}
		}
		return 0;
	}
	ll max_flow(){
		ll result = 0;
		while(dinic_bfs()){
			fill(work,work+nodes,0);
			while(ll delta=dinic_dfs(src,INF))result+=delta;
		}
		return result;
	}
};

int n,m;

void solve(){
	cin>>n>>m;
	Dinic dinic(n+m+2,0,n+m+1);
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		int p;
		while(k--){
			cin>>p;
			dinic.add_edge(i,n+p,1);
		}
		dinic.add_edge(0,i,1);
	}
	for(int i=1;i<=m;i++)dinic.add_edge(n+i,n+m+1,1);
	int val = dinic.max_flow();
	if(val==n)cout<<"YES\n";
	else cout<<"NO\n";
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

