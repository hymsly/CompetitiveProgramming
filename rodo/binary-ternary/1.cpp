#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

double sqr(double x){
	return x*x;
}

double dist(double a,double b,double c,double d){
	return sqrt(sqr(a-c) + sqr(b-d));
}

int main(){
	//ios_base::sync_with_stdio(0);
	int t;cin>>t;
	double ax,ay,bx,by;
	double px,py,qx,qy;
	while(t--){
		cin>>ax>>ay>>bx>>by;
		px = ax;
		py = -ay;
		qx = -bx;
		qy = by;
		double ans = dist(ax,ay,bx,by) + dist(px,py,qx,qy);
		printf("%.3f\n",ans);
	}

	return 0;
}


