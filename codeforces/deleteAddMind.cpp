#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;

vector<ll> v;
vector< pair<ll,ll> > p;

ll pot[11];

ll get(ll mod,map<ll,ll> f[]){
	ll ans = 0;
	for(int i=1;i<11;i++){
		ll val = (k-(mod*pot[i])%k)%k;
		if(f[i].count(val)) ans+=f[i][val];
	}
	return ans;
}

ll solve(){
	map<ll,ll> M[11];
	for(int i=0;i<n;i++){
		M[p[i].second][p[i].first]++;
	}
	ll ans = 0;
	for(int i=0;i<n;i++){
		M[p[i].second][p[i].first]--;
		ans += get(p[i].first,M);
		M[p[i].second][p[i].first]++;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n>>k;
	pot[0] = 1;
	for(int i=1;i<11;i++){
		pot[i] = pot[i-1]*10;
		pot[i] %= k;
	}
	v.resize(n);
	p.resize(n);
	for(int i=0;i<n;i++) cin>>v[i];
	for(int i=0;i<n;i++){
		p[i].first = v[i]%k;
		p[i].second = 0;
		while(v[i]){
			p[i].second++;
			v[i]/=10;
		}
	}
	cout<<solve()<<'\n';

	return 0;
}
