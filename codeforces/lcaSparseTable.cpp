#include <bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(int i=a,to=b;i<to;i++)
typedef long long ll;
const int INF = (1e9);
const int K = 18;
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
	if(x==INF) return y;
	if(y==INF) return x;
	if(D[x]<D[y])swap(x,y);
	for(int k=K-1;k>=0;--k)if(D[x]-(1<<k)>=D[y])x=F[k][x];
	if(x==y)return x;
	for(int k=K-1;k>=0;--k)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];
	return F[0][x];
}
#define oper lca
int st[K][1<<K]; // K such that 2^K>n
void st_init(){
	fore(i,0,n)st[0][i]=i;
	fore(k,1,K)fore(i,0,n-(1<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
}
int st_query(int s, int e){
	if(s==e) return INF;
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}
int aparicion[1<<K];
int id = 0;
int N=1;
void dfs(int x){
	aparicion[x] = id++;
	for(int i=0;i<g[x].size();i++) dfs(g[x][i]);
}
int lef[1<<K],rig[1<<K];
void buildSides(){
	memset(lef,-1,sizeof lef);
	memset(rig,-1,sizeof rig);
	fore(i,0,n) lef[i+N]=i,rig[i+N]=i;
	for(int i=N-1;i>=1;i--){
		int uno = lef[2*i],dos = lef[2*i+1];
		if(uno==-1)lef[i]=dos;
		else if(dos==-1)lef[i]=uno;
		else if(aparicion[uno]<aparicion[dos])lef[i]=uno;
		else lef[i]=dos;
	}
	for(int i=N-1;i>=1;i--){
		int uno = rig[2*i],dos = rig[2*i+1];
		if(uno==-1)rig[i]=dos;
		else if(dos==-1)rig[i]=uno;
		else if(aparicion[uno]>aparicion[dos])rig[i]=uno;
		else rig[i]=dos;
	}
}
int mostLeft(int s,int r){
	s+=N;
	r+=N;
	int ans = -1;
	int aparece = INF;
	while(s<r){
		if(s&1){
			if(aparicion[lef[s]]<aparece)ans=lef[s],aparece=aparicion[lef[s]];
			s++;
		}
		if(r&1){
			if(aparicion[lef[--r]]<aparece)ans=lef[r],aparece=aparicion[lef[r]];
		}
		s>>=1;
		r>>=1;
	}
	return ans;
}
int mostRight(int s,int r){
	s+=N;
	r+=N;
	int ans = -1;
	int aparece = -1;
	while(s<r){
		if(s&1){
			if(aparicion[rig[s]]>aparece)ans=rig[s],aparece=aparicion[rig[s]];
			s++;
		}
		if(r&1){
			if(aparicion[rig[--r]]>aparece)ans=rig[r],aparece=aparicion[rig[r]];
		}
		s>>=1;
		r>>=1;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int q;
	cin>>n>>q;
	while(N<n)N<<=1;
	for(int i=1;i<n;i++){
		int num;cin>>num;num--;
		g[num].push_back(i);
	}
	lca_init();
	st_init();
	dfs(0);
	buildSides();
	//for(int i=0;i<n;i++) cout<<i<<"->"<<aparicion[i]<<endl;
	int a,b;
	while(q--){
		cin>>a>>b;
		a--;b--;
		int left = mostLeft(a,b+1),right = mostRight(a,b+1);
		int leftLca = lca(st_query(a,left),st_query(left+1,b+1));
		int rightLca = lca(st_query(a,right),st_query(right+1,b+1));
		//cout<<"query "<<a<<"->"<<b<<endl;
		//cout<<left<<" "<<right<<endl;
		//cout<<left<<" "<<leftLca<<endl;
		//cout<<right<<" "<<rightLca<<endl;
		if(D[rightLca]>D[leftLca]){
			cout<<right+1<<" "<<D[rightLca]<<'\n';
		}else{
			cout<<left+1<<" "<<D[leftLca]<<'\n';
		}
	}
	
	return 0;
}
