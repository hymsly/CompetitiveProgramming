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
const ll N=(431);

bool pr[N+5];
vector<ll> pri;
vector<ll> pot;

ll f(ll x,ll y){
	ll ans=0;
	while(x){
		ans+=(x/y);
		x/=y;
	}
	return ans;
}

int main(){
	//fast_io()
	memset(pr,1,sizeof(pr));
	for(ll i=2;i*i<=N;i++){
		if(pr[i]){
			for(int j=i*i;j<=N;j+=i) pr[j] = 0;
		}
	}
	for(int i=2;i<=N;i++){
		if(pr[i]) pri.pb(i);
	}
	ll n,k;
	while(cin>>n>>k){
		pot.clear();
		pot.resize(pri.size());
		for(int i=0;i<pri.size();i++){
			pot[i]=f(n,pri[i]);
			pot[i]-=f(k,pri[i]);
			pot[i]-=f(n-k,pri[i]);
		}
		ll ans=1;
		for(int i=0;i<pot.size();i++){
			ans*=(pot[i]+1);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

