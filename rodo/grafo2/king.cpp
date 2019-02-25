#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define fst first
#define snd second
using namespace std;
typedef long long ll;
const ll INF = (1e18);
const int MAXN = 100;
int n,m;
vector<pair<int,ll> > g[MAXN+5]; // u->[(v,cost)]
ll dist[MAXN+5];
bool bford(int src){ // O(nm)
	fill(dist,dist+n,INF);dist[src]=0;
	fore(_,0,n-1)fore(x,0,n)if(dist[x]!=INF)for(auto t:g[x]){
		dist[t.fst]=min(dist[t.fst],dist[x]+t.snd);
	}
	fore(x,0,n)if(dist[x]!=INF)for(auto t:g[x]){
		if(dist[t.fst]>dist[x]+t.snd){
			return true;
		}
	}
	return false;
}

void clear(){
	for(int i=0;i<=n+1;i++) g[i].clear();
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	while(cin>>n){
		if(n==0) break;
		clear();
		cin>>m;
		int a,b,c;string st;
		for(int i=0;i<m;i++){
			cin>>a>>b>>st>>c;
			b+=a;
			a--;
			if(st=="gt") g[b].push_back({a,-c-1});
			else g[a].push_back({b,c-1});
		}
		for(int i=0;i<=n;i++){
			g[n+1].push_back({i,0});
		}
		n+=2;
		if(bford(n-1)){
			cout<<"successful conspiracy\n";
		}else{
			cout<<"lamentable kingdom\n";
		}
	}

	return 0;
}

