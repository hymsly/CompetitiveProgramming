#include<bits/stdc++.h>
using namespace std;
#define SZ(a) (int)a.size()
#define pb push_back
#define fore(i,a,b) for(int i=a,to=b;i<to;i++)
#define fi first
#define snd second
typedef long long ll;
const int N = (50);
const int MAXN = (2*N+10);
const ll INF = (1e12);

struct edge {int to,rev;ll f,cap;};

struct Dinic{
	int nodes,src,dst;
	int dist[MAXN],q[MAXN],work[MAXN];
	vector<edge> g[MAXN];
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

bool vis[N+5];

void solve(int n){
	int ans = 0;
	vector< pair<int,int> > v(n);
	for(int i=0;i<n;i++) cin>>v[i].fi>>v[i].snd;
	for(int i=0;i<n;i++){
		int src = 0,dst = 2*n+1;
		Dinic dinic(2*n+2,src,dst);
		memset(vis,0,sizeof vis);
		int votos = 0;
		for(int j=0;j<n;j++) if(i!=j) dinic.add_edge(src,j+1,1);
		for(int j=0;j<n;j++){
			if(j==i){
				vis[v[j].fi]=1;
				vis[v[j].snd]=1;
			}else if(v[j].fi==i+1 || v[j].snd==i+1) votos++;
			else{
				dinic.add_edge(j+1,v[j].fi+n,1);
				dinic.add_edge(j+1,v[j].snd+n,1);
			}
		}
		if(votos<=1){
			ans++;
			continue;
		}
		for(int j=0;j<n;j++){
			if(i==j) continue;
			if(vis[j+1]) dinic.add_edge(j+1+n,dst,votos-2);
			else dinic.add_edge(j+1+n,dst,votos-1);
		}
		int faltan = n-votos-1;
		int flow = dinic.max_flow();
		if(flow < faltan) ans++;
	}
	cout<<ans<<'\n';
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n;
	while(cin>>n) solve(n);


	return 0;
}

