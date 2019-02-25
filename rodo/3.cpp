#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(x) push_back(x)

#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
#define fi first
#define se second
#define sz(v) ((int)v.size())
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
int n;
ll memo[35];

ll dp(int pos){
	if(pos==n) return 1;
	if(memo[pos]) return memo[pos];
	ll &ans = memo[pos] = 0;
	for(int i=pos+2;i<=n;i+=2){
		ans += dp(i)*(i-pos>2?2:3);
	}
	return ans;
}

int main(){
	//fast_io()
	while(cin>>n){
		if(n==-1) break;
		memset(memo,0,sizeof(memo));
		cout<<dp(0)<<endl;
	}
	
	return 0;
}

