#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll x){
	return x*x*x;
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n,k;cin>>n>>k;
	ll ans = 0;
	ans += f(n/k);
	if(k%2==0) ans += f(n/(k/2) - n/k);
	cout<<ans<<endl;

	return 0;
}

