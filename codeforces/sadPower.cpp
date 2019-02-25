#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = (1e18);

vector<ll> v;

ll raiz(ll x){
	ll lo=0,hi=1e9+2;
	while((hi-lo)>1){
		ll mi = (hi+lo)/2;
		if(mi*mi>x) hi=mi;
		else lo=mi;
	}
	return lo;
}

bool isquare(ll x){
	ll y = raiz(x);
	if(y*y==x) return true;
	else return false;	
}

void init(){
	set<ll> S;
	S.insert(0LL);
	for(ll i=2;i<=1e6;i++){
		if(isquare(i)) continue;
		ll val = i;
		while(val <= INF/(i*i)){
			val*=(i*i);
			if(val <= INF) S.insert(val);
		}
	}
	set<ll> :: iterator it;
	for(it=S.begin();it!=S.end();it++){
		v.push_back((*it));
	}
}


ll many(ll x){
	ll lo=0,hi=v.size();
	while((hi-lo)>1){
		ll mi = (hi+lo)/2;
		if(v[mi]>x) hi=mi;
		else lo=mi;
	}
	return lo;
}

ll get(ll x){
	if(x==0) return 0;
	ll ans = many(x);
	ll y = raiz(x);
	ans += y;
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	init();
	int q;cin>>q;
	ll l,r;
	while(q--){
		cin>>l>>r;
		cout<<get(r)-get(l-1)<<'\n';
		//cout<<r<<": "<<get(r)<<"\n"<<l-1<<":"<<get(l-1)<<'\n';
	}

	return 0;
}

