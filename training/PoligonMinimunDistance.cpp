#include<bits/stdc++.h>

using namespace std;
#define Vector pt
#define pb push_back
typedef long long ll;
typedef long double ld;
const ld DINF = (1e200);
const ld EPS  = (1e-9);

struct pt {  // for 3D add z coordinate
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	ld norm2(){return *this**this;}
	ld norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<EPS&&abs(y-p.y)<EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(double t){return pt(x*t,y*t);}
	pt operator/(double t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
	ld angle(pt p){ // redefine acos for values out of range
		return acos(*this*p/(norm()*p.norm()));}
	pt unit(){return *this/norm();}
	ld operator%(pt p){return x*p.y-y*p.x;}
	// 2D from now on
};

struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool has(pt r){return dist(r)<EPS;}
	bool seghas(pt r){return has(r)&&(r-p)*(r-(p+pq))-EPS<0;}
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<EPS;} // 2D
	bool operator==(ln l){return *this/l&&has(l.p);}
	pt operator^(ln l){ // intersection
		if(*this/l)return pt(DINF,DINF);
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
		return r;
	}
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
	pt ref(pt r){
		if(seghas(r)) return r;
		return proj(r)*2-r;
	}
	double dist(pt r){return (r-proj(r)).norm();}
};

int caso;
void solve(){
	int n;
	cin>>n;
	vector<pt> v;
	vector<ln> w;
	pt a,b;
	for(int i=0;i<n;i++) cin>>a.x>>a.y,v.pb(a);
	for(int i=0;i<n;i++) w.pb(ln(v[i],v[(i+1)%n]));
	int q;cin>>q;
	printf("Case %d:\n",++caso);
	while(q--){
		cin>>a.x>>a.y>>b.x>>b.y;
		ld dist=DINF;pt ans;
		for(int i=0;i<n;i++){
			pt op = w[i].ref(b);
			ld curDist = (op-a).norm();
			if(a==op){
				dist = curDist;ans = a;continue;
			}
			if(w[i]/(ln(a,op))) continue;
			pt curPoint = w[i]^ln(a,op);
			if(curDist<=dist+EPS){
				dist = curDist;
				ans = curPoint;
			}
		}
		printf("%.7f  %.7f %.7f\n",(double)dist,(double)ans.x,(double)ans.y);
	}
}

int main(){
	//freopen ("flags.in","r",stdin);
	int t;cin>>t;
	while(t--) solve();


	return 0;
}
