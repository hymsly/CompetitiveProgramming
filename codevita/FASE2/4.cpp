#include<bits/stdc++.h>

using namespace std;
#define SZ(x) (int)x.size()
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;i++)
typedef long long ll;
typedef long double ld;
const ll INF = (1e9);
const ld DINF = (1e200);
const ld EPS = (1e-9);

struct pt {  // for 3D add z coordinate
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	ld norm2(){return *this**this;}
	ld norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<EPS&&abs(y-p.y)<EPS;}
	bool operator!=(pt p){return abs(x-p.x)>=EPS&&abs(y-p.y)>=EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(double t){return pt(x*t,y*t);}
	pt operator/(double t){return pt(x/t,y/t);}
	double operator*(pt p){return x*p.x+y*p.y;}
	double angle(pt p){ // redefine acos for values out of range
		return acos(*this*p/(norm()*p.norm()));}
	pt unit(){return *this/norm();}
	double operator%(pt p){return x*p.y-y*p.x;}
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<EPS&&y<p.y-EPS);}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>EPS;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(double a){return rot(pt(sin(a),cos(a)));}
};
pt ccw90(1,0);
pt cw90(-1,0);

int sgn2(double x){return x<0?-1:1;}
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool has(pt r){return dist(r)<EPS;}
	bool seghas(pt r){return has(r)&&(r-p)*(r-(p+pq))-EPS<0;}
//	bool operator /(ln l){return (pq.unit()^l.pq.unit()).norm()<EPS;} // 3D
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<EPS;} // 2D
	bool operator==(ln l){return *this/l&&has(l.p);}
	pt operator^(ln l){ // intersection
		if(*this/l)return pt(DINF,DINF);
		//FOR DOUBLES
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
		if(!l.seghas(r)) return pt(DINF,DINF);
//		if(!has(r)){return pt(NAN,NAN,NAN);} // check only for 3D
		return r;
	}
	double angle(ln l){return pq.angle(l.pq);}
	int side(pt r){return has(r)?0:sgn2(pq%(r-p));} // 2D
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
	pt ref(pt r){return proj(r)*2-r;}
	double dist(pt r){return (r-proj(r)).norm();}
};

struct triangle{
	ll p,h;
	triangle(){}
	triangle(ll _p,ll _h){
		p = _p;h = _h;
	}
	ll izq(){
		return p-h;
	}
	ll der(){
		return p+h;
	}
};

vector<triangle> v;

bool cmp(triangle a,triangle b){
	ll pa = a.izq();
	ll pb = b.izq();
	if(pa!=pb) return pa<pb;
	return a.h>b.h;
}

int n;

ld area(ld x){
	return x*x;
}

ld inter(triangle x,triangle y,bool &ok){
	if(x.der()>=y.der()){
		return area(y.h);
	}
	ok=1;
	if(x.der()<=y.izq())return 0.0L;
	ln rect1 = ln(pt(x.der(),0.0),pt(x.p,x.h));
	ln rect2 = ln(pt(y.izq(),0.0),pt(y.p,y.h));
	pt point = rect1^rect2;
	return area(point.y);
}

bool equal(double i, double j){
    return (abs(i - j) < EPS);
}

void printDecimal(double d){
	d = round(d*100)/100;
	if(equal(d,floor(d)))printf("%.1f\n", d);
	else if(equal(d*10,floor(d*10)))printf("%.1f\n", d);
    else printf("%.2f\n", d);
}

void solve(){
	cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++) cin>>v[i].p>>v[i].h;
	sort(v.begin(),v.end(),cmp);
	ld ans = 0.0;
	ll lastIzq = -INF;
	ll lastHeight = 0;
	for(int i=0;i<n;i++){
		//cout<<v[i].p<<" "<<v[i].h<<endl;
		if(lastHeight==0){
			lastIzq = v[i].izq();
			lastHeight = v[i].h;
			ans += area((ld)v[i].h);
			continue;
		}
		if(lastIzq==v[i].izq())continue;
		bool ok = 0;
		ans += area((ld)v[i].h);
		ans -= inter(triangle(lastIzq+lastHeight,lastHeight),v[i],ok);
		if(ok){
			lastIzq = v[i].izq();
			lastHeight = v[i].h;
		}
	}
	printDecimal((double)ans);
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--) solve();

	return 0;
}
