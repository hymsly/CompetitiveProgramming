#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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
	if(rabin(n)){f[-n]++;return;}
	ll q=rho(n);fact(q,f);fact(n/q,f);
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	string s;
	while(1){
		getline(cin,s);
		if(s=="0") break;
		ll x = 1;
		stringstream ss(s);
		ll num,exp;
		while(ss>>num>>exp){
			while(exp--) x*=num;
		}
		x--;
		map<ll,int> f;
		fact(x,f);
		map<ll,int> :: iterator it;
		bool ok=1;
		for(it=f.begin();it!=f.end();it++) cout<<(ok?"":" ")<<-(*it).first<<" "<<(*it).second,ok=0;
		cout<<'\n';
	}

	return 0;
}

