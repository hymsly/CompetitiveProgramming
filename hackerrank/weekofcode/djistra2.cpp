#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node{
	ll dist,u;
	Node(){}
	Node(ll _dist,ll _u){
		dist=_dist;
		u=_u;
	}
};

bool operator < (const Node a,const Node b){
	return a.dist > b.dist;
}

int n;
ll k;
const int N=(1e4);
vector<int> G[N+2];
vector<int> C[N+2];

ll d[N+2];

void djistra(int source){
	for(int i=1;i<=n;i++){
		d[i] = (1e12);
	}
	d[source] = 0;
	priority_queue<Node> Q;
	Q.push(Node(0,source));
	while(!Q.empty()){
		Node a = Q.top();
		Q.pop();
		if(a.dist%(2*k)>=k){
			Q.push(Node((a.dist/(2*k) +1 )*2*k,a.u));
		}else{
			for(int i=0;i<G[a.u].size();i++){
				int v=G[a.u][i];
				ll w = C[a.u][i];
				if(a.dist + w < d[v]){
					d[v] = a.dist+w;
					Q.push(Node(d[v],v));
				}
			}
		}
	}
	//for(int i=1;i<=n;i++) cout<<d[i]<<(char)(i==n?10:32);
	cout<<d[n]<<'\n';
}

int main(){
	cin>>n;
	cin>>k;
	int m;
	cin>>m;
	int a,b,t;
	while(m--){
		cin>>a>>b>>t;
		G[a].push_back(b);
		G[b].push_back(a);
		C[a].push_back(t);
		C[b].push_back(t);
	}
	djistra(1);

	return 0;
}

