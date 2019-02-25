#include<bits/stdc++.h>



using namespace std;

#define SZ(x) (ll)x.size()

#define mp make_pair

#define fst first

#define snd second

#define fore(i,a,b) for(ll i=a,to=b;i<to;i++)
#define pb push_back

typedef long long ll;

typedef long double ld;

const double EPS = (1e-7);
const double DINF = (1e20);
struct pt {  // for 3D add z coordinate
	double x,y;
	pt(double x, double y):x(x),y(y){}
	pt(){}
	double norm2(){return *this**this;}
	double norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<EPS&&abs(y-p.y)<EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(double t){return pt(x*t,y*t);}
	pt operator/(double t){return pt(x/t,y/t);}
	double operator*(pt p){return x*p.x+y*p.y;}
//	pt operator^(pt p){ // only for 3D
//		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
	double angle(pt p){ // redefine acos for values out of range
		return acos(*this*p/(norm()*p.norm()));}
	pt unit(){return *this/norm();}
	double operator%(pt p){return x*p.y-y*p.x;}
	// 2D from now on
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<EPS&&y<p.y-EPS);}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>EPS;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(double a){return rot(pt(sin(a),cos(a)));}
};
pt ccw90(1,0);
pt cw90(-1,0);
ll sgn2(double x){return x<0?-1:1;}
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool has(pt r){return dist(r)<EPS;}
	bool seghas(pt r){return has(r)&&(r-p)*(r-(p+pq))-EPS<0;}
//	bool operator /(ln l){return (pq.unit()^l.pq.unit()).norm()<EPS;} // 3D
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<EPS;} // 2D
	bool operator==(ln l){return *this/l&&has(l.p);}
	pt operator^(ln l){ // llersection
		if(*this/l)return pt(DINF,DINF);
		//FOR DOUBLES
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
//		if(!has(r)){return pt(NAN,NAN,NAN);} // check only for 3D
		return r;
	}
	double angle(ln l){return pq.angle(l.pq);}
	ll side(pt r){return has(r)?0:sgn2(pq%(r-p));} // 2D
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
	pt ref(pt r){return proj(r)*2-r;}
	double dist(pt r){return (r-proj(r)).norm();}
//	double dist(ln l){ // only 3D
//		if(*this/l)return dist(l.p);
//		return abs((l.p-p)*(pq^l.pq))/(pq^l.pq).norm();
//	}
};

vector<ln> v;

void read(ln &x){
	string s;cin>>s;
	for(ll i=0;i<SZ(s);i++)if(s[i]==',')s[i]=' ';
	stringstream ss(s);
	pt p1,p2;
	ss>>p1.x>>p1.y>>p2.x>>p2.y;
	x = ln(p1,p2);
}


int main(){

	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

	ll n;cin>>n;
	v.resize(n);
	for(ll i=0;i<n;i++){
		read(v[i]);
	}
	ll ans = 0;

	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<n;j++){
			for(ll k=j+1;k<n;k++){
				pt a = v[i]^v[j];
				pt b = v[i]^v[k];
				pt c = v[j]^v[k];
				if(a==pt(DINF,DINF)) continue;
				if(b==pt(DINF,DINF)) continue;
				if(c==pt(DINF,DINF)) continue;
				vector<ln> cur;
				cur.pb(ln(a,b));
				cur.pb(ln(c,b));
				cur.pb(ln(a,c));
				bool ok=1;
				for(ll m=0;m<n;m++){
					if(m==i || m==j || m==k) continue;
					for(ll q=0;q<3;q++){
						pt x = v[m]^cur[q];
						if(x==pt(DINF,DINF))continue;
						if(cur[q].seghas(x)) ok=0;
					}
				}
				if(ok)ans++;
			}
		}
	}
	cout<<ans<<endl;


	return 0;

}
