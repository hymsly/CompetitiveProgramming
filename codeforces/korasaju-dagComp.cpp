#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (2e5);

ll C[N+2];

vector<int> G[N+2],GG[N+2];
bool vis[N+2];

void addEdge(int x,int y){
	if(x==y) return;
	G[x].push_back(y);
	GG[y].push_back(x);
}

stack<int> s;
int componente[N+5];
void dfs(int x){
    vis[x] = 1;
    for(int i=0;i<G[x].size();i++){
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
ll id=1;

vector<int> COND[N+5];//grafo condensado
int in[N+5];

vector<int> ACUM[N+5];
int n;
void kosaraju(){
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
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
    for(int i=1;i<=n;i++){
    	int conden = componente[i];
    	ACUM[conden].push_back(i);
	}
    set< pair<int,int> > M;
    for(int i=1;i<=n;i++){
        int componenteDeI = componente[i];
        for(int j=0;j<G[i].size();j++){
            int componenteDeJ = componente[G[i][j]];
            if(componenteDeI == componenteDeJ) continue;
            if(M.find(make_pair(componenteDeI,componenteDeJ))!=M.end()) continue;
            COND[componenteDeI].push_back(componenteDeJ);
            M.insert(make_pair(componenteDeI,componenteDeJ));
            in[componenteDeI] ++;
        }
    }
    vector<int> nodos;
    ll ans = 0;
    for(int i=1;i<id;i++){
    	if(in[i]==0){//es nodo final
			ll res = (1e6);
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

