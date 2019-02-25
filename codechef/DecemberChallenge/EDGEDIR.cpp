#include <bits/stdc++.h>
#define pb push_back
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n,m;
vector<int> g[100005];
int vis[100005];
vector<vector<int> > r;
map< pair<int,int> ,int> EDGE;
int value[100005];

bool dfs(int x, int f){
	vis[x]=1;
	int k=-1;
	for(int y:g[x]){
		if(y==f)continue;
		if(vis[y]>0||!vis[y]&&!dfs(y,x)){
			if(k<0)k=y;
			else r.pb({k,x,y}),k=-1;
		}
	}
	vis[x]=-1;
	if(k>=0){
		r.pb({k,x,f});
		return true;
	}
	return false;
}

void solve(){
	scanf("%d%d",&n,&m);
	memset(vis,0,sizeof vis);
	fore(i,0,m)value[i]=1;
	r.clear();
	EDGE.clear();
	for(int i=0;i<n;i++)g[i].clear();
	fore(i,0,m){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);
		EDGE[{x,y}] = i;
	}
	fore(i,0,n){
		if(!vis[i]&&dfs(i,-1)){
			printf("-1\n");
			return;
		}
	}
	for(auto v:r){
		if(EDGE.count({v[0],v[1]}))value[EDGE[{v[0],v[1]}]]=0;
		if(EDGE.count({v[2],v[1]}))value[EDGE[{v[2],v[1]}]]=0; 
	}
	fore(i,0,m)cout<<value[i]<<(char)(i+1==m?10:32);
}

int main(){
	int t;cin>>t;
	while(t--) solve();
	return 0;
}
