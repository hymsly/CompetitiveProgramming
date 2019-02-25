#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool same(char x,char y){
	if(x<='f' && y<='f') return true;
	if(x>'f' && y>'f') return true;
	return false;
}

map<string,ll> memo;

ll f(string s){
	if(memo.count(s)) return memo[s]/2;
	ll ans = 2;
	for(int i=1;i<s.size();i++){
		if(same(s[i-1],s[i]))ans+=4;
		else ans+=2;
	}
	memo[s]=ans;
	return ans;
}

void solve(){
	memo.clear();
	int n;cin>>n;
	ll ans = 0;
	string s;
	while(n--) cin>>s,ans+=f(s);
	cout<<ans<<'\n';
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

