#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mcm(ll x,ll y){
	ll ans = x/__gcd(x,y);
	ans *= y;
	return ans;
}
vector< pair<ll,ll> > v;

set<ll> S;

bool is(ll x){
	bool ok=1;
	for(int i=0;i<v.size();i++){
		if(v[i].first%x!=0 && v[i].second%x!=0) ok=0;
	}
	return ok;
}

ll mulmod(ll a, ll b, ll m) {
	if(!b)return 0;
	ll q=mulmod(a,b/2,m);q=(q+q)%m;
	return b&1?(q+a)%m:q;
}
ll expmod(ll b, ll e, ll m){
	if(!e)return 1;
	ll q=expmod(b,e/2,m);q=mulmod(q,q,m);
	return e&1?mulmod(b,q,m):q;
}
bool is_prime_prob(ll n, int a){
	if(n==a)return true;
	ll s=0,d=n-1;
	while(d%2==0)s++,d/=2;
	ll x=expmod(a,d,n);
	if((x==1)||(x+1==n))return true;
	for(int i=0;i<s;i++){
		x=mulmod(x,x,n);
		if(x==1)return false;
		if(x+1==n)return true;
	}
	return false;
}
bool rabin(ll n){ // true iff n is prime
	if(n==1)return false;
	int ar[]={2,3,5,7,11,13,17,19,23};
	for(int i=0;i<9;i++) if(!is_prime_prob(n,ar[i])) return false;
	return true;
}
ll rho(ll n){
    if(!(n&1))return 2;
    ll x=2,y=2,d=1;
    ll c=rand()%n+1;
    while(d==1){
        x=(mulmod(x,x,n)+c)%n;
        y=(mulmod(y,y,n)+c)%n;
        y=(mulmod(y,y,n)+c)%n;
        if(x>=y)d=__gcd(x-y,n);
        else d=__gcd(y-x,n);
    }
    return d==n?rho(n):d;
}
void fact(ll n, map<ll,int>& f){ //O (lg n)^3
	if(n==1)return;
	if(rabin(n)){f[n]++;return;}
	ll q=rho(n);fact(q,f);fact(n/q,f);
}
map<ll,int> m;

int main(){
	//ios_base::sync_with_stdio(0);
	int n;cin>>n;
	v.resize(n);
	ll a,b;
	cin>>a>>b;
	v[0].first = a;
	v[0].second = b;
	ll ans = mcm(a,b);
	for(int i=0;i<n;i++){
		cin>>a>>b;
		v[i].first = a;
		v[i].second = b;
		ans = __gcd(ans,mcm(a,b));
	}
	if(ans==1){
		cout<<"-1\n";
		return 0;
	}
	fact(ans,m);
	map<ll,int> :: iterator it;	
	for(it=m.begin();it!=m.end();it++){
		if(is((*it).first)){
			cout<<(*it).first<<'\n';
			return 0;
		}
	}
	cout<<"-1\n";

	return 0;
}
