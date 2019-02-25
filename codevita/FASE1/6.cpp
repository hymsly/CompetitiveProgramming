#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define SZ(x)(int)x.size()
#define fore(i,a,b) for(int i=a,to=b;i<to;i++)
typedef long double ld;
typedef long long ll;
const ld EPS = (1e-9);
const ld DINF = (1e200);
int n;
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
	ll ax,bx,cx,cy;
	ll den;
	triangle(){}
};

bool operator <(const triangle &a,const triangle &b){
	return a.ax<b.bx;
}

vector<triangle> v;

set<pt> inter;

map<pt,ll> suma;
vector<pt> puntos;
int sgn(double x){return x<-EPS?-1:x>EPS;}
struct pol {
	int n;vector<pt> p;
	pol(){}
	pol(vector<pt> _p){p=_p;n=p.size();}
	ld area(){
		ld r=0.0L;
		fore(i,0,n)r+=p[i]%p[(i+1)%n];
		return abs(r)/2; // negative if CW, positive if CCW
	}
	bool has(pt q){ // O(n)
		fore(i,0,n)if(ln(p[i],p[(i+1)%n]).seghas(q))return true;
		int cnt=0;
		fore(i,0,n){
			int j=(i+1)%n;
			int k=sgn((q-p[j])%(p[i]-p[j]));
			int u=sgn(p[i].y-q.y),v=sgn(p[j].y-q.y);
			if(k>0&&u<0&&v>=0)cnt++;
			if(k<0&&v<0&&u>=0)cnt--;
		}
		return cnt!=0;
	}
};

bool dentro(triangle x,pt y){
	vector<pt> poligon;
	poligon.pb(pt(x.ax,0));
	poligon.pb(pt(x.bx,0));
	poligon.pb(pt(x.cx,x.cy));
	pol p(poligon);
	return p.has(y);
}
void acumular(){
	for(int i=0;i<SZ(puntos);i++){
		for(int j=0;j<n;j++){
			if(dentro(v[j],puntos[i])) suma[puntos[i]]+=v[j].den;
		}
	}
}

vector<pt> getPoint(ll densidad,ll infx,ll supx){
	vector<pt> ans;
	for(int i=0;i<SZ(puntos);i++) if(suma[puntos[i]]==densidad && puntos[i].x>=infx-EPS && puntos[i].x<=supx+EPS) ans.pb(puntos[i]);
	return ans;
}

vector<pt> chull(vector<pt> p){
	if(SZ(p)<3)return p;
	vector<pt> r;
	sort(p.begin(),p.end()); // first x, then y
	fore(i,0,p.size()){ // lower hull
		while(r.size()>=2&&r.back().left(r[r.size()-2],p[i]))r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back();
	int k=r.size();
	for(int i=p.size()-1;i>=0;--i){ // upper hull
		while(r.size()>=k+2&&r.back().left(r[r.size()-2],p[i]))r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back();
	return r;
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++)cin>>v[i].ax>>v[i].bx>>v[i].cx>>v[i].cy>>v[i].den;
	sort(v.begin(),v.end());
	set<ll> S;
	for(int i=0;i<n;i++) S.insert(2*v[i].ax),S.insert(2*v[i].bx);
	for(int i=0;i<n;i++){
		inter.insert(pt(v[i].ax,0));
		inter.insert(pt(v[i].bx,0));
		inter.insert(pt(v[i].cx,v[i].cy));
		for(int j=i+1;j<n;j++){
			ln ln1 = ln(pt(v[i].ax,0),pt(v[i].cx,v[i].cy));
			ln ln2 = ln(pt(v[i].bx,0),pt(v[i].cx,v[i].cy));
			ln ln3 = ln(pt(v[j].ax,0),pt(v[j].cx,v[j].cy));
			ln ln4 = ln(pt(v[j].bx,0),pt(v[j].cx,v[j].cy));
			if((ln1^ln3)!=pt(DINF,DINF)) inter.insert(ln1^ln3);
			if((ln1^ln4)!=pt(DINF,DINF)) inter.insert(ln1^ln4);
			if((ln2^ln3)!=pt(DINF,DINF)) inter.insert(ln2^ln3);
			if((ln2^ln4)!=pt(DINF,DINF)) inter.insert(ln2^ln4);
			
		}
	}
	set<pt> :: iterator it;
	for(it=inter.begin();it!=inter.end();it++){
		puntos.pb((*it));
	}
	acumular();
	vector<ll> bases;
	set<ll> :: iterator it2;
	for(it2=S.begin();it2!=S.end();it2++) bases.pb((*it2));
	ll value = 0;
	ld area = 0.0L;
	for(int i=1;i<SZ(bases);i++){
		ll p = (bases[i]+bases[i-1])/2;
		ll cur = 0;
		for(int j=0;j<n;j++){
			if(p>=v[j].ax*2 && p<=v[j].bx*2) cur+=v[j].den;
		}
		//cout<<(ld)p/2.0L<<" "<<cur<<endl;
		if(cur>value){//esta es la respuesta
			value = cur;
			vector<pt> polygon = chull(getPoint(value,bases[i-1]/2,bases[i]/2));
			pol p(polygon);
			area = p.area();
		}
	}
	printf("%.0f\n",(double)round(area));

	return 0;
}

