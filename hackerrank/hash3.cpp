#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD1 = (1e9+7);
const ll MOD2 = (1e9+9);
const int B = 29;
ll hpref[200005];
ll pot[200005];
ll hpref2[200005];
ll pot2[200005];
ll sumpref[200005];
ll multpref[200005];
ll multpref2[200005];

void init(){
	pot[0] = 1;
	for(int i=1;i<=200000;i++) pot[i]=(pot[i-1]*B)%MOD1;
	pot2[0] = 1;
	for(int i=1;i<=200000;i++) pot2[i]=(pot2[i-1]*B)%MOD2;
}

void getSumMult(string s){
	memset(sumpref,0,sizeof sumpref);
	memset(multpref,0,sizeof multpref);
	memset(multpref2,0,sizeof multpref2);
	sumpref[0] = (s[0] - 'a' + 1);
	multpref[0] = (s[0] - 'a' + 1);
	multpref2[0] = (s[0] - 'a' + 1);
	for(int i=1;i<s.size();i++){
		sumpref[i] = (sumpref[i-1] + (s[i]-'a'+1))%MOD1;
		multpref[i] = (multpref[i-1] * (s[i]-'a'+1))%MOD1;
		multpref2[i] = (multpref2[i-1] * (s[i]-'a'+1))%MOD2;
	}
}

ll POT(ll x,ll y,ll mod){
	if(y==0) return 1;
	if(y==1) return x;
	ll ans = 1;
	if(y&1) ans = x;
	ll val = POT(x,y/2,mod);
	ans *= val;
	ans %= mod;
	ans *= val;
	ans %= mod;
	return ans;
}

ll inv(ll x,ll mod){
	return POT(x,mod-2,mod);
}

ll subsum(int i,int j){
	if(i==0) return sumpref[j];
	return ((sumpref[j] - sumpref[i-1])%MOD1 + MOD1)%MOD1;
}


ll submult(int i,int j){
	if(i==0) return multpref[j];
	return (multpref[j] * inv(multpref[i-1],MOD1))%MOD1;
}

ll submult2(int i,int j){
	if(i==0) return multpref2[j];
	return (multpref2[j] * inv(multpref2[i-1],MOD2))%MOD2;
}

void getpref(string s){
	memset(hpref,0,sizeof hpref);
	hpref[0] = (s[0] - 'a' + 1);
	for(int i=1;i<s.size();i++){
		hpref[i] = (hpref[i-1]*B + (s[i]-'a'+1))%MOD1;
	}
	memset(hpref2,0,sizeof hpref2);
	hpref2[0] = (s[0] - 'a' + 1);
	for(int i=1;i<s.size();i++){
		hpref2[i] = (hpref2[i-1]*B + (s[i]-'a'+1))%MOD2;
	}
}

ll hsub(int i,int j){
	if(i==0) return hpref[j];
	return ((hpref[j] - hpref[i-1]*pot[j-i+1])%MOD1 + MOD1)%MOD1;
}

ll hsub2(int i,int j){
	if(i==0) return hpref2[j];
	return ((hpref2[j] - hpref2[i-1]*pot2[j-i+1])%MOD2 + MOD2)%MOD2;
}

map<pair<ll,ll>,int> M;

int ans[200005];

int main(){
	init();
	int t;cin>>t;
	string a,b;
	while(t--){
		cin>>a>>b;
		M.clear();
		memset(ans,0,sizeof ans);
		getpref(b);
		getSumMult(b);
		ll sum=0,mult=1,mult2=1;
		for(int i=0;i<a.size();i++){
			sum += (a[i]-'a'+1);
			mult *= (a[i]-'a'+1);
			mult %= MOD1;
			mult2 *= (a[i]-'a'+1);
			mult2 %= MOD2;
		}
		for(int i=0;i<=b.size()-a.size();i++){
			ll val1 = hsub(i,i+a.size()-1);
			ll val2 = hsub2(i,i+a.size()-1);
			if(subsum(i,i+a.size()-1)==sum && submult(i,i+a.size()-1)==mult && submult2(i,i+a.size()-1)==mult2){
				pair<ll,ll> p = make_pair(val1,val2);
				if(M.count(p)){
					ans[M[p]]++;
				}else{
					M[p] = i;
					ans[i]++;
				}
			}
		}
		int maxi = 0;
		vector<int> v;
		for(int i=0;i<=b.size();i++){
			if(ans[i] > maxi){
				v.clear();
				v.push_back(i);
				maxi = ans[i];
			}else if(ans[i] == maxi){
				v.push_back(i);
			}
		}
		if(maxi == 0) cout<<"-1\n";
		else{
			string res = b.substr(v[0],a.size());
			for(int i=1;i<v.size();i++){
				res = min(res,b.substr(v[i],a.size()));
			}
			cout<<res<<'\n';
		}
	}

	return 0;
}

