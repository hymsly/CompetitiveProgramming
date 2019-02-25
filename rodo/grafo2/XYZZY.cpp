#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define fst first
#define snd second
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = (1e9);
const int MAXN = (100);
int n,m;
vector<int> g[MAXN+2]; // u->[(v,cost)]
ll dist[MAXN+2];
bool vis[MAXN+2];

bool dfs(int x){
	vis[x] = 1;
	bool ans = false;
	for(auto t:g[x]){
		if(vis[t]) continue;
		if(t==n-1) return true;
		ans |= dfs(t);
	}
	return ans;
}
ll d[MAXN];

bool bford(int src){ // O(nm)
	fill(dist,dist+n,INF);dist[src]=-100;
	fore(_,0,n-1)fore(x,0,n)if(dist[x]!=INF)for(auto t:g[x]){
		if(dist[x]+d[t]<0) dist[t]=min(dist[t],dist[x]+d[t]);
	}
	if(dist[n-1]<=0) return true;
	fore(x,0,n)if(dist[x]!=INF)for(auto t:g[x]){
		if(dist[t]>dist[x]+d[t] && dist[x]+d[t]<0){
			memset(vis,0,sizeof vis);
			if(dfs(x)) return true;
			//return true;
		}
	}
	return false;
}


int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	while(cin>>n){
		if(n==-1) break;
		for(int i=0;i<n;i++) g[i].clear();
		int a,b,c;
		vector< pair<int,int> > v;
		for(int i=0;i<n;i++){
			cin>>a>>b;
			d[i] = -a;
			while(b--){
				cin>>c;
				c--;
				v.push_back({i,c});
			}
		}
		for(int i=0;i<v.size();i++){
			g[v[i].fst].push_back(v[i].snd);
		}
		if(bford(0)) cout<<"winnable\n";
		else cout<<"hopeless\n";
	}

	return 0;
}

