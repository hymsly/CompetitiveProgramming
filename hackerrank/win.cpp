#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll m,x;
ll v[35];
ll X[1000005];
typedef pair<ll,pair<ll,ll> > tup;

tup extGcd(ll a,ll b){
	if(b==0) return make_pair(a,make_pair(1,0));
	tup ret = extGcd(b,a%b);
	return make_pair(ret.first , make_pair(ret.second.second, ret.second.first - (a/b)*ret.second.second));
}

ll inv(ll a,ll n){
	tup t= extGcd(a,n);
	ll inver=((t.second.first%n) + n)%n;
	return inver;
}

ll get(ll t){
	ll ans = 0;
	ll gcd = __gcd(m,t);
	if(x%gcd!=0) return ans;
	ll auxm = m;
	ll auxx = x;
	t/=gcd;
	auxm/=gcd;
	auxx/=gcd;
	ll inversa = (inv(t,auxm)*auxx)%auxm;
	for(int i=0;i<m;i++){
		ll newval = auxm*i+inversa;
		if(newval >= m) return ans;
		ans += X[newval];
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin>>n>>m>>x;
	if(m==1){
		cout<<(1<<n)-1<<endl;
		return 0;
	}
	for(int i=0;i<n;i++) cin>>v[i];
	if(n==1){
		if(v[0]%m==x) cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	int val = (n/2);
	ll ans = 0;
	for(ll mask = 1;mask < (1<<val);mask++){
		ll maskarita = 1;
		for(int j=0;j<val;j++){
			if(mask & (1<<j)){
				maskarita *= v[j];
				maskarita %= m;
			}
		}
		maskarita %= m;
		if(maskarita == x) ans++;
		X[maskarita]++;
	}
	for(ll mask=1;mask<(1<<n-val);mask++){
		ll maskarita = 1;
		for(int j=0;j<n-val;j++){
			if(mask&(1<<j)){
				maskarita *= v[j+val];
				maskarita %= m;
			}
		}
		maskarita %= m;
		if(maskarita == x) ans++;
		ans += get(maskarita);
	}
	cout<<ans<<'\n';

	return 0;
}

