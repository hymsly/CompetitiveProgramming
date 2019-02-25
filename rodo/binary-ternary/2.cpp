#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector< pair<int,int> > v;

double sqr(double x){
	return x*x;
}

double dist(pair<double,double> p,pair<double,double> q){
	return sqrt(sqr(p.first-q.first) + sqr(p.second-q.second));
}

double getdist(double x,double y){
	double ans=0.0;
	pair<double,double> p = make_pair(x,y);
	for(int i=0;i<v.size();i++){
		ans = max(ans,dist(v[i],p));
	}
	return ans;
}

double gety(double x){
	double lo=(-1e4),hi=(1e4);
	
	for(int i=0;i<100;i++){
		double mi1 = (2*lo + hi)/3.0;
		double mi2 = (lo + 2*hi)/3.0;
		
		if(getdist(x,mi1) > getdist(x,mi2)) lo = mi1;
		else hi = mi2;
	}
	
	return (lo+hi)/2.0;

}

double get(){
	double lo=(-1e4),hi=(1e4);
	
	for(int i=0;i<100;i++){
		double mi1 = (2*lo + hi)/3.0;
		double mi2 = (lo + 2*hi)/3.0;
		
		
		double y1 = gety(mi1);
		double y2 = gety(mi2);
		
		
		if(getdist(mi1,y1) > getdist(mi2,y2)) lo=mi1;
		else hi=mi2;
	}

	double ansx = (lo+hi)/2.0;
	double ansy = gety(ansx);
	
	
	return getdist(ansx,ansy);

}

int main(){
	//ios_base::sync_with_stdio(0);
	int n;cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++){
		cin>>v[i].first>>v[i].second;
	}
	
	double ans = 2.0*get();
	
	printf("%.2f\n",ans);

	return 0;
}


