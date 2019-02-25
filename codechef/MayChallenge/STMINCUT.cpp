#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = (1000);
const ll INF = (1e18);
int n;
ll A[N+2][N+2];
ll B[N+2][N+2];
ll pa[N+2];

int Find(int x){
	return (x==pa[x]?x:pa[x]=Find(pa[x]));
}

void Union(int x,int y){
	int px = Find(x);
	int py = Find(y);
	pa[px] = pa[py];
}

bool cmp(pair< ll,pair<int,int> > p ,pair< ll,pair<int,int> > q){
	return p.first < q.first;
}

vector<int> G[N+2];
bool vis[N+2];

void dfs(int root,int x,ll mini){
	//cout<<root<<" "<<x<<" "<<mini<<endl;
	B[root][x] = B[x][root] = mini;
	vis[x] = 1;
	for(int i=0;i<G[x].size();i++){
		int p = G[x][i];
		if(vis[p]) continue;
		dfs(root,p,min(mini,B[p][x]));
	}
}

void solve(){
	for(int i=1;i<=N;i++) pa[i] = i;
	for(int i=1;i<=N;i++) G[i].clear();
	cin>>n;
	memset(A,0,sizeof A);
	memset(B,0,sizeof B);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cin>>A[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) B[i][j] = A[i][j];
	}
	//for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cout<<B[i][j]<<(char)(j==n?10:32);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ll p = max(B[i][j],B[j][i]);
			B[i][j] = p;
			B[j][i] = p;
		}
	}
	//for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cout<<B[i][j]<<(char)(j==n?10:32);
	vector< pair< ll,pair<int,int> > > v;
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(B[i][j]) v.push_back(make_pair(B[i][j],make_pair(i,j)));
	sort(v.rbegin(),v.rend(),cmp);
	for(int i=0;i<v.size();i++){
		int p = v[i].second.first, q =v[i].second.second;
		if(Find(p)==Find(q)) continue;
		G[p].push_back(q);
		G[q].push_back(p);
		Union(p,q);
	}
	/*for(int i=1;i<=n;i++){
		for(int j=0;j<G[i].size();j++){
			int p = G[i][j];
			cout<<i<<" "<<p<<" "<<B[i][p]<<endl;
		}
	}*/
	//cout<<"-----------------\n";
	for(int i=1;i<=n;i++){//calculo el mincut entre i y todos los demas
		//cout<<"dfs para "<<i<<endl;
		memset(vis,0,sizeof vis);
		dfs(i,i,INF);
	}
	ll ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			ans += (B[i][j] - A[i][j]);
		}
	}
	//for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cout<<B[i][j]<<(char)(j==n?10:32);
	cout<<ans<<'\n';
}

int main(){
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

