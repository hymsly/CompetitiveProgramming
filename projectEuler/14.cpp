#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
map<ll,int> memo;

int dp(ll x){
	if(x==1) return 1;
	if(memo.find(x) != memo.end()) return memo[x];
	int &ans = memo[x] = 1;
	if(x&1) ans += dp(3*x+1);
	else ans += dp(x/2);
	return ans;
}

int main(){
	int maxi = 0;
	ll ans = 0;
	for(ll i=1;i<1000000;i++){
		int val = dp(i);
		if(val > maxi){
			maxi = val;
			ans = i;
		}
	}
	cout<<ans<<endl;

	return 0;
}

