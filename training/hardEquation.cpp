#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a,b,m;

ll pot(ll x,ll y,ll mod){
	if(y==0) return 1LL;
	if(y==1) return x;
	ll ans = 1;
	if(y&1) ans = x;
	ll val = pot(x,y/2,mod);
	ans *= val;
	ans %= mod;
	ans *= val;
	ans %= mod;
	return ans;
}

void solve(){
	cin>>a>>b>>m;
	a%=m;
	b%=m;
	if(m==1){
		if(a==0) cout<<1<<'\n';
		else cout<<0<<'\n';
		return;
	}
	if(b==1){
		cout<<0<<'\n';
		return;	
	}
	ll n = 1;
	while(n*n<m) n++;
	map<ll,int> M;
	ll base = pot(a,n,m);
	ll curPot = base;
	for(int i=1;i<=n;i++){
		M[curPot] = i;
		curPot *= base;
		curPot %= m;
	}
	ll vali = 1;
	for(int i=0;i<n;i++){
		ll cur = vali*b;
		cur %= m;
		if(M.count(cur)){
			cout<<M[cur]*n-i<<'\n';
			return;
		}
		vali*=a;
		vali%=m;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int t;cin>>t;
	while(t--) solve();


	return 0;
}
