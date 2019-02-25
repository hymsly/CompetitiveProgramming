#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n;cin>>n;
	vector<ll> v(n);
	vector<ll>acum(n);
	for(int i=0;i<n;i++) cin>>v[i];
	if(n==1){
		cout<<1<<'\n';
		return;
	}
	for(int i=0;i<n;i++){
		if(i>0)acum[i]=acum[i-1]+v[i];
		else acum[i]=v[i];
	}
	ll pos = 0;
	ll ans = 0;
	while(pos<n-1){
		ll p = acum[pos];
		pos+=p;
		ans++;
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

