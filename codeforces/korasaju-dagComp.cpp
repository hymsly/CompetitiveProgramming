#include<bits/stdc++.h>
using namespace std;
#define fore(i, a, b) for (Long i = a, to = b; i < to; i++)
#define all(v) v.begin(), v.end()
#define SZ(v) (int)v.size()
#define pb push_back
typedef long long Long;
typedef pair<int, int> Pair;
const int MX = (2e5);

ll C[MX+2];

vector<int> G[MX+2],GG[MX+2];
bool vis[MX+2];

void addEdge(int x,int y){
	if(x==y) return;
	G[x].push_back(y);
	GG[y].push_back(x);
}

stack<int> s;
int componente[MX+5];
void dfs(int x){
    vis[x] = 1;
    fore(i,0,SZ(G[x])){
        if(vis[G[x][i]]) continue;
        dfs(G[x][i]);
    }
    s.push(x);
}
void dfs2(int x,int id){
    vis[x] = 1;
    componente[x] = id;
    for(int i=0;i<GG[x].size();i++){
        if(vis[GG[x][i]]) continue;
        dfs2(GG[x][i],id);
    }
}
int id=1;

vector<int> COND[MX+5];//grafo condensado
int in[MX+5];

vector<int> ACUM[MX+5];
int n;
void kosaraju(){
    memset(vis,0,sizeof(vis));
    fore(i,1,n+1){
        if(!vis[i]){
            dfs(i);
        }
    }
    memset(vis,0,sizeof(vis));
    while(!s.empty()){
        int val = s.top();
        s.pop();
        if(vis[val]) continue;
        dfs2(val,id++);
    }
    fore(i,1,n+1){
    	int conden = componente[i];
    	ACUM[conden].push_back(i);
	}
    set< Pair > M;
    fore(i,1,n+1){
        int componenteDeI = componente[i];
        for(j,0,SZ(G[i])){
            int componenteDeJ = componente[G[i][j]];
            if(componenteDeI == componenteDeJ) continue;
            if(M.find(make_pair(componenteDeI,componenteDeJ))!=M.end()) continue;
            COND[componenteDeI].push_back(componenteDeJ);
            M.insert(make_pair(componenteDeI,componenteDeJ));
            in[componenteDeI] ++;
        }
    }
    vector<int> nodos;
    Long ans = 0;
    fore(i,1,id){
    	if(in[i]==0){//es nodo final
			Long res = (1e6);
			for(int j=0;j<ACUM[i].size();j++){
				res = min(res,C[ACUM[i][j]]);
			}
			ans += res;
		}
	}
	cout<<ans<<'\n';
}

int main(){
	//ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>C[i];
	int num;
	for(int i=1;i<=n;i++){
		cin>>num;
		addEdge(i,num);
	}
	kosaraju();
	
	return 0;
}

