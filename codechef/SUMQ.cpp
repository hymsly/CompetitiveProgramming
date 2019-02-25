#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=(1e9+7);

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;cin>>t;
	ll n,m,p;
	while(t--){
		cin>>n>>m>>p;
		vector<ll> a(n);
		vector<ll> b(m);
		vector<ll> c(p);
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<m;i++) cin>>b[i];
		for(int i=0;i<p;i++) cin>>c[i];
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		sort(c.begin(),c.end());
		vector<ll> acuma(n);
		vector<ll> acumc(p);
		for(int i=0;i<n;i++){
			if(i) acuma[i] = acuma[i-1] + a[i];
			else acuma[i] = a[i];
		}
		for(int i=0;i<p;i++){
			if(i) acumc[i] = acumc[i-1] + c[i];
			else acumc[i] = c[i];
		}
		ll ans=0;
		for(int i=0;i<m;i++){
			ll posa = upper_bound(a.begin(),a.end(),b[i]) - a.begin();
			ll posc = upper_bound(c.begin(),c.end(),b[i]) - c.begin();
			if(posa && posc) ans += (((b[i]*posa)%MOD + acuma[posa-1])%MOD)*(((b[i]*posc)%MOD + acumc[posc-1])%MOD)%MOD;
			ans%=MOD;
		}
		cout<<ans<<'\n';
	}

	return 0;
}


