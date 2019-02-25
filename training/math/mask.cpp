#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	
	while(t--){
		ll n;
		vector<ll> v;
		cin>>n;
		int len;cin>>len;
		v.resize(len);
		for(int i=0;i<len;i++) cin>>v[i];
		ll ans = n;
		for(ll mask = 0;mask<(1<<len);mask++){
			int cnt = 0;
			ll val = 1;
			for(int j=0;j<len;j++){
				if(mask & (1<<j)) cnt++,val*=v[j];
			}
			if(cnt%2==0) ans -= 2*(n/val);
			else ans += 2*(n/val);
		}
		cout<<ans<<'\n';
	}

	return 0;
}

