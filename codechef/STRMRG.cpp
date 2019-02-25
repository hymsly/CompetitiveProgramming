#include<bits/stdc++.h>

using namespace std;
const int INF = (100000);
string a,b;
int n,m;
int memo[5005][5005][2];
void clear(){
	for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) for(int k=0;k<2;k++) memo[i][j][k] = -1;
}

int dp(int pos1,int pos2,bool p){//if p is true: string b else string a
	if(pos1==n && pos2==m) return 0;
	if(memo[pos1][pos2][p] != -1) return memo[pos1][pos2][p];
	int &ans = memo[pos1][pos2][p] = INF;
	if(pos2 < m) ans = min(ans,(b[pos2] != (p?b[pos2-1]:a[pos1-1])) + dp(pos1,pos2+1,1));
	if(pos1 < n) ans = min(ans,(a[pos1] != (p?b[pos2-1]:a[pos1-1])) + dp(pos1+1,pos2,0));
	return ans;
}

int main(){
	int t;cin>>t;
	while(t--){
		cin>>n>>m;
		clear();
		cin>>a>>b;
		int ans = 1+min(dp(0,1,1),dp(1,0,0));
		cout<<ans<<endl;
	}

	return 0;
}

