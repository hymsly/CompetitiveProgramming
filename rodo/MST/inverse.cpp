#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (2000);
const ll INF = (1e15);

ll A[N+2][N+2];
ll B[N+2][N+2];
struct edge{
	int u,v;
	ll d;
	edge(){}
	edge(int _u,int _v,ll _d){
		u = _u;
		v = _v;
		d = _d;
	}
};

bool operator <(const edge &a,const edge &b){
	return a.d<b.d;
}

int pa[N+2];

int Find(int x){
	return (pa[x]==x?x:pa[x]=Find(pa[x]));
}
void Union(int x,int y){
	int xx = Find(x),yy = Find(y);
	pa[xx] = yy;
}
bool same(int x,int y){
	return Find(x)==Find(y);
}
vector< pair<int,ll> > G[N+2];

bool vis[N+2];

void dfs(int padre,int x,ll d){
	vis[x] = 1;
	B[padre][x] = min(B[padre][x],d);
	B[x][padre] = min(B[x][padre],d);
	for(int i=0;i<G[x].size();i++){
		int u = G[x][i].first;
		ll w = G[x][i].second;
		if(vis[u]) continue;
		dfs(padre,u,d+w);
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n;cin>>n;
	for(int i=1;i<=n;i++) pa[i]=i;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>A[i][j];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) B[i][j] = INF;
	for(int i=1;i<=n;i++) B[i][i] = 0;
	bool ok=1;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		if(A[i][i]!=0) ok=0;
		if(A[i][j] != A[j][i]) ok=0;
		if(i!=j && (A[i][j]==0 || A[j][i]==0)) ok=0;
	}
	if(!ok){
		cout<<"NO\n";
		return 0;
	}
	vector<edge> v;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++) v.push_back(edge(i,j,A[i][j]));
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		edge &cur = v[i];
		int u = cur.u,v = cur.v;
		ll d = cur.d;
		if(same(u,v)) continue;
		G[u].push_back(make_pair(v,d));
		G[v].push_back(make_pair(u,d));
		Union(u,v);
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		dfs(i,i,0);
	}
	
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(A[i][j]!=B[i][j]) ok=0;
	if(!ok) cout<<"NO\n";
	else cout<<"YES\n";


	return 0;
}

