#include<bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
#define pb push_back
#define fore(i,a,b) for(int i=a,to=b;i<to;i++)
typedef long long ll;
typedef long double ld;
const ld EPS = (1e-9);
const ld INF = (1e20);
const int MAXN = (800+5);

int n;
vector<pair<int,ld> > g[MAXN]; // u->[(v,cost)]
ld dist[MAXN];
bool bford(int src){ // O(nm)
	fill(dist,dist+n,INF);dist[src]=0.0L;
	fore(_,0,n-1)fore(x,0,n)if(abs(dist[x]-INF)>EPS)for(auto t:g[x]){
		dist[t.fst]=min(dist[t.fst],dist[x]+t.snd);
	}
	fore(x,0,n)if(abs(dist[x]-INF)>EPS)for(auto t:g[x]){
		ld now = dist[t.fst];
		ld after = dist[x]+t.snd;
		if(abs(after-now)<EPS) continue;
		if(after<now) return true;
	}
	return false;
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int m;
	cin>>n>>m;
	int a,b;
	ld c;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		g[a].pb({b,-(ld)log(c)});
	}
	for(int i=1;i<=n;i++) g[0].pb({i,0.0L});
	n++;
	if(bford(0)) cout<<"inadmissible\n";
	else cout<<"admissible\n";

	return 0;
}

