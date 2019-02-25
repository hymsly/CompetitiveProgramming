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
int n,m,k;
ll w;
char M[11][11][1001];
bool used[1001];

ll cmp(int x,int y){
	ll ans = 0;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) ans+=(M[i][j][x]!=M[i][j][y]);
	if(x*y==0) return ans;
	return ans*w;
}

void solve(){
	cin>>n>>m>>k>>w;
	for(int i=0;i<=k;i++) pa[i] = i;
	for(int a=1;a<=k;a++) for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>M[i][j][a];
	for(int i=0;i<k;i++) for(int j=i+1;j<=k;j++) v.push_back(edge(i,j,cmp(i,j)));
	ll ans = 0LL;
	for(int i=0;i<m;i++) cin>>v[i].u>>v[i].v>>v[i].d;
	sort(v.begin(),v.end());
	vector< pair<int,int> > mst;
	for(int i=0;i<v.size();i++){
		edge &cur = v[i];
		int u = cur.u,v = cur.v;
		if(same(u,v)) continue;
		ans += cur.d;
		Union(u,v);
		mst.push_back(make_pair(u,v));
	}
	used[0] = 1;
	vector< pair<int,int> > res;
	while(res.size()<k){
		for(int i=0;i<mst.size();i++){
			if(used[mst[i].first] && used[mst[i].second]) continue;
			if(used[mst[i].first]){
				res.push_back(make_pair(mst[i].second,mst[i].first));
				used[mst[i].second]=1;
			}else if(used[mst[i].second]){
				res.push_back(make_pair(mst[i].first,mst[i].second));
				used[mst[i].first]=1;
			}
		}
	}
	cout<<ans<<'\n';
	for(int i=0;i<res.size();i++) cout<<res[i].first<<" "<<res[i].second<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	solve();

	return 0;
}

