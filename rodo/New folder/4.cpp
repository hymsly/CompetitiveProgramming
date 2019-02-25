#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(x) push_back(x)

#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
#define fi first
#define se second
#define sz(v) ((int)v.size())
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll MOD=(1e9+7);
vector<ll> pr,ex;

ll pot(ll x,ll y){
	if(y==0) return 1LL;
	if(y==1) return x;
	ll ans = 1;
	if(y&1) ans = x;
	ll val =pot(x,y/2);
	ans*=val;
	ans%=MOD;
	ans*=val;
	ans%=MOD;
	return ans;
}

ll inv(ll x){
	return pot(x,MOD-2)%MOD;
}

ll tot(ll x){
	x%=MOD;
	x*=(x+1);
	x%=MOD;
	x*=inv(2LL);
	x%=MOD;
	return x;
}

ll cant(ll x,ll y){
	return ((y%MOD)*tot(x/y))%MOD;
}

void f(ll x){
	for(ll i=2;i*i<=x;i++){
		ll cnt = 0;
		while(x%i==0) cnt++,x/=i;
		if(cnt){
			pr.pb(i);ex.pb(cnt);
		}
	}
	if(x>1){
		pr.pb(x);ex.pb(1);
	}
}


int main(){
	//fast_io()
	ll n;
	while(cin>>n){
		if(n==0) break;
		pr.clear();ex.clear();
		f(n);
		ll ans = 0;
		for(int mask=1;mask<(1<<pr.size());mask++){
			ll primo = 1;
			int cnt = 0;
			for(int j=0;j<pr.size();j++){
				if((1<<j) & mask){
					cnt++;
					primo *= pr[j];
				}
			}
			if(cnt & 1) ans += cant(n-1,primo);
			else ans -= cant(n-1,primo);
			ans%=MOD;
			ans+=MOD;
			ans%=MOD;
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}

