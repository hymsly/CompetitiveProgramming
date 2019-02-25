#include<bits/stdc++.h>

using namespace std;
const int N = (1e5);

vector<int> G[N+2];
vector<int> tree[N+2];

int pa[N+2];
bool vis[N+2];
int Find(int x){
	return (pa[x]==x?x:pa[x]=Find(pa[x]));
}

void Union(int x,int y){
	int px = Find(x);
	int py = Find(y);
}

void root(int x,int padre){
	for(int i=0;i<G[x].size();i++){
		tree[x].push_back(G[x][i]);
		root(G[x][i],x);
	}
}

void dfs(int x,int padre){
	vis[x] = 1;
	for(int i=0;i<tree[x].size();i++){
		Union(padre,tree[x][i]);
		if(!vis[tree[x][i]]) dfs(tree[x][i],padre);
	}
}

int A[N+2];

int main(){
	int n;cin>>n;
	int a,b;
	for(int i=1;i<n;i++){
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=1;i<=n;i++) pa[i] = i;
	int lab = 0;
	for(int i=0;i<G[1].size();i++){
		root(G[1][i],1);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) dfs(i,i);
	}

	return 0;
}

