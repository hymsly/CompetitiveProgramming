#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (200);

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
bool fin[N+5];
ll cnt[N+5];

vector<int> ACUM[N+5];
int n;
ll lcm(ll x,ll y){
	ll ans = x;
	ans /= __gcd(x,y);
	ans*=y;
	return ans;
}

ll dfs3(int x){
	if(fin[componente[x]]) return 0LL;
	return 1+dfs3(G[x][0]);
}

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
    memset(fin,1,sizeof fin);
    ll ans = 1;
    for(int i=1;i<=n;i++){
        int componenteDeI = componente[i];
        cnt[componenteDeI]++;
        for(int j=0;j<G[i].size();j++){
            int componenteDeJ = componente[G[i][j]];
            if(componenteDeI == componenteDeJ) continue;
            if(M.find(make_pair(componenteDeI,componenteDeJ))!=M.end()) continue;
            COND[componenteDeI].push_back(componenteDeJ);
            M.insert(make_pair(componenteDeI,componenteDeJ));
			fin[componenteDeI] = 0;
        }
    }
    for(int i=1;i<id;i++){
    	if(fin[i]){
			ans=lcm(ans,cnt[i]);
		}
	}
	ll maxi = 0;
	for(int i=1;i<=n;i++){
		maxi = max(maxi,dfs3(i));
	}
	if(maxi>ans){
		cout<<(maxi/ans + (maxi%ans>0))*ans<<'\n';
	}else cout<<ans<<'\n';
}


int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	int a;
	for(int i=1;i<=n;i++){
		cin>>a;
		addEdge(i,a);
	}
	kosaraju();

	return 0;
}

