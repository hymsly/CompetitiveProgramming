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
vector<ll> pr;
vector<ll> ex;


void f(ll x){
	for(ll i=2;i*i<=x;i++){
		if(x%i==0){
			pr.pb(i);
			ll cnt=0;
			while(x%i==0) x/=i,cnt++;
			ex.pb(cnt);	
		}
	}
	if(x>1) pr.pb(x),ex.pb(1LL);
}

bool is(ll x){
	for(int i=0;i<pr.size();i++){
		ll cnt = 0;
		ll aux = x;
		while(aux){
			cnt+=aux/pr[i];
			aux/=pr[i];
		}
		if(cnt<ex[i]) return false;
	}
	return true;
}

int main(){
	//fast_io()
	ll n,m;
	while(cin>>n>>m){
		pr.clear();
		ex.clear();
		f(m);
		if(is(n)) cout<<m<<" divides "<<n<<"!\n";
		else cout<<m<<" does not divide "<<n<<"!\n";
	}
	
	return 0;
}

