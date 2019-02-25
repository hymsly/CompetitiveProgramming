#include<bits/stdc++.h>

using namespace std;
const int INF = (1e9);


struct Point{
	double x,y;
	double reg;
	Point(){}
	Point(double _x,double _y){
		x = _x;
		y = _y;
		reg = atan2(y,x);
	}
	double mod(){
		return sqrt(x*x+y*y);
	}
	Point ort(){
		return Point(-y,x);
	}
	Point unit(){
		double k = mod();
		return Point(x/k,y/k);
	}
};

vector<Point> v;

bool operator < (const Point &a,const Point &b){
	return a.reg<b.reg;
}

Point operator - (const Point &a,const Point &b){
	return Point(a.x-b.x,a.y-b.y);
}

Point operator + (const Point &a,const Point &b){
	return Point(a.x+b.x,a.y+b.y);
}

int main(){
	int n;cin>>n;
	int a,b;
	Point mini = Point(INF,0);
	for(int i=0;i<n;i++){
		cin>>a>>b;
		v[i] = Point(a,b);
		if(mini.x > v[i].x){
			mini = v[i];
		}
	}

	return 0;
}

