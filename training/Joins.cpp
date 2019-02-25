#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef long double ld;
const int N = (100);
const ld INF = (1e9);
const ld EPS = (1e-6);


pair<ll,ll> A[N+2];
int n,k;
vector<int> pa;
int Find(int x){
	return (pa[x]==x?x:pa[x]=Find(pa[x]));
}
void Union(int x,int y){
	int xx = Find(x),yy=Find(y);
	pa[xx] = yy;
}

ll sqr(ll x){
	return x*x;
}

ld dist(pair<ll,ll> a,pair<ll,ll> b){
	ll val = sqr(a.fi-b.fi)+sqr(a.se-b.se);
	return (ld)sqrt(val);
}

ld mst(vector< pair<ll,ll> > &v){
	int len = v.size();
	pa.resize(len);
	for(int i=0;i<len;i++) pa[i]=i;
	vector< pair<ld,pair<int,int> > > edges;
	for(int i=0;i<len;i++){
		for(int j=i+1;j<len;j++){
			edges.push_back(mp(dist(v[i],v[j]),mp(i,j)));
		}
	}
	sort(edges.begin(),edges.end());
	ld ans = 0.0L;
	for(int i=0;i<edges.size();i++){
		int p = edges[i].se.fi,q = edges[i].se.se;
		if(Find(p)==Find(q)) continue;
		ans+=edges[i].fi;
		Union(p,q);
	}
	for(int i=1;i<=n;i++){
		ld mini = INF;
		for(int j=0;j<v.size();j++){
			mini = min(mini,dist(A[i],v[j]));
		}
		ans += mini;
	}
	return ans;
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>A[i].fi>>A[i].se;
	for(int mask=1;mask<(1<<k);mask++){
		vector< vector<int> > RES;
		for(int j=0;j<k;j++){
			if(mask & (1<<j)){//ubicar el punto mas cercano
				vector<int> points;ld mini = INF;
				for(int i=k+1;i<=n;i++){
					ld cur = dist(A[j],A[i]);
					if(abs(cur-mini)<EPS) points.pb(i);
					else{
						points.clear();
						points.pb(i);
						mini = cur;
					}
				}
				RES.pb(points);
			}
		}
		for(int i=0;i<RES.size();i++){
			
		}
	}

	return 0;
}

