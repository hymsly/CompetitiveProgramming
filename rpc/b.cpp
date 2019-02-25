#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (1e18);
const int N = (500);
int n,m;
ll ve;

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

ll bfs(int src,int dst){
	vector<ll> d(n,INF);
	d[src] = 0;	
	priority_queue<Node> Q;
	Q.push(Node(src,0));
	while(!Q.empty()){
		Node a = Q.top();
		Q.pop();
		for(int i=0;i<G[a.u].size();i++){
			int v = G[a.u][i];
			ll w = C[a.u][i];
			if(d[v] > d[a.u] + w){
				d[v] = d[a.u] + w;
				Q.push(Node(v,d[v]));
			}
		}
	}
	return d[dst];
}

int main(){
	while(cin>>n>>m){
		int a,b;cin>>a>>b;
		for(int i=0;i<n;i++) G[i].clear(),C[i].clear();
		ll c;
		ve = a+b;
		for(int i=0;i<m;i++){
			cin>>a>>b>>c;
			a--;
			b--;
			G[a].push_back(b);
			G[b].push_back(a);
			C[a].push_back(c);
			C[b].push_back(c);
		}
		int src,dst;
		cin>>src>>dst;
		ll len = bfs(src-1,dst-1);
		printf("%.2f\n",(double)len/(double)ve);
	}

	return 0;
}

