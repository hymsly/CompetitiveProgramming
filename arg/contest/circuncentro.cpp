#include <bits/stdc++.h>
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define pb push_back
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define mset(x,y) memset(&x,(y),sizeof(x));
#define fi first
#define se second
#define Vector Point
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
const long double EPS = (1e-9);

typedef long long ll ;
typedef vector<ll> vi ;


const long double PI = acos(-1.0L);
struct Point{
	long double x, y;
	Point(){}
	Point(long double a, long double b) { x = a; y = b; }
	long double mod2() { return x*x + y*y; }
	long double mod() { return sqrt(x*x+y*y); }
	long double arg() { return atan2(y, x); }
	Point ort() { return Point(-y, x); }
	Point unit() { long double k = mod(); return Point(x/k, y/k); }
};
Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator *(const Point &a, long double k) { return Point(a.x*k, a.y*k); }
Point operator /(const Point &a, long double k) { return Point(a.x/k, a.y/k); }

long double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
long double dot(const Vector &A, const Vector &B) { return A.x * B.x + A.y * B.y; }

Point circumcenter(const Point &A, const Point &B, const Point &C){
	return (A + B + (A - B).ort() * dot(C - B, A - C) / cross(A - B, A - C)) / 2.0;
}
bool Comp(Point o,Point a,Point b){
	return ((a+b)-(o+o)).mod()<EPS;
}
int bad(Point p,Point q,Point r){
	long double t = min(dot(q-p,r-p),min(dot(p-q,r-q),dot(p-r,q-r)));
	if(t<-EPS)return -1;
	else if (t<EPS)return 0;
	return 1;
}
bool cmp(const Point &A, const Point &B, const Point &C){
	Point _A = Point(1.0*A.x,1.0*A.y);
	Point _B = Point(1.0*B.x,1.0*B.y);
	Point v1 = C-_B, v2 = C-_A;
	if( cross(v1,v2) < EPS  ) return 1;
	return 0;
}

bool valid(const Point &A, const Point &B, const Point &C, const Point &D ){
	return cmp(A,B,D) || cmp(B,C,D) || cmp(C,A,D);
}

bool colinial(const Point &A, const Point &B, const Point &C){
	Point v1 = B-A, v2 = C-A;
	if( cross(v1,v2) == 0 ) return 1;
	return 0;
}

vector<Point> nP, res;
vector<long double> rt;
int det[1005];
int main(){
	fast_io();
	streamsize precisionOriginal=cout.precision();
	cout.precision(10);
	cout<<fixed<<showpoint;
	
	int n; 
	cin>>n;
	long double x,y; 
	ll xl, yl;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		nP.pb( Point(x,y) );
	}
	long double maxi = -1.0;

	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				Point aux = circumcenter( nP[i], nP[j] , nP[k] );
				int bx = bad( nP[i], nP[j] , nP[k] );
				if( bx == -1 ) continue;
				//cout<<-1<<endl;
				long double d = (nP[i]-aux).mod();
				bool bb=0;
				for(int u=0;u<n;u++){
					if( (nP[u]-aux).mod()<d ) bb=1;
				}
				if( bb )continue;
				//cout<<-2<<endl;
				if(bx==0){
					
					for(int uu=0;uu<3;uu++)det[uu]=0;
					for(int u=0;u<n;u++){
						if(Comp(aux,nP[u],nP[i]))det[0]++;
						if(Comp(aux,nP[u],nP[j]))det[1]++;
						if(Comp(aux,nP[u],nP[k]))det[2]++;
					}	
					if(!det[0] || !det[1] || !det[2]){
						bb=1;
					}
				}
				if( bb )continue;
				//cout<<maxi<<endl;
				maxi=max(d,maxi);
				//cout<<-3<<endl;
			}
		}
	}
	
	if(maxi< -EPS)cout<<-1<<endl;
	else cout<<maxi<<endl;
	return 0;
}
