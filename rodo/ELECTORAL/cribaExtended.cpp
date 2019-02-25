#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = (5e6);

ll f[N+2];

void init(){
	for(ll i=2;i*i<=N;i++){
		if(!f[i]) for(ll j=i*i;j<=N;j+=i) f[j]=i;
	}
	for(ll i=2;i<=N;i++) if(!f[i]) f[i]=i;
}

ll ans = 0;
void update(ll x){
	while(x>1){
		ll div = f[x];
		while(x%div==0){
			ans++;
			x/=div;
		}
	}
}

ll res[N+2];

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	init();
	for(ll i=1;i<=N;i++){
		update(i);
		res[i] = ans;
	}
	int t;cin>>t;
	int a,b;
	while(t--){
		cin>>a>>b;
		cout<<res[a]-res[b]<<'\n';
	}

	return 0;
}

