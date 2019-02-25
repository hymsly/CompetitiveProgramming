#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=(1e5);
const ll INF=(1e18);

vector<int> G[N+5];
vector<ll> C[N+5];
vector<ll> d;
ll n,k,x,s,m;
void xd(int start){
	d.resize(n+1);
	for(int i=1;i<=n;i++){
		d[i] = INF;
	}
	d[start]=0;
	priority_queue<int> Q;
	Q.push(start);
	int ok=n-k;
	while(!Q.empty()){
		int p = Q.top();
		Q.pop();
		for(int i=0;i<G[p].size();i++){
			int pp = G[p][i];
			if(d[pp] > d[p] + C[p][i] ){
				d[pp] = d[p] + C[p][i];
				Q.push(pp);
			}
		}
	}
	ll mini=INF;
	for(int i=1;i<=k;i++){
		mini=min(mini,d[i]);
	}
	for(int i=k+1;i<=n;i++){
		d[i] = min(d[i] , mini + x);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n>>k>>x>>m>>s;
		for(int i=1;i<=N;i++){
			G[i].clear();
			C[i].clear();
		}
		int a,b;ll c;
		/*for(int i=1;i<=k;i++){
			for(int j=i+1;j<=k;j++){
				G[i].pb(j);
				G[j].pb(i);
				C[i].pb(x);
				C[j].pb(x);
			}
		}*/
		while(m--){
			cin>>a>>b>>c;
			G[a].push_back(b);
			G[b].push_back(a);
			C[a].push_back(c);
			C[b].push_back(c);
		}
		xd(s);
		for(int i=1;i<=n;i++){
			cout<<d[i]<<(char)(i==n?10:32);
		}
	}
	
	return 0;
}

