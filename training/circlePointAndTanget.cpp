#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef long long ll;
typedef long double ld;
const int N = (1e5);
const ld INF = (1e16L);
const ld EPS = (1e-9);

struct Point{
	ld x,y;
	Point(){}
	pair<ld,ld> getRadio(ld r){
		ld b = 2*x;
		ld c = x*x+y*y-2*y*r;
		ld d = b*b-4*c;
		if(d<EPS) return mp(1.0L,0.0L);
		d = sqrt(d);
		return mp(x-d/2.0L,x+d/2.0L);
	}
} P[N+2];
int n;
bool f(ld x){
	ld left = -INF,right = INF;
	for(int i=0;i<n;i++){
		pair<ld,ld> cur = P[i].getRadio(x);
		left = max(left,cur.first);
		right = min(right,cur.second);	
	}
	if(right+EPS <= left) return false;
	return true;
}


int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++) cin>>P[i].x>>P[i].y;
	int ok=0;
	for(int i=0;i<n;i++) ok|=(P[i].y<0?1:2);	
	if(ok==3){
		cout<<-1<<'\n';
		return 0;
	}
	for(int i=0;i<n;i++) P[i].y=abs(P[i].y);
	ld lo=0.0L,hi=INF;
	for(int i=0;i<100;i++){
		ld mi = (hi+lo)/2.0L;
		if(f(mi))hi=mi;
		else lo=mi;
	}
	printf("%.10f\n",(double)hi);

	return 0;
}

