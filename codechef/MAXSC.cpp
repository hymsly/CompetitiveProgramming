#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = (1e18);
int n;
ll M[705][705];

ll f(int pos,ll val){
	if(pos==1) return 0;
	pos--;
	ll newval = 0;
	for(int i=1;i<=n;i++){
		if(M[pos][i] >= val) break;
		newval = M[pos][i];
	}
	if(newval==0) return -INF;
	return newval+f(pos,newval);
}

int main(){
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) cin>>M[i][j];
		}
		for(int i=1;i<=n;i++) sort(M[i]+1,M[i]+1+n);
		ll ans = f(n+1,INF);
		if(ans <= 0) ans = -1;
		cout<<ans<<'\n';
	}

	return 0;
}

