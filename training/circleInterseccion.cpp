#include<bits/stdc++.h>
using namespace std;
#define Vector Point
#define pb push_back
typedef long long ll;
typedef long double ld;
const ld EPS = (1e-9);

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
	ld mod(){return sqrt(sqr(x)+sqr(y));}
	Point ort(){return Point(-y,x);}
	Point unit(){
		ld k = mod();return Point(x/k,y/k);
	}
};
Point operator +(const Point &a,const Point &b){
	return Point(a.x+b.x,a.y+b.y);
}
Point operator -(const Point &a,const Point &b){
	return Point(a.x-b.x,a.y-b.y);
}
Point operator *(const Point &a,ld k){
	return Point(a.x*k,a.y*k);
}
ld dist(Point a,Point b){
	return sqrt(sqr(a.x-b.x) + sqr(a.y-b.y));
}
struct Circle{
	Point c;
	ld r;
	Cirle(){}
	bool in(Point x){
		ld d = dist(x,c);
		return (d<=r+EPS);
	}
	void show(){
		c.show();
		cout<<r<<endl;
	}
};


vector<Point> circleCircleIntersection(Circle x,Circle y){
	vector<Point> ans;
	ld d = dist(x.c,y.c);
	if(d<EPS) return ans;
	if(d>x.r+y.r || d<abs(x.r-y.r)) return ans;
	else{
		ld a = (sqr(x.r)-sqr(y.r)+d*d)/(2.0*d);
		ld b = d-a;
		ld c = sqrt(abs(sqr(x.r)-sqr(a)));
		Vector V = (y.c-x.c).unit();
		Point H = x.c + V*a;
		ans.pb(H+V.ort()*c);
		if(c>EPS) ans.pb(H-V.ort()*c);
		return ans;
	}
}

bool cmp(pair<Circle,ll> x,pair<Circle,ll> y){
	return x.second>y.second;
}

void solve(){
	int n,m;cin>>n>>m;
	vector< pair<Circle,ll> > v(n);
	for(int i=0;i<n;i++) cin>>v[i].first.c.x>>v[i].first.c.y>>v[i].first.r>>v[i].second;
	sort(v.begin(),v.end(),cmp);
	vector<Point> inter;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			vector<Point> cur = circleCircleIntersection(v[i].first,v[j].first);
			for(int k=0;k<cur.size();k++) inter.pb(cur[k]);
		}
		inter.pb(v[i].first.c);
	}
	ll ans = 0;
	for(int i=0;i<inter.size();i++){
		ll val = 0,k=0;
		for(int j=0;j<n&&k<m;j++){
			if(v[j].first.in(inter[i])){
				val+=v[j].second;
				k++;
			}
		}
		ans =max(ans,val);
	}
	cout<<ans<<'\n';
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

