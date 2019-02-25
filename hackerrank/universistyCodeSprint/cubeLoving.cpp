#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = (1e6);

ll f[N+2];
map<ll,bool> M;
pair<ll,bool> cnt ( ll x ){
	pair<ll,bool> ans = make_pair(1,false);
	while(x>1){
		ll div = f[x];
		while(x%div==0){
			x/=div;
		}
		ans.first*=div;
		ans.second = !ans.second;
	}
	return ans;
}
vector<ll> pr;
vector<bool> ex;
void init(){
	for(ll i=2;i*i<=N;i++){
		if(!f[i]){
			for(ll j=i*i;j<=N;j+=i) f[j] = i;
		}
	}
	for(ll i=2;i<=N;i++) if(!f[i]) f[i] = i;
	for(ll i=2;i<=N;i++){
		pair<ll,bool> p = cnt(i);
		M[p.first] = p.second;
	}
	map<ll,bool>:: iterator it;
	for(it=M.begin();it!=M.end();it++){
		pr.push_back((*it).first);
		ex.push_back((*it).second);
	}
}


int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	init();
	int t;cin>>t;
	ll x;
	int len = pr.size();
	while(t--){
		ll ans = 0;
		cin>>x;
		for(int i=0;i<len;i++){
			ll base = pr[i]*pr[i]*pr[i];
			if(base > x) break;
			if(ex[i]) ans+=(x/base);
			else ans-=(x/base);
		}
		cout<<ans<<'\n';
	}

	return 0;
}

