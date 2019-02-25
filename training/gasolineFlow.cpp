#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fore(i,a,b) for(int i=a,to=b;i<to;i++)
#define SZ(x) (int) x.size()
const int N = (1000);
const int MAXN = (2*N+5);
const ll INF = (1e12);
// Min cut: nodes with dist>=0 vs nodes with dist<0
// Matching MVC: left nodes with dist<0 + right nodes with dist>0
struct edge {int to,rev;ll f,cap;};
struct Dinic{
	int nodes,src,dst; // remember to init nodes
	int dist[MAXN],q[MAXN],work[MAXN];
	vector<edge> g[MAXN];
	Dinic(){}
	Dinic(int _nodes,int _src,int _dst){
		nodes = _nodes;src = _src;dst = _dst;
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
	ll max_flow(){
		ll result=0;
		while(dinic_bfs()){
			fill(work, work+nodes, 0);
			while(ll delta=dinic_dfs(src,INF))result+=delta;
		}
		return result;
	}
};

int n,m,t,tot;
int A[N+2],D[N+2];
vector< pair<int,int> > g[N+2];

bool can(int time){
	Dinic dinic(n+m+2,0,n+m+1);
	for(int i=1;i<=n;i++) dinic.add_edge(0,i,A[i]);
	for(int i=1;i<=m;i++) dinic.add_edge(i+n,n+m+1,D[i]);
	for(int i=1;i<=n;i++){
		for(int j=0;j<SZ(g[i]);j++){
			if(g[i][j].second>time) continue;
			dinic.add_edge(i,g[i][j].first+n,INF);
		}
	}
	int res = dinic.max_flow();
	if(res==tot) return true;
	return false;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++) cin>>A[i];
	tot = accumulate(A+1,A+n+1,0);
	for(int i=1;i<=m;i++) cin>>D[i];
	int a,b,c;
	for(int i=1;i<=t;i++){
		cin>>a>>b>>c;
		g[a].pb(make_pair(b,c));
	}
	int lo=1,hi=(1e6);
	if(!can(hi)){
		cout<<"-1\n";
		return 0;
	}
	while((hi-lo)>1){
		int mi = (hi+lo)/2;
		if(can(mi)) hi=mi;
		else lo=mi;
	}
	cout<<hi<<'\n';
	return 0;
}

