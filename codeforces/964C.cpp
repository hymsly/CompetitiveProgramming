#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = (1e9+9);

ll POT(ll x,ll y){
	if(y==0) return 1;
	if(y==1) return x;
	ll ans = 1;
	if(y&1) ans = x;
	ll val = POT(x,y/2);
	ans *= val;
	ans %= MOD;
	ans *= val;
	ans %= MOD;
	return ans;
}

ll inv(ll x){
	return POT(x,MOD-2)%MOD;
}

int main(){
	ll n,a,b,k;cin>>n>>a>>b>>k;
	string s;cin>>s;
	ll ans = 0;
	ll division = (b*inv(a))%MOD;
	ll val = POT(a,n);
	for(int i=0;i<k;i++){
		if(s[i]=='+') ans+=val;
		else ans-=val;
		ans %= MOD;
		ans += MOD;
		ans %= MOD;
		val *= division;
		val %= MOD;
	}
	ans %= MOD;
	ans += MOD;
	ans %= MOD;
	ll cnt = (n+1)/k;
	division = POT(division,k);
	if(division != 1){
		ans *= (POT(division,cnt)-1);
		ans %= MOD;
		ans *= inv(division-1);
		ans %= MOD;
		cout<<ans<<endl;
	}else{
		ans *= cnt;
		ans %= MOD;
		cout<<ans<<endl;
	}

	return 0;
}

