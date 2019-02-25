#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = (1e12);

ll d[55];
ll memo[55][55];

ll dp(int lo,int hi){
	if(hi==lo+1) return 0;
	if(memo[lo][hi] != -1) return memo[lo][hi];
	ll &ans = memo[lo][hi] = INF;
	for(int i=lo+1;i<hi;i++){
		ans = min(d[hi]-d[lo] + dp(lo,i) + dp(i,hi),ans);
	}
	return ans;
}

int main(){
	ll l;
	while(cin>>l){
		if(l==0) break;
		int n;
		cin>>n;
		memset(memo,-1,sizeof memo);
		for(int i=1;i<=n;i++){
			cin>>d[i];
		}
		d[n+1] = l;
		cout<<"The minimum cutting is "<<dp(0,n+1)<<".\n";
	}

	return 0;
}

