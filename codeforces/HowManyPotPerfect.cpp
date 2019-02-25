#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (1e18);

bool isSquare(ll x){
	ll y = (ll) sqrt(x);
	if(y*y==x) return true;
	if((y-1)*(y-1)==x) return true;
	if((y+1)*(y+1)==x) return true;
	return false;
}

bool prime(ll x){
	for(ll i=2;i*i<=x;i++){
		if(x%i==0) return false;
	}
	return true;
}

ll f(ll x,ll y){
	ll ans = 1;
	for(int i=0;i<y;i++){
		if(ans>INF/x) return INF+1;
		ans*=x;
	}
	return ans;
}

set<ll> used;
vector<ll> G;

void init(){
	for(ll i=3;i<=64;i+=2){
		for(ll j=2;;j++){
			if(isSquare(j)) continue;
			ll val = f(j,i);
			if(val>INF) break;
			if(used.find(val) != used.end()) continue;
			G.push_back(val);
			used.insert(val);
		}
	}
	sort(G.begin(),G.end());
}

int main(){
	clock_t s = clock();
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	init();
	cout<<G.size()<<endl;
	int t;cin>>t;
	//for(int i=0;i<20;i++) cout<<G[i]<<(char)(i+1==G.size()?10:32);
	while(t--){
		ll x;cin>>x;
		ll ans = (ll) sqrt(x);
		if(ans*ans>x){
			ans--;
		}
		ll p = lower_bound(G.begin(),G.end(),x+1) - G.begin();
		ans += p;
		cout<<x-ans<<'\n';
	}
	cout<<float( clock () - s ) /  CLOCKS_PER_SEC<<'\n';

	return 0;
}

