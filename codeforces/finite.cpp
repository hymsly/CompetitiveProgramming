#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
	ll p,q,b;
	cin>>p>>q>>b;
	ll divi = __gcd(p,q);
	q/=divi;
	//q no deberia tener divisor primo que no divida a b
	while(1){
		ll aux = __gcd(q,b);
		if(aux==1) break;
		while(q%aux==0) q/=aux;
	}
	if(q==1) cout<<"Finite\n";
	else cout<<"Infinite\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

