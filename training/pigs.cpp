#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SZ(a) (int)a.size()
#define pb push_back
#define fore(i,a,b) for(int i=a,to=b;i<to;i++)
#define fi first
#define snd second
const int N = (100);
const int M = (1000);
const int MAXN = (N+M+2);
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

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n,m;cin>>n>>m;
	Dinic dinic(n+m+2,0,n+m+1);
	ll num;
	for(int i=1;i<=m;i++){
		cin>>num;
		dinic.add_edge(n+i,n+m+1,num);
	}
	for(int i=1;i<=n;i++){
		int a,b;
		cin>>a;
		while(a--){
			cin>>num;
			dinic.add_edge(i,num+n,INF);
		}
		cin>>b;
		dinic.add_edge(0,i,b);
	}
	/*for(int i=0;i<n+m+2;i++){
		cout<<i<<"---\n";
		for(int j=0;j<SZ(dinic.g[i]);j++) cout<<dinic.g[i][j].to<<" "<<dinic.g[i][j].cap<<'\n';
	}*/
	cout<<dinic.max_flow()<<'\n';

	return 0;
}

