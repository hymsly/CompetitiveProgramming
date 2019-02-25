#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=(1e6);
ll mod;
ll F[N+5];
vector<ll> pr;
vector<ll> ex;
typedef pair< ll,pair<ll,ll> > tup;


ll f(ll x,ll y){
	ll ans=0;
	while(x){
		ans+=(x/y);
		x/=y;
	}
	return ans;
}

ll pot(ll x,ll y){
	if(y==0) return 1LL;
	if(y==1) return x;
	ll ans=1;
	if(y&1) ans*=x;
	ll val = pot(x,y/2);
	ans*=val;
	ans%=mod;
	ans*=val;
	ans%=mod;
	return ans;
}

tup extGcd(ll a,ll b){
	if(b==0) return make_pair(a,make_pair(1,0));
	tup ret = extGcd(b,a%b);
	return make_pair(ret.first, make_pair(ret.second.second, ret.second.first - (a/b)*ret.second.second));
}


ll inv(ll x){
	tup t= extGcd(x,mod);
	ll inver = ((t.second.first%mod) + mod)%mod;
	return inver;
}

ll wilson(ll x){
	//complete x!%mod;
	return F[x]%mod;
}

ll fact(ll x){
	if(x==0) return 1LL;
	ll rep = x/mod;
	ll ans = pot(F[mod-1],rep);
	ans *= wilson(x%mod);
	ans%=mod;
	return ans;
}

ll C(ll x,ll y){
	vector<ll> canti(pr.size());
	for(int i=0;i<pr.size();i++){
		canti[i] = f(x,pr[i]) - f(x-y,pr[i]) - f(y,pr[i]);
	}
	ll is=(1e18);
	for(int i=0;i<canti.size();i++){
		is = min(is,canti[i]/ex[i]);
	}
	if(is>0){
		return 0LL;
	}else{
		ll ans = 1;
		for(int i=0;i<canti.size();i++){
			ans*= pot(pr[i],canti[i]);
			ans%=mod;
		}
		ans *= fact(x);
		ans%=mod;
		ans *= inv(fact(y));
		ans%=mod;
		ans *= inv(fact(x-y));
		ans%=mod;
		return ans;
	}
}

ll modi(ll x){
	for(int i=0;i<pr.size();i++){
		while(x%pr[i]==0) x/=pr[i];
	}
	return x;
}

void doit(){
	memset(F,0,sizeof(F));
	F[0]=1;
	for(ll i=1;i<mod;i++){
		F[i]=(modi(i))*F[i-1];
		F[i]%=mod;
	}
}

void getExp(ll x){
	for(ll i=2;i*i<=x;i++){
		ll cnt=0;
		while(x%i==0) cnt++,x/=i;
		if(cnt) pr.push_back(i),ex.push_back(cnt);
	}
	if(x>1){
		pr.push_back(x);ex.push_back(1);
	}
}

int main(){
	//fast_io()
	int t;cin>>t;
	ll n,k;
	while(t--){
		pr.clear();
		ex.clear();
		cin>>n>>k>>mod;
		ll p=n/k + (n%k>0),q=p*k-n;
		getExp(mod);
		doit();
		cout<<p<<" "<<C(p+q-1,q)<<endl;
	}
	
	return 0;
}

