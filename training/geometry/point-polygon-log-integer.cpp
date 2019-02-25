#include<bits/stdc++.h>
#define Vector Point
using namespace std;
#define fore(i,a,b) for(int i=a,to=b;i<to;i++)
typedef long long ll;
struct Point{
	ll x,y;
	Point(){}
	Point(ll _x,ll _y){
		x = _x;y = _y;
	}
	ll mod2(){
		return (x*x+y*y);
	}
	ll operator%(Point P){return x*P.y-y*P.x;}
};

Point operator +(const Point &a ,const Point &b){
	return Point(a.x+b.x,a.y+b.y);
}
Point operator -(const Point &a ,const Point &b){
	return Point(a.x-b.x,a.y-b.y);
}

bool operator <(const Point &a, const Point &b){
	if(a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}
ll cross(const Vector &A, const Vector &B){
	return A.x * B.y - A.y * B.x;
}

ll area(const Point &A, const Point &B, const Point &C) {
	return cross(B - A, C - A);
}
vector <Point> ConvexHull(vector <Point> Poly){
	sort(Poly.begin(),Poly.end());
	int nP = Poly.size(),k = 0;
	Point H[ 2*nP ];
	for( int i = 0 ; i < nP ; ++i ){
	while( k >= 2 && area( H [ k - 2 ] , H[ k - 1 ] , Poly[ i] ) <= 0) --k;
		H[ k++ ] = Poly[ i ];
	}
	for( int i = nP - 2 , t = k ; i >= 0 ; --i ){
	while( k > t && area( H[ k - 2 ] , H[ k - 1 ] , Poly[ i ]) <= 0) --k;
		H[ k++ ] = Poly[ i ];
	}
	if( k == 0 )return vector <Point>();
	return vector <Point> ( H , H + k - 1 );
}
bool isInConvex(vector<Point>&P,Point &A){
	int n = P.size(),lo=1,hi=P.size()-1;
	if(area(P[0],P[1],A)<0) return 0;
	if(area(P[n-1],P[0],A)<0) return 0;
	while(hi-lo>1){
		int mid = (hi+lo)/2;
		if(area(P[0],P[mid],A) > 0) lo=mid;
		else hi = mid;
	}
	return area(P[lo],P[hi],A)>=0;
}


int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n;cin>>n;
	vector<Point> v;
	for(int i=0;i<n;i++){
		Point cur;cin>>cur.x>>cur.y;
		v.push_back(cur);
	}
	vector<Point> w = ConvexHull(v);
	int q;cin>>q;
	int ans = 0;
	while(q--){
		Point query;cin>>query.x>>query.y;
		if(isInConvex(w,query)){
			ans++;
		}
	}
	cout<<ans<<'\n';

	return 0;
}

