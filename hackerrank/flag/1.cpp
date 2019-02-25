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
string a,b;
bool memo[1005][1005][2];
bool used[1005][1005][2];

bool dp(int pos1,int pos2,int flag){
	if(pos2==b.size() && pos1==a.size()) return true;
	if(pos1==a.size()) return false;
	if(used[pos1][pos2][flag]) return memo[pos1][pos2][flag];
	bool &ans = memo[pos1][pos2][flag];
	if(pos2<b.size()){
		if(a[pos1] == b[pos2] || a[pos1] - 32 == b[pos2]){
			ans |= dp(pos1+1,pos2+1,1);
		}
	}
	if(flag){
		if((int) a[pos1] >=65 && (int) a[pos1] <= 90) ans |= false;
		else ans |= dp(pos1+1,pos2,flag);
	}else ans |= dp(pos1+1,pos2,flag);
	used[pos1][pos2][flag] = 1;
	
	return ans;
}

int main(){
	//fast_io()
	int t;cin>>t;
	while(t--){
		memset(used,0,sizeof(used));
		memset(memo,0,sizeof(memo));
		cin>>a>>b;
		if(dp(0,0,0)){
			cout<<"YES\n";	
		}else cout<<"NO\n";
	}
	
	return 0;
}

