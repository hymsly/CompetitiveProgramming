#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fore(i,a,b) for(int i=a,to=b;i<to;i++)
#define SZ(x) (int)x.size()
#define pb push_back
const int K = (18);
const int N = (1e5);
vector<int> g[1<<K];int n;  // K such that 2^K>=n
int F[K][1<<K],D[1<<K];
void lca_dfs(int x){
	fore(i,0,g[x].size()){
		int y=g[x][i];if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
	}
}
void lca_init(){
	D[0]=0;F[0][0]=-1;
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n)
		if(F[k-1][x]<0)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
}
int lca(int x, int y){
	if(D[x]<D[y])swap(x,y);
	for(int k=K-1;k>=0;--k)if(D[x]-(1<<k)>=D[y])x=F[k][x];
	if(x==y)return x;
	for(int k=K-1;k>=0;--k)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];
	return F[0][x];
}

int dist(int x,int y){
	//cout<<x+1<<"-"<<y+1<<" "<<lca(x,y)+1<<":"<<(D[x]+D[y]-2*D[lca(x,y)])<<'\n';
	return (D[x]+D[y]-2*D[lca(x,y)]);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int q;cin>>n>>q;
	for(int i=1;i<n;i++){
		int a,b;cin>>a>>b;
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	lca_init();
	while(q--){
		int a,b,c,d;cin>>a>>b>>c>>d;
		a--;b--;c--;d--;
		int x = dist(a,b)+dist(c,d);
		int y=min(dist(a,c)+dist(b,d),dist(b,c)+dist(a,d));
		int ans = 0;
		if(x>=y)ans = ((x-y)/2)+1;
		cout<<ans<<'\n';
	}

	return 0;
}
