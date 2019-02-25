#include<bits/stdc++.h>

using namespace std;

double sqr(double x){
	return x*x;
}

int main(){
	int t;cin>>t;
	int n;
	while(t--){
		double ans = 0.0;
		cin>>n;
		int a,b,c;
		for(int i=0;i<n;i++){
			cin>>a>>b>>c;
			ans += b*(sqr(c/100.0))*a;
		}
		printf("%.6f\n",ans);
	}

	return 0;
}

