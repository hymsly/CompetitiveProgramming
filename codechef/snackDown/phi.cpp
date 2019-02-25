#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll phi(ll x){
	ll ans = 1;
	for(ll i=2;i*i<=x;i++){
		if(x%i==0){
			while(x%i==0){
				x/=i;
				ans*=i;
			}
			ans/=i;
			ans*=(i-1);
		}
	}
	if(x>1){
		ans*=(x-1);
	}
	return ans;
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	ll x;cin>>x;
	cout<<phi(x)<<'\n';

	return 0;
}

