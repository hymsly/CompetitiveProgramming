#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = (2e18);


ll M[35];
ll memo[35];

void init(){
	for(int i=0;i<32;i++){
		M[i] = INF;
	}
	memset(memo,-1,sizeof memo);
}

vector<int> v;

bool need[35];

void f(ll x){
	for(int i=0;i<32;i++){
		if(x & (1<<i)) need[i] = true;
	}
}


ll dp(int pos){
	if(pos<0) return 0;
	if(memo[pos] != -1) return memo[pos];
	ll &ans = memo[pos] = 0;
	if(need[pos]){
		ans = dp(pos-1) + M[pos];
	}else{
		ans = min(dp(pos-1), M[pos]);
	}
	return ans;
}

int main(){
	init();
	ll val;
	int n;cin>>n>>val;
	ll num;
	for(int i=0;i<n;i++){
		cin>>num;
		for(int j=i;j<32;j++){
			M[j] = min(M[j],num);
			num <<=1;	
		}
	}
	f(val);
	ll ans = dp(31);
	cout<<ans<<endl;

	return 0;
}

