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

ll conquer(int l,int r){
	if(r<=l+1) return 0LL;
	int mi = (l+r)/2;
	ll ans = conquer(l,mi) + conquer(mi,r);
	map<ll,ll> left[11],right[11];
	for(int i=l;i<mi;i++){
		left[p[i].second][p[i].first]++;
	}
	for(int i=mi;i<r;i++){
		right[p[i].second][p[i].first]++;
	}
	for(int i=l;i<mi;i++){
		ans += get(p[i].first,right);
	}
	for(int i=mi;i<r;i++){
		ans += get(p[i].first,left);
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
	cout<<conquer(0,n)<<'\n';

	return 0;
}
