#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N=301;

ll X[N];
ll Y[N];
ll vis[N][N];
vector< pair<ll,ll> > v;
ll ac0[N];
ll ac1[N];

ll dis(ll i, ll j){
	return (X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]);
}

void solve(){
	ll n;
	scanf("%lld",&n);
	for(ll i=0; i<n; i++){
		ac0[i]=0;
		ac1[i]=0;
	}
	for(ll i=0; i<n; i++){
		scanf("%lld",&X[i]);
	}
	for(ll i=0; i<n; i++){
		scanf("%lld",&Y[i]);
	}
	for(ll i=0; i<n; i++){
		for(ll j=0; j<n; j++){
			scanf("%lld",&vis[i][j]);
			v.push_back(make_pair(dis(i,j),vis[i][j]));
		}
	}
	sort(v.begin(),v.end());
	
	
	return;
}

int main(){
	ll t;
	scanf("%lld",&t);
	for(ll i=0; i<t; i++){
		solve();
	}
	return 0;
}
