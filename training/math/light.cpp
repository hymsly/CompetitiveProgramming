#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is(ll x){
	ll p = (ll) sqrt(x);
	if(p*p==x) return true;
	if((p-1)*(p-1)==x) return true;
	if((p+1)*(p+1)==x) return true;
	return false;
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	ll x;
	while(cin>>x){
		if(x==0) break;
		if(is(x)) cout<<"yes\n";
		else cout<<"no\n";
	}

	return 0;
}

