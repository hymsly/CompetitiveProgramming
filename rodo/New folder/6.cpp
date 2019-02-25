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
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pair<ll,ll> > tup; 

tup extGcd(ll a,ll b){
	if(b==0) return mp(a,mp(1,0));
	tup ret =  extGcd(b,a%b);
	return mp(ret.fi , mp(ret.se.se, ret.se.fi - (a/b)* ret.se.se));
}

vector<ll> f(ll x){
	vector<ll> ans;
	for(ll i= 2;i<=x;i++){
		if(x%i==0){
			ans.pb(i);
			ans.pb(x/i);
			return ans;
		}
	}
}

ll inv(ll a,ll n){
	tup t= extGcd(a,n);
	ll inver=((t.se.fi%n) + n)%n;
	return inver;
}


ll chino(vector<ll>&rem , vector<ll>&mod){
	int k=sz(mod);
	ll n=1;
	for(int i=0;i<k;i++) n*=mod[i];
	ll x=0;
	for(int i=0;i<k;i++){
		ll m=n/mod[i];
		ll y=inv(m,mod[i]);
		y%=n;
		x+=(rem[i] * ( ( m*y) % n))%n;
		x%=n;
	}
	return x;
}


int main(){
	//fast_io()
	int t;cin>>t;
	ll n;
	while(t--){
		cin>>n;
		vector<ll> p = f(n);
		vector<ll> a ,b;
		a.pb(0LL);a.pb(1LL);
		b.pb(1LL);b.pb(0LL);
		vector<ll> ans;
		ans.pb(0);ans.pb(1);
		ans.pb(chino(a,p));
		ans.pb(chino(b,p));
		sort(all(ans));
		for(int i=0;i<ans.size();i++) cout<<ans[i]<<(char)(i+1==ans.size()?10:32);
	}

	
	return 0;
}

