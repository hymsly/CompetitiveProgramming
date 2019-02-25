#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	//ios_base::sync_with_stdio(0);
	ll n;cin>>n;
	ll x ,y;
	cin>>x>>y;
	if(y<n){
		cout<<"-1"<<endl;
		return 0;
	}
	ll val = n-1 + (y-n+1)*(y-n+1);
	if(val>=x){
		for(int i=1;i<n;i++) cout<<1<<endl;
		cout<<y-n+1<<endl;
	}else{
		cout<<"-1"<<endl;
	}

	return 0;
}


