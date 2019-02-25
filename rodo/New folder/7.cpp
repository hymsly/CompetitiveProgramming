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

ll divi(ll x){
	ll ans = 1;
	for(int i=0;i<ex.size();i++){
		ans*=(ex[i]+1);
	}
	return ans;
}

ll phi(ll x){
	ll ans = x;
	for(int i=0;i<ex.size();i++){
		ans /= pr[i];
		ans *= (pr[i]-1);
	}
	return ans;
}

int main(){
	//fast_io()
	ll n;
	while(cin>>n){
		if(n==0) break;
		pr.clear();ex.clear();
		f(n);
		ll ans = n+1;
		ans -= phi(n);
		ans -= divi(n);
		cout<<ans<<endl;
	}
	
	
	return 0;
}

