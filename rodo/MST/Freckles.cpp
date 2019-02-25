#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ld sqr(ld x){
	return x*x;
}

struct Point{
	ld x,y;
	Point(){}
	Point(ld _x,ld _y){
		x = _x;
		y = _y;
	}
	ld dist(Point u){
		return sqrt(sqr(x-u.x) + sqr(y-u.y));
	}
};

struct edge{
	int u,v;
	ld d;
	edge(){}
	edge(int _u,int _v,ld _d){
		u = _u;
		v = _v;
		d = _d;
	}
};

vector<Point> v;
vector<edge> e;

bool operator <(const edge &a,const edge &b){
	return a.d<b.d;
}

int pa[101];

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

void solve(){
	int n;cin>>n;
	for(int i=0;i<n;i++) pa[i] = i;
	v.resize(n);
	for(int i=0;i<n;i++) cin>>v[i].x>>v[i].y;
	e.clear();
	for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) e.push_back(edge(i,j,v[i].dist(v[j])));
	sort(e.begin(),e.end());
	ld ans = 0.0L;
	for(int i=0;i<e.size();i++){
		int u = e[i].u,v = e[i].v;
		if(same(u,v)) continue;
		ans += e[i].d;
		Union(u,v);
	}
	printf("%.2f\n",(double)ans);
}

int main(){
	int t;cin>>t;
	while(t--){
		solve();
		if(t)cout<<'\n';
	}

	return 0;
}

