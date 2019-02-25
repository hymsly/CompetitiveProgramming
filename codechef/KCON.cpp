#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = (1e5);
const ll INF = (1e18);

ll M[2*N+2];

ll f(int n){
	ll ans = -INF;
	ll last = 0;
	ll mini = 0;
	for(int i=1;i<=n;i++){
		last += M[i];
		ans = max(ans,last - mini);
		mini = min(mini,last);
	}
	return ans;
}

int main(){
	int t;cin>>t;
	int n,k;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>M[i];
		ll ans = -INF;
		ans = max(ans,f(n));
		if(k>1){
			ll val = 0;
			for(int i=1;i<=n;i++) val+=M[i];
			for(int i=1;i<=n;i++) M[n+i] = M[i];
			ll newval = f(2*n);
			if(val < 0){
				ans = max(ans,newval);
			}else{
				ans = max(ans,(k-2)*val + newval);
			}
		}
		cout<<ans<<'\n';
	}

	return 0;
}

