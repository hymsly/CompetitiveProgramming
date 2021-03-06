#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (1e5);
const ll INF = (1e15);
int n,f;
bool F[N+2];
int D[N+2];
ll C[N+2];

struct Node{
	int u;
	vector< ll > costo;//[hijo,costo del hijo]
	vector< int > hijos;
	bool hasToVisited;
	Node(){}
	Node(int _u){
		u = _u;
		costo.clear();
		hijos.clear();
		hasToVisited = false;
	}
	void show(){
		cout<<u<<endl;
		for(int i=0;i<costo.size();i++) cout<<hijos[i]<<" -> "<<costo[i]<<endl;
	}
};

Node G[N+2];
vector<int> tree[N+2];
void calc(int x){
	bool &hasTo = G[x].hasToVisited = false;
	if(F[x]) hasTo=true; 
	for(int i=0;i<tree[x].size();i++)calc(tree[x][i]);
	for(int i=0;i<tree[x].size();i++) hasTo|=G[tree[x][i]].hasToVisited;
	for(int i=0;i<tree[x].size();i++){
		int hijo = tree[x][i];
		vector<ll> &costoHijo = G[hijo].costo;
		vector<int> &hijosHijo = G[hijo].hijos;
		ll tot = accumulate(costoHijo.begin(),costoHijo.end(),0LL);
		if(G[hijo].hasToVisited) G[x].hijos.push_back(hijo),G[x].costo.push_back(tot + C[hijo]);
		else G[x].hijos.push_back(hijo),G[x].costo.push_back(tot);
	}
}

ll memo[N+2];

ll dp(int x){
	if(memo[x] != -1) return memo[x];
	Node &cur = G[x];
	ll &ans = memo[x] = INF;
	ll total = accumulate(cur.costo.begin(),cur.costo.end(),0LL);
	for(int i=0;i<cur.hijos.size();i++){
		if(cur.hijos[i]==x) continue;
		ans = min(ans,dp(cur.hijos[i]) + total -  cur.costo[i]);
	}
	if(ans==INF) ans = 0;
	return ans;
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	while(cin>>n>>f){
		memset(D,-1,sizeof D);
		memset(C,0,sizeof C);
		memset(F,0,sizeof F);
		memset(memo,-1,sizeof memo);
		for(int i=1;i<=n;i++) G[i] = Node(i),tree[i].clear();
		int a,b,c;
		for(int i=1;i<n;i++){
			cin>>a>>b>>c;
			tree[a].push_back(b);
			C[b] = c;
			D[b] = a;
		}
		for(int i=0;i<f;i++){
			cin>>a;
			F[a] = 1;
		}
		calc(1);
		//for(int i=1;i<=n;i++) G[i].show();
		ll ans = dp(1);
		cout<<ans<<'\n';
	}

	return 0;
}

