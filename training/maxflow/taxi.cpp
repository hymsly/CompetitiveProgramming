#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fore(i,a,b) for(int i=a,to=b;i<to;i++)
#define pb push_back
#define SZ(x) (int)x.size()
const int N = 800;
const ll INF = (1e12);
struct edge{int to,rev;ll f,cap;};
struct Dinic{
	int nodes,src,dst;
	int dist[N+2],q[N+2],work[N+2];
	vector<edge> g[N+2];
	Dinic(){}
	Dinic(int _nodes,int _src,int _dst){
		nodes = _nodes;src = _src;dst = _dst;
	}
	void add_edge(int s,int t,ll cap){
		g[s].pb((edge){t,SZ(g[t]),0,cap});
		g[t].pb((edge){s,SZ(g[s])-1,0,cap});
	}
	bool dinic_bfs(){
		fill(dist,dist+nodes,-1);dist[src]=0;
		int qt=0;q[qt++]=src;
		for(int qh=0;qh<qt;qh++){
			int u = q[qh];
			fore(i,0,SZ(g[u])){
				edge &e=g[u][i];int v=e.to;
				if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
			}
		}
		return dist[dst]>=0;
	}
	ll dinic_dfs(int u,ll f){
		if(u==dst) return f;
		for(int &i=work[u];i<SZ(g[u]);i++){
			edge &e=g[u][i];
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
		ll result =0;
		while(dinic_bfs()){
			fill(work,work+nodes,0);
			while(ll delta=dinic_dfs(src,INF))result+=delta;
		}
		return result;
	}
};

int n,m;ll s,tim;

bool dist(pair<int,int> p1,pair<int,int> p2){
	int len = abs(p1.first-p2.first)+abs(p2.second-p1.second);
	ll dist = (ll)len*200;
	if(dist<=s*tim)return true;
	return false;
}

void solve(){
	cin>>n>>m>>s>>tim;
	vector<pair<int,int> > person(n),taxi(m);
	for(int i=0;i<n;i++) cin>>person[i].first>>person[i].second;
	for(int i=0;i<m;i++) cin>>taxi[i].first>>taxi[i].second;
	Dinic dinic(n+m+2,0,n+m+1);
	for(int i=0;i<n;i++)dinic.add_edge(0,i+1,1);
	for(int i=0;i<m;i++)dinic.add_edge(n+i+1,n+m+1,1);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(dist(person[i],person[j])) dinic.add_edge(i+1,n+1+j,1);
		}
	}
	cout<<dinic.max_flow()<<'\n';
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

