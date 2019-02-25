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
ll memo[5005];

ll dp(int pos){
	if(pos==n) return 1;
	if(pos>n) return 0;
	if(memo[pos]) return memo[pos];
	ll &ans = memo[pos] = 0;
	ans += dp(pos+1);
	ans += 4*dp(pos+2);
	for(int i=pos+3;i<=n;i++){
		ans += dp(i)*((pos-i)&1?2:3);
	}
	return ans;
}

int main(){
	//fast_io()
	int t;cin>>t;
	for(int test=1;test<=t;test++){
		cin>>n;
		memset(memo,0,sizeof(memo));
		cout<<test<<" "<<dp(0)<<endl;
	}
	
	return 0;
}

