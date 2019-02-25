#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A[20];

ll ok[(1<<18)];

ll tot;

ll C(ll x){
	ll ans = 1;
	for(int i=0;i<x;i++) ans*=3;
	return ans;
}

ll memo[(1<<17)][3];

ll dp(ll mask,int pos){
	if(pos==3) return (mask==0);
	if(memo[mask][pos] != -1) return memo[mask][pos];
	ll &ans = memo[mask][pos] = 0;
	for(int i=mask;i>0;i=(i-1)&mask){
		ans += dp(mask^i,pos+1);
    }
    return ans;
}

int main(){
    int n;cin>>n;
    int zero=0;
    for(int i=0;i<n;i++){
		cin>>A[i];
		if(A[i]==0){
			zero++;
			i--;
			n--;
		}
	}
    ll valor = C(zero);
    if(n==0){
    	memset(memo,-1,sizeof memo);
		cout<<dp((1<<zero)-1,0)<<'\n';
		return 0;
	}
	for(int i=0;i<n;i++) tot+=A[i];
    ll ans = 0;
    vector<ll> can;
    for(ll mask=0;mask<(1<<n);mask++){
        ll cnt=0;
        for(int j=0;j<n;j++){
            if(mask & (1<<j)) cnt+=A[j];
        }
        if(cnt*3==tot){
            can.push_back(mask);
            ok[mask] = 1;
        }
    }
    int len = can.size();
	for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            ll p = can[i] & can[j];
			if(!p){
                ll need = (1<<n) - 1 - can[i] - can[j];
                if(ok[need]){
                    ans+=valor;
                }
            }
        }
    }
    cout<<ans<<'\n';

    return 0;
}

