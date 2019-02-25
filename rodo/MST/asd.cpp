#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = (1e9+7);
ll n,k;
ll minimo(ll ini,ll cnt){
	return (2*ini+cnt-1)*cnt/2;
}

ll get(ll tot,ll cnt){
	ll lo=0,hi=(1e8);
	while((hi-lo)>1){
		ll mi = (hi+lo)/2;
		if(minimo(mi,cnt)>tot) hi=mi;
		else lo=mi;
	}
	return lo;
}

void solve(){
	cin>>n>>k;
	ll ans = 1;
	ll mini = k*(k+1)/2;
	if(mini>n) cout<<"-1\n";
	else if(mini==n) cout<<0<<'\n';
	else{
		for(int i=0;i<k;i++){
			ll val = get(n,k-i);
			n-=val;
			ans *= (val);
			ans %= MOD;
			ans *= (val-1);
			ans %= MOD;
		}
	} 
	cout<<ans<<'\n';
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

