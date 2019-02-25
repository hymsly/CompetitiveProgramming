#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define pb push_back
#define SZ(x) (int)x.size()
// Min cut: nodes with dist>=0 vs nodes with dist<0
// Matching MVC: left nodes with dist<0 + right nodes with dist>0
const int N = (100);
int nodes,src,dst; // remember to init nodes
int dist[2*N+5],q[2*N+5],work[2*N+5];
const ll INF = (1e12);
struct edge {int to,rev;ll f,cap;};
vector<edge> g[2*N+5];
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
ll max_flow(int _src, int _dst){
	src=_src;dst=_dst;
	ll result=0;
	while(dinic_bfs()){
		fill(work, work+nodes, 0);
		while(ll delta=dinic_dfs(src,INF))result+=delta;
	}
	return result;
}

int n,m;

ll A[N+2],B[N+2];

ll M[N+2][N+2];

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>A[i];
	for(int i=1;i<=n;i++) cin>>B[i];
	for(int i=1;i<=n;i++){
		add_edge(0,i,A[i]);
		add_edge(i+n,2*n+1,B[i]);
		add_edge(i,i+n,INF);
	}
	while(m--){
		int a,b;
		cin>>a>>b;
		add_edge(a,b+n,INF);
		add_edge(b,a+n,INF);
	}
	nodes = 2*n + 2;
	src = 0;
	dst = 2*n+1;
	ll val = max_flow(src,dst);
	if(val == accumulate(A+1,A+n+1,0LL) && val == accumulate(B+1,B+n+1,0LL)){
		cout<<"YES\n";
		for(int i=1;i<=n;i++){
			for(int j=0;j<SZ(g[i]);j++){
				int fin = g[i][j].to-n;
				if(fin<=0) continue;
				M[i][fin] += g[i][j].f;
			}
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cout<<M[i][j]<<(char)(j==n?10:32);
	}else cout<<"NO\n";

	return 0;
}

