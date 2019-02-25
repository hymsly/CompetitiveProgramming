#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

map<pair<ll,int>,ll> memo;
vector<ll> v;

ll dp(ll x,int pos){
	if(pos==v.size()){
		if(x) return 1LL;
		else return 0LL;
	}
	pair<ll,int> p = make_pair(x,pos); 
	if(memo.find(p) != memo.end()) return memo[p];
	ll ans = 0;
	if(x>0) ans = dp(x/v[pos],pos+1)+dp(x,pos+1);
	memo[p] = ans;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	int n;
	ll k;
	cin>>n>>k;
	v.resize(n);
	for(int i=0;i<n;i++) cin>>v[i];
	sort(v.begin(),v.end());
	
	cout<<dp(k,0)-1<<endl;
	
	return 0;
}

