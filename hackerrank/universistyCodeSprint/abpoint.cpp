#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (3e5);

int n,m;
ll t1,t2;
bool vis[N+2];
vector<int> G[N+2];

ll mini[N+2];
ll maxi[N+2];
int ID[N+2];

void dfs(int x,int id){
	ID[x] = id;
	vis[x] = 1;
	ll len = G[x].size();
	mini[id] = min(mini[id],len);
	maxi[id] = max(maxi[id],len);
	for(int i=0;i<len;i++){
		if(vis[G[x][i]])continue;
		dfs(G[x][i],id);
	}
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>t1>>t2;
	fill(mini+1,mini+n+1,N+1);
	int a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int id = 1;
	for(int i=1;i<=n;i++){
		if(!vis[i]) dfs(i,id++);
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		ll len = G[i].size();
		ll minimo = mini[ID[i]];
		ll maximo = maxi[ID[i]];
		if(len > t1*minimo && len < t2*maximo) ans++;
	}
	cout<<ans<<'\n';

	return 0;
}

