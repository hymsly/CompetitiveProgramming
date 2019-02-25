#include<bits/stdc++.h>

using namespace std;
const int N = 100;

int M[N+5][N+5];

int memo[N+5][N+5];
int dp(int x,int y){
	if(x>N) return 0;
	if(memo[x][y] != -1) return memo[x][y];
	int &ans = memo[x][y] = M[x][y];
	ans += max(dp(x+1,y),dp(x+1,y+1));
	return ans;
}

int main(){
	memset(memo,-1,sizeof(memo));
	for(int i=1;i<=N;i++){
		for(int j=1;j<=i;j++) cin>>M[i][j];
	}
	cout<<dp(1,1)<<endl;

	return 0;
}

