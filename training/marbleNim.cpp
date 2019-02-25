#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (10000);
ll memo[102][102];
ll dp(int x,int y){
	if(x==0 || y==0 || x==y) return INF;
	if(memo[x][y] != -1) return memo[x][y];
	int u = max(x,y);
	set<ll> S;
	for(int i=1;i<=u;i++){
		if(x>=i) S.insert(dp(x-i,y));
		if(x>=i && y>=i) S.insert(dp(x-i,y-i));
		if(y>=i) S.insert(dp(x,y-i));
	}
	ll &ans = memo[x][y] = 0;
	while(S.find(ans)!=S.end()) ans++;
	return ans;
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	memset(memo,-1,sizeof memo);
	int n;cin>>n;
	int a,b;
	int nim = 0;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		if(a==b){
			cout<<"Y\n";
			return 0;
		}
		nim^=dp(a,b);
	}
	if(nim==0) cout<<"N\n";
	else cout<<"Y\n";

	return 0;
}

