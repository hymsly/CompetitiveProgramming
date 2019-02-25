#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
const ll INF = (1e18+1LL);
ll n,m;
ll tot;
vector< pair<ll,ll> > v;

bool can(ll x){
	ll need = 0;
	for(int i=0;i<n;i++){
		if(v[i].se==0) need+=v[i].fi;
		else need += min(v[i].fi,x/v[i].se);
	}
	if(need+m>=tot) return true;
	return false;
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	v.resize(n);
	for(int i=0;i<n;i++) cin>>v[i].fi;
	for(int i=0;i<n;i++) cin>>v[i].se;
	for(int i=0;i<n;i++) tot+=v[i].fi;
	if(m>=tot){
		cout<<"0\n";
		return 0;
	}
	if(can(0)){
		cout<<"0\n";
		return 0;
	}
	ll lo=0,hi=INF;
	while((hi-lo)>1){
		ll mi = (hi+lo)/2;
		if(can(mi)) hi=mi;
		else lo=mi;
	}
	cout<<hi<<'\n';

	return 0;
}

