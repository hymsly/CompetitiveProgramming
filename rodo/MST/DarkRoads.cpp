#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (2e5);

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

vector<edge> v;

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
int n,m;
void solve(){
	for(int i=0;i<n;i++) pa[i] = i;
	v.resize(m);
	ll ans = 0LL;
	for(int i=0;i<m;i++) cin>>v[i].u>>v[i].v>>v[i].d,ans+=v[i].d;
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		edge &cur = v[i];
		int u = cur.u,v = cur.v;
		if(same(u,v)) continue;
		ans -= cur.d;
		Union(u,v);
	}
	cout<<ans<<'\n';
}

int main(){
	while(cin>>n>>m){
		if(n==0 && m==0) break;
		solve();
	}

	return 0;
}

