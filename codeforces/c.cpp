#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(x) push_back(x)

#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
#define fi first
#define se second
#define sz(v) ((int)v.size())
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const double EPS=(1e-6);

int main(){
	//fast_io()
	int n;cin>>n;
	int x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;
	double mini=0.0,maxi=(1e18);
	int x,y,vx,vy;
	for(int i=0;i<n;i++){
		cin>>x>>y>>vx>>vy;
		double val1,val2,val3,val4;
		if(vx==0){
			if(x>=x1 && x<=x2){
				val1 = 0.0;
				val2 = (1e18);
			}else{
				val1 = 0.0;
				val2 = -0.1;
			}
		}else if(vx>0){
			val1 = (double)(x1-x)/(double)vx;
			if(val1<0.0){
				val1=0.0;
			}
			val2 = double (x2-x)/ (double) vx;
			if(val2<0.0){
				val2=-0.1;
			}
		}else{
			vx = abs(vx);
			val1 = (double)(x-x2)/(double)vx;
			if(val1<0.0){
				val1=0.0;
			}
			val2 = double (x-x1)/ (double)vx;
			if(val2<0.0){
				val2=-0.1;
			}
		}
		if(vy==0){
			if(y>=y1 && y<=y2){
				val3 = 0.0;
				val4 = (1e18);
			}else{
				val3 = 0.0;
				val4 = -0.1;
			}
		}else if(vy>0){
			val3 = (double)(y1-y)/(double)vy;
			if(val3<0.0){
				val3=0.0;
			}
			val4 = double (y2-y)/ (double) vy;
			if(val4<0.0){
				val4=-0.1;
			}
		}else{
			vy = abs(vy);
			val3 = (double)(y-y2)/(double)vy;
			if(val3<0.0){
				val3=0.0;
			}
			val4 = (double)(y-y1)/ (double)vy;
			if(val4<0.0){
				val4=-0.1;
			}
		}
		mini = max(mini , val1);
		mini = max(mini , val3);
		maxi = min(maxi , val2);
		maxi = min(maxi , val4);
	}
	if(maxi<mini){
		cout<<-1<<endl;
	}else{
		printf("%.20f\n",mini);
	}
	
	return 0;
}

