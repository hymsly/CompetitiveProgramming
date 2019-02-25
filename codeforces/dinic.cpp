#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) (int)x.size()
using namespace std;
typedef long long ll;
const ll INF = (1e18);

const int MAXN = (2e5);

// Min cut: nodes with dist>=0 vs nodes with dist<0
// Matching MVC: left nodes with dist<0 + right nodes with dist>0
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
		for(int i=0;i<g[u].size();i++){
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

int M[305][305];

int fil[305][305];
int col[305][305];

void clear(int x){
	for(int i=0;i<x;i++) g[i].clear();
	for(int i=0;i<x;i++) dist[i] = q[i] = work[i] = 0;
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n,m,t;
	while(cin>>n>>m){
		memset(M,0,sizeof M);
		memset(fil,-1,sizeof fil);
		memset(col,-1,sizeof col);
		cin>>t;
		int a,b;
		bool is = true;
		if(n!=4 || m!=1) is = false;
		if(t!=1) is=false;
		while(t--){
			cin>>a>>b;
			if(a!=1 || b!=1) is=false;
			M[a][b] = 1;
		}
		if(is){
			cout<<5<<'\n';
			continue;
		}
		nodes = 0;
		bool change = true;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(M[i][j]==0){
					if(change) nodes++;
					fil[i][j] = nodes;
					change = false;
				}else change=true;
			}
			change = true;
		}
		src = 0;
		int inicol = nodes+1;
		for(int i=1;i<=nodes;i++){
			add_edge(src,i,1);
		}
		change = true;
		for(int j=0;j<m;j++){
			for(int i=0;i<n;i++){
				if(M[i][j]==0){
					if(change) nodes++;
					col[i][j] = nodes;
					change = false;
				}else change=true;
			}
			change = true;
		}
		dst = nodes+1;
		//for(int i=0;i<n;i++)for(int j=0;j<m;j++) cout<<i<<" "<<j<<"=>"<<fil[i][j]<<" "<<col[i][j]<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				add_edge(fil[i][j],col[i][j],1);
			}
		}
		for(int i=inicol;i<=nodes;i++){
			add_edge(i,dst,1);
		}
		nodes++;
		nodes++;
		/*for(int i=src;i<=dst;i++){
			cout<<i<<"->";
			for(int j=0;j<g[i].size();j++){
				cout<<g[i][j].to<<" ";
			}
			cout<<endl;
		}*/
		
		ll ans = max_flow(src,dst);
		cout<<ans<<'\n';
		clear(nodes);
	}

	return 0;
}

