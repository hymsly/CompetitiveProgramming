#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d;

map<ll,ll> M;
ll digit(ll x){
	ll ans = 0;
	while(x){
		ans+=(x%10);
		x/=10;
	}
	return ans;
}

ll bfs(ll ini,ll suma,ll goal){
	M.clear();
	M[ini] = 0;
	queue<ll> Q;
	Q.push(ini);
	while(!Q.empty()){
		ll p = Q.front();
		if(p==goal) return M[p];
		Q.pop();
		ll q = digit(p);
		if(!M.count(q)){
			M[q] = M[p]+1;
			Q.push(q);
		}
		ll qq = p+suma;
		if(!M.count(qq)){
			M[qq] = M[p]+1;
			Q.push(qq);
		}
	}
}

void solve(){
	cin>>n>>d;
	ll f = n%9;
	ll goal = 9;
	for(int i=0;i<9;i++){
		ll val = f+d*i;
		val%=9;
		goal = min(goal,(val==0?9:val));
	}
	cout<<goal<<" "<<bfs(n,d,goal)<<'\n';
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

