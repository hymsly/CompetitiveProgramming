#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
ll M[26];

map<pair<int,ll>,ll> memo;

ll dp(int pos,ll sobra){
	if(pos==26) return 0;
	pair<int,ll> p=make_pair(pos,sobra); 
	if(memo.count(p)) return memo[p];
	ll &ans = memo[p] = dp(pos+1,sobra+M[pos]);
	ans = max(ans , min(M[pos],sobra) + dp(pos+1,abs(M[pos]-sobra)));
	return ans;
}

void solve() {
    for(int i=0;i<26;i++) cin>>M[i];
    for(int i=0;i<26;i++){
        if(M[i]>0){
            M[i]--;
            break;
        }
    }
    memo.clear();
	ll ans = dp(0,0);
	cout<<ans<<'\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
    int t;cin>>t;
    while(t--) solve();

    return 0;
}
