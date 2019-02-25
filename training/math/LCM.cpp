#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> pr,ex,divi;

ll n;

ll lcm(ll x,ll y){
	ll gcd = __gcd(x,y);
	return ((x/gcd) * y);
}

void fact(ll x){
	pr.clear();ex.clear();
	divi.clear();
	for(ll i=2;i*i<=x;i++){
		ll cnt = 0;
		while(x%i==0){
			cnt++;
			x/=i;
		}
		if(cnt){
			pr.push_back(i);
			ex.push_back(cnt);
		}
	}
	if(x>1){
		pr.push_back(x);
		ex.push_back(1);
	}
	divi.push_back(1LL);
	for(int i=0;i<pr.size();i++){
		ll val = 1;
		int len = divi.size();
		for(int j=0;j<ex[i];j++){
			val*=pr[i];
			for(int k=0;k<len;k++) divi.push_back(val*divi[k]);
		}
	}
	
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	while(cin>>n){
		if(n==0) break;
		fact(n);
		int len = divi.size();
		ll ans = 0;
		for(int i=0;i<divi.size();i++){
			for(int j=i;j<divi.size();j++){
				if(lcm(divi[i],divi[j])==n) ans++;
			}
		}
		cout<<n<<" "<<ans<<'\n';
	}

	return 0;
}

