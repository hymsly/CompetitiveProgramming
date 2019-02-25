#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (3e5);
const ll INF = (1e16);
struct edge{
	int to,id;
	ll c;
	edge(){}
	edge(int _to,ll _c,int _id){
		to = _to;
		c = _c;
		id = _id;
	}
};
struct Node{
	int u;ll w;
	Node(){}
	Node(int _u,ll _w){
		u = _u;
		w = _w;
	}
};
bool arb[N+2];

ll D[N+2];
int last[N+2];
int n;

bool operator <(const Node &a,const Node &b){
	return a.w>b.w;
}

vector<edge> G[N+2];
ll costos[N+2];
void dijkstra(int src){
	fill(D+1,D+n+1,INF);
	D[src] = 0;
	priority_queue<Node> Q;
	Q.push(Node(src,0));
	while(!Q.empty()){
		Node a = Q.top();
		Q.pop();
		for(int i=0;i<G[a.u].size();i++){
			edge &cur = G[a.u][i];
			ll cost = cur.c;
			ll dst = cur.to;
			int id = cur.id;
			if(D[dst] > cost + D[a.u]){
				D[dst] = cost+D[a.u];
				arb[last[dst]] = 0;
				arb[id] = 1;
				last[dst] = id;
				Q.push(Node(dst,D[dst]));
			}else if((D[dst] == cost + D[a.u]) && costos[last[dst]]>cost){
				arb[last[dst]] = 0;
				arb[id] = 1;
				last[dst] = id;
			}
		}
	}
}


int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int m;cin>>n>>m;
	int a,b;ll c;
	costos[0] = INF;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		G[a].push_back(edge(b,c,i));
		G[b].push_back(edge(a,c,i));
		costos[i] = c;
	}
	int src;cin>>src;
	dijkstra(src);
	ll suma = 0;
	vector<int> arbol;
	for(int i=1;i<=m;i++) if(arb[i]) arbol.push_back(i);
	for(int i=1;i<=n;i++){
		for(int j=0;j<G[i].size();j++){
			edge &cur = G[i][j];
			if(arb[cur.id]) suma+=cur.c;
		}
	}
	suma /= 2;
	cout<<suma<<"\n";
	for(int i=0;i<arbol.size();i++) cout<<arbol[i]<<(char)(i+1==arbol.size()?10:32);

	return 0;
}

