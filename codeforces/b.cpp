#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a;
int f(int x){
	return abs((x-2)*180-n*a);
}

int main(){
	//ios_base::sync_with_stdio(0);
	cin>>n>>a;
	int lo=3,hi=n;
	while((hi-lo)>2){
		int mi1=(2*lo+hi)/3;
		int mi2=(lo+2*hi)/3;
		if(f(mi1)>f(mi2)){
			lo=mi1;
		}else hi=mi2;
	}
	int ans=lo;
	for(int i=lo+1;i<=hi;i++){
		if(f(i)<f(ans)) ans=i;
	}
	cout<<"2 1 "<<ans<<endl;

	return 0;
}


