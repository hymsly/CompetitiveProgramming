#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = (1e9+7);
const int N=(1000);
int caso;
ll ans;
int n;

ll memo[3][N+2];
int M[3][N+2];

ll dp(int x,int y){
	if(y==n) return (x==2);
	if(M[x][y]==0) return 0;
	if(memo[x][y] != -1) return memo[x][y];
	ll &ans = memo[x][y] = 0;
	if(x>0 && M[x-1][y]!=0) ans += dp(x-1,y+1);
	if(x<2 && M[x+1][y]!=0) ans += dp(x+1,y+1);
	ans %= MOD;
	return ans;
}

void solve(){
	cin>>n;
	memset(memo,-1,sizeof memo);
	memset(M,1,sizeof M);
	string s;
	for(int i=0;i<3;i++){
		cin>>s;
		for(int j=0;j<n;j++){
			if(s[j]=='#') M[i][j]=0;
			else M[i][j]=1;
		}
	}
	if(n%2==0) ans = dp(0,0);
	cout<<"Case #"<<++caso<<": "<<ans<<'\n';
}

int main(){
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

