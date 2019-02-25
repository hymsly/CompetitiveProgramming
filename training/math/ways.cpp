#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (1e7);


int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	ll n,k;
	while(cin>>n>>k){
		//cout<<ans<<endl;
		ld ans = 0.0L;
		if ( k > n - k ) {
            for ( ll i = k + 1; i <= n; i++ )
                ans += (log10 (i) - log10 (n - i + 1));
        }
        else {
            for ( ll i = n - k + 1; i <= n; i++ )
                ans += (log10 (i) - log10 (n - i + 1));
        }
		ll res = (ll) floor(ans);
		cout<<res+1<<'\n';
	}

	return 0;
}

