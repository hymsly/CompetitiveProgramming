#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
vector<ll> v;

ll f(ll x){
	ll ans=0;
	bool ok=1;
	for(int i=x-m;i>=0;i-=m){
		ans+=2*(v[x]-v[i]);
		if(i==0) ok=0;
	}
	if(ok) ans+=2*(x-v[0]);
	ok=1;
	for(int i=x+m;i<v.size();i+=m){
		ans+=2*(v[i]-v[x]);
		if(i==v.size()-1) ok=0;
	}
	if(ok) ans+=2*(v[v.size()-1]-v[x]);
	return ans;
}

int main(){
	//ios_base::sync_with_stdio(0);
	scanf("%d%d",&n,&m);
	set<ll> S;
	ll num;
	for(int i=0;i<n;i++){
		cin>>num;
		S.insert(num);
	}
	set<ll> :: iterator it;
	for(it = S.begin();it!=S.end();it++){
		v.push_back(*it);
	}
	int lo=0,hi=v.size()-1;
	while((hi-lo)>2){
		ll mi1 = (2*lo + hi)/3;
		ll mi2 = (lo + 2*hi)/3;
		if(f(mi1) >= f(mi2)) lo = mi1;
		else hi=mi2;
	}
	ll ans = (1e18);
	for(ll i=lo;i<=hi;i++) ans = min(ans,f(i));
	cout<<ans<<'\n';

	return 0;
}


