#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
 
vector < int > adj[N+2];    // stores the tree
vector < int > euler;      // tracks the eulerwalk
vector < int > depthArr;   // depth for each node corresponding
                           // to eulerwalk
 
int FAI[N+2];     // stores first appearence index of every node
int level[N+2];   // stores depth for all nodes in the tree
int ptr;         // pointer to euler walk
int dp[2*N+2][25];  // sparse table
 
void buildSparseTable(int n){
    for(int i=0; i<n; i++) dp[i][0] = i;
	for(int j=1;(1<<j)<=n;j++){
		for(int i=0;i+(1<<j)<=n;i++){
			if(depthArr[dp[i][j-1]] <= depthArr[dp[i+(1<<(j-1))][j-1]]){
				dp[i][j] = dp[i][j-1];
			}else{
				dp[i][j] = dp[i+(1<<(j-1))][j-1];
			}
		}
	}
}
 
int query(int l,int r){
    int d = r-l;
    int dx = 31 - __builtin_clz(d);
    if(depthArr[dp[r-(1<<dx)][dx]] < depthArr[dp[l][dx]]) return dp[r-(1<<dx)][dx];
    else return dp[l][dx];
}
 
void dfs(int cur,int dep){
    if (FAI[cur]==-1) FAI[cur] = ptr++;
    level[cur] = dep;
    euler.push_back(cur);
    for(int i=0;i<adj[cur].size();i++){
        dfs(adj[cur][i],dep+1);
        euler.push_back(cur);
        ptr++;
    }
}
 
void makeArr(){
    for (int i=0;i<euler.size();i++){
	    depthArr.push_back(level[euler[i]]);
	}
}
 
int LCA(int u,int v){
    if (FAI[u] > FAI[v]) swap(u,v);
    return euler[query(FAI[u], FAI[v]+1)];
}
 
int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int len,num;
		cin>>len;
		for(int j=0;j<len;j++){
			cin>>num;
			adj[i].push_back(num);
		}
	}
    ptr = 0;
    memset(FAI,-1,sizeof(FAI));
    dfs(0,0);
    makeArr();
	buildSparseTable(depthArr.size());
	int q;cin>>q;
	int a,b;
	while(q--){
		cin>>a>>b;
		cout<<LCA(a,b)<<'\n';
	}
 
    return 0;
}

