#include<bits/stdc++.h>

using namespace std;
const int N = (1e5);
int n;
vector<int> G[N+2];
int A[4*N+2];
bool vis[N+2];
int ST[4*N+2][25];
int cnt = 0;
int pa[N+2];

void bfs(int x){
	int lvl = 0;
	pa[x] = lvl++;
	queue<int> Q;
	Q.push(x);
	while(!Q.empty()){
		int p = Q.front();
		Q.pop();
		for(int i=0;i<G[p].size();i++){
			int pp = G[p][i];
			Q.push(pp);
			pa[pp] = lvl++;
		}
	}
}

void dfs(int x){
	vis[x] = 1;
	A[cnt++] = pa[x];
	for(int i=0;i<G[x].size();i++){
		if(vis[G[x][i]]) continue;
		dfs(G[x][i]);
		A[cnt++] = pa[x];
	}
}

int fi[N+2];
int de[N+2];
void build(){
	for(int i=0;i<cnt;i++) ST[i][0] = A[i];
	for(int j=1;(1<<j)<=cnt;j++){
		for(int i=0;i+(1<<j)<=cnt;i++) ST[i][j] = min(ST[i][j-1] , ST[i + (1<<(j-1))][j-1]);
	}
}

int query(int l,int r){//[l,r>
	int d = r-l;
	int lg = 31 - (__builtin_clz(d));
	return min(ST[l][lg],ST[r-(1<<lg)][lg]);
}

int main(){
	memset(pa,-1,sizeof pa);
	cin>>n;
	int num,len;
	for(int i=0;i<n;i++){
		cin>>len;
		for(int j=0;j<len;j++){
			cin>>num;
			G[i].push_back(num);
		}
	}
	bfs(0);
	dfs(0);
	for(int i=0;i<cnt;i++){
		//if(fi[A[i]]!=-1) continue;
		fi[A[i]] = i;
	}
	for(int i=0;i<n;i++){
		de[fi[i]] = i;
	}
	build();
	int q;cin>>q;
	int a,b;
	while(q--){
		cin>>a>>b;
		int ans = query(fi[pa[a]],fi[pa[b]]+1);
		cout<<de[fi[ans]]<<'\n';
	}
	

	return 0;
}

