#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500;

string D[N+2];

ll cmp(string a,string b){
	ll ans = 0;
	for(int i=0;i<4;i++){
		int u = (a[i]-'0'),v = (b[i]-'0');
		if(u>v) swap(u,v);
		ans += min(v-u,10+u-v);
	}
	return ans;
}

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

void solve(){
	int n;cin>>n;
	for(int i=0;i<=n;i++) pa[i]=i;
	for(int i=1;i<=n;i++) cin>>D[i];
	vector<edge> v;
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) v.push_back(edge(i,j,cmp(D[i],D[j])));
	sort(v.begin(),v.end());
	ll ans = cmp(D[0],D[1]);
	for(int i=1;i<=n;i++){
		ans = min(ans,cmp(D[0],D[i]));
	}
	for(int i=0;i<v.size();i++){
		edge &cur = v[i];
		int u = cur.u,v = cur.v;
		if(Find(u)==Find(v)) continue;
		ans += cur.d;
		Union(u,v);
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	D[0] = "0000";
	while(t--) solve();

	return 0;
}

