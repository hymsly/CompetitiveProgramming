#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define fst first
#define snd second
using namespace std;
typedef long long ll;
typedef long double ld;
const ld INF = (1e7);
const ld EPS = (1e-6);
const int MAXN = (50);
int n,m;
vector<pair<int,ld> > g[MAXN+2]; // u->[(v,cost)]
ld dist[MAXN+2];
bool bford(int src,ld search){ // O(nm)
	fill(dist,dist+n,INF);dist[src]=0;
	fore(_,0,n-1)fore(x,0,n)if(abs(dist[x]-INF)>EPS)for(auto t:g[x]){
		dist[t.fst]=min(dist[t.fst],dist[x]+t.snd-search);
	}
	fore(x,0,n)if(abs(dist[x]-INF)>EPS)for(auto t:g[x]){
		if(dist[t.fst]>dist[x]+t.snd-search){
			return true;
		}
	}
	return false;
}

int caso = 0;

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<=n;i++) g[i].clear();
		int a,b;ll c;
		for(int i=0;i<m;i++){
			cin>>a>>b>>c;
			g[a].push_back(make_pair(b,(ld)c));
		}
		for(int i=1;i<=n;i++) g[0].push_back(make_pair(i,0.0L));
		n++;
		ld lo=0,hi=INF;
		bool ok=0;
		while((hi-lo)>EPS){
			ld mi = (hi+lo)/2.0L;
			bool negCiclo=bford(0,mi);
			if(negCiclo) ok=1,hi=mi;
			else lo=mi;
		}
		if(!ok) printf("Case #%d: No cycle found.\n",++caso);
		else printf("Case #%d: %.2lf\n",++caso,(double)hi);
	}

	return 0;
}

