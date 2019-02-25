#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

bool is(ll x){
	ll aux = x;
	ll ans = 0;
	while(aux){
		ans *= 10;
		ans += aux%10;
		aux /= 10;
	}
	return (ans==x);
}

int main(){
	ll ans = 0;
	for(ll i=100;i<1000;i++){
		for(ll j=i;j<1000;j++){
			ll val = i*j;
			if(is(val)) ans = max(ans,val);
		}
	}
	cout<<ans<<endl;

	return 0;
}

