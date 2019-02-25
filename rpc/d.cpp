#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (1e18);
const ll MOD = (1e9+7);
const int N = (1e5);

int n,m;
vector<int> G[N+2];
vector<ll> C[N+2];

struct Node{
	int u;ll w;
	Node(){}
	Node(int _u,ll _w){
		u = _u;
		w = _w;
	}
};

bool operator <(const Node a,const Node b){
	return a.w>b.w;
}

ll D[N+2];

ll bfs(int src,int dst){
	for(int i=0;i<n;i++) D[i] = INF;
	D[src] = 0;
	priority_queue< Node > Q;
	Q.push(Node(src,0));
	while(!Q.empty()){
		Node p = Q.top();
		Q.pop();
		for(int i=0;i<G[p.u].size();i++){
			int v = G[p.u][i];
			ll w = C[p.u][i];
			if(D[v] > D[p.u] + w){
				D[v] = D[p.u] + w;
				Q.push(Node(v,D[v]));
			}
		}
	}
	return D[dst];
}

ll memo[N+2];

ll dp(int src){
	if(src+1==n) return 1LL;
	if(memo[src] != -1) return memo[src];
	ll &ans = memo[src] = 0;
	for(int i=0;i<G[src].size();i++){
		int v = G[src][i];
		if(D[v] + C[src][i] == D[src]){
			ans += dp(v);
			ans %= MOD;
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	while(cin>>n>>m){
		int a,b;ll c;
		for(int i=0;i<n;i++) memo[i] = -1;
		for(int i=0;i<n;i++) G[i].clear(),C[i].clear();
		for(int i=0;i<m;i++){
			cin>>a>>b>>c;
			G[a].push_back(b);
			G[b].push_back(a);
			C[a].push_back(c);
			C[b].push_back(c);
		}
		ll minimunPath = bfs(0,n-1);
		bfs(n-1,n-1);
		ll ways = dp(0);
		cout<<minimunPath<<" "<<ways<<'\n';
	}

	return 0;
}

