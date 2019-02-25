#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
typedef long long ll;
const ll T = (86400);
const ll INF = (1e12);
const int N = 1000;
ll memo[T+2][1024];

struct music{
	ll i,f,o;
	int type;
	music(){}
} A[N+2];
vector<ll> inis;
vector<ll> g[N+2];
int n;
ll dp(int time,ll mask){
	if(time==inis.size()){
		if(mask+1==(1<<n)) return 0LL;
		return -INF;
	}
	if(memo[time][mask] != -1) return memo[time][mask];
	ll &ans = memo[time][mask] = dp(time+1,mask);
	for(int i=0;i<g[time].size();i++){
		music &cur = A[g[time][i]];
		int p = lower_bound(inis.begin(),inis.end(),cur.f) - inis.begin();
		ans = max(ans,dp(p,mask|(1<<cur.type)) + cur.o);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	memset(memo,-1,sizeof memo);
	cin>>n;
	int pos=0;
	set<ll> ini;
	for(int i=0;i<n;i++){
		int t;cin>>t;
		while(t--){
			cin>>A[pos].i>>A[pos].f>>A[pos].o;
			ini.insert(A[pos].i);
			A[pos].type = i;
			pos++;
		}
	}
	set<ll> :: iterator it;
	for(it=ini.begin();it!=ini.end();it++) inis.push_back((*it));
	for(int i=0;i<pos;i++){
		int p = lower_bound(inis.begin(),inis.end(),A[i].i)-inis.begin();
		g[p].push_back(i);
	}
	ll ans = dp(0,0);
	cout<<(ans<0?-1:ans)<<'\n';

	return 0;
}

