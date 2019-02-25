#include<bits/stdc++.h>

using namespace std;
int n;

vector<int> G[102];
set<int> memo[102];

void clear(){
	for(int i=0;i<=100;i++) G[i].clear();
	for(int i=0;i<=100;i++) memo[i].clear();
}

set<int> dp(int x){
	if(memo[x].size()) return memo[x];
	set<int> &ans = memo[x];
	ans.insert(x);
	for(int i=0;i<G[x].size();i++){
		set<int> val = dp(G[x][i]);
		set<int> :: iterator it;
		for(it=val.begin();it!=val.end();it++){
			ans.insert(*it);
		}
	}
	return ans;
}

void solve(){
	int cnt;
	for(int i=1;i<=n;i++){
		cin>>cnt;
		int num;
		while(cnt--){
			cin>>num;
			G[i].push_back(num);
		}
	}
	int ans=-1,maxi=0;
	for(int i=1;i<=n;i++){
		if(dp(i).size()>maxi){
			ans = i;
			maxi = dp(i).size();
		}		
	}
	cout<<ans<<'\n';
}

int main(){
	while(cin>>n){
		if(n==0) break;
		clear();
		solve();
	}

	return 0;
}

