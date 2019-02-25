#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define SZ(x) (int) x.size()
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
typedef long long ll;
const int N = (100);
const int MAXN = (5*N+5);
const ll INF = (1e12);

int nodes,src,dst; // remember to init nodes
int dist[MAXN],q[MAXN],work[MAXN];
struct edge {int to,rev;ll f,cap;};
vector<edge> g[MAXN];
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

vector< pair<ll,ll> > pr[N+2];
void fact(ll x,int id){
	for(ll i=2;i*i<=x;i++){
		ll cnt = 0;
		while(x%i==0) cnt++,x/=i;
		if(cnt) pr[id].pb({i,cnt});
	}
	if(x>1) pr[id].pb({x,1});
}

ll A[N+2];
ll init[N+2];

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>A[i];
	for(int i=1;i<=n;i++) fact(A[i],i);
	src = 0;
	nodes++;
	for(int i=1;i<=n;i+=2){
		init[i] = nodes;
		for(int j=0;j<SZ(pr[i]);j++){
			add_edge(src,init[i]+j,pr[i][j].second);
			nodes++;
		}
	}
	for(int i=2;i<=n;i+=2){
		init[i] = nodes;
		for(int j=0;j<SZ(pr[i]);j++){
			//add_edge(src,init[i]+j,pr[i][j].second);
			nodes++;
		}
	}
	dst = nodes++;
	for(int i=2;i<=n;i+=2){
		for(int j=0;j<SZ(pr[i]);j++){
			add_edge(init[i]+j,dst,pr[i][j].second);
		}
	}
	int a,b;
	while(m--){
		cin>>a>>b;
		for(int i=0;i<SZ(pr[a]);i++){
			for(int j=0;j<SZ(pr[b]);j++){
				if(pr[a][i].first == pr[b][j].first){
					if(a&1) add_edge(init[a]+i,init[b]+j,INF);
					else add_edge(init[b]+j,init[a]+i,INF);
					break;
				}
			}
		}
	}
	cout<<max_flow(src,dst)<<'\n';


	return 0;
}

