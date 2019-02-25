#include<bits/stdc++.h>

using namespace std;
#define Vector Point
typedef long long ll;
struct Point{
	ll x,y,z;
	Point(){}
	Point(ll _x,ll _y,ll _z){
		x = _x;
		y = _y;
		z = _z;
	}
};


struct Mat{
	ll M[3][3];
	Mat(){
		memset(M,0,sizeof M);
	}
	Mat(Point a,Point b,Point c){
		M[0][0] = a.x;M[1][0] = b.x;M[2][0] = c.x;
		M[0][1] = a.y;M[1][1] = b.y;M[2][1] = c.y;
		M[0][2] = a.z;M[1][2] = b.z;M[2][2] = c.z;
	}
	void set(int x){
		for(int i=0;i<3;i++){
			M[i][x] = 1LL;
		}
	}
	ll det(){
		ll ans = 0;
		for(int i=0;i<3;i++){
			ll cur1 = 1,cur2 = 1;
			for(int j=0;j<3;j++){
				cur1 *= M[j][(i+j)%3];
				cur2 *= M[j][(i-j+3)%3];
			}
			ans += (cur1-cur2);
		}
		return ans;
	}
};

vector< Point > v;

Point operator -(const Point &a,const Point &b){
	return Point(a.x-b.x,a.y-b.y,a.z-b.z);
}

bool notline(Point a,Point b,Point c){
	a=a-c;
	b=b-c;
	if ( a.y*b.z==b.y*a.z && a.x*b.z==b.x*a.z && a.x*b.y==b.x*a.y ) return false ;
	return true ;
}

Vector Crammer(Point a,Point b,Point c){
	Mat matriz(a,b,c);
	Mat matrizX = matriz;
	matrizX.set(0);
	Mat matrizY = matriz;
	matrizY.set(1);
	Mat matrizZ = matriz;
	matrizZ.set(2);
	Point ec;
	ec.x = matrizX.det();
	ec.y = matrizY.det();
	ec.z = matrizZ.det();
	return ec;
}

ll eval(Vector a,Point c){
	return c.x*a.x + c.y*a.y + c.z*a.z;
}



int main(){
	int n;cin>>n;
	if(n<=3){
		cout<<"TAK\n";
		return 0;
	}
	v.resize(n);
	ll a,b,c;
	for(int i=0;i<n;i++){
		cin>>a>>b>>c ;
		v[i] = Point(a,b,c);
	}
	Point p1=v[0],p2=v[1],p3;
	bool ok = 0;
	for(int i=2;i<n;i++){
		if(notline(p1,p2,v[i])){
			ok = 1;
			p3 = v[i];
			break;
		}
	}
	if(!ok){
		cout<<"TAK\n";
		return 0;
	}
	Mat matriz(p1,p2,p3);
	ll determ = matriz.det();
	Vector ec = Crammer(p1,p2,p3);
	
	for(int i=1;i<n;i++){
		ll val = eval(ec,v[i]);
		if(val != determ){
			cout<<"NIE\n";
			return 0;
		}
	}
	cout<<"TAK\n";

	return 0;
}
