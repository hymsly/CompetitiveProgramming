#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=(2000);
int caso;
ll ans;

int pa[N+2];

int Find(int x){
	return (pa[x]==x?x:pa[x]=Find(pa[x]));
}

void Union(int x,int y){
	int xx = Find(x);
	int yy = Find(y);
	pa[xx]=yy;
}

int pre[N+2];
int post[N+2];

vector<int> G[N+2];
int pos;
void preorder(int x){
	pre[pos++] = x;
	for(int i=0;i<G[x].size();i++){
		int p = G[x][i];
		preorder(p);
	}
}

void postorder(int x){
	for(int i=0;i<G[x].size();i++){
		int p = G[x][i];
		postorder(p);
	}
	post[pos++] = x;
}

int etiqueta[N+2];
int n,k;
void solve(){
	cin>>n>>k;
	for(int i=1;i<=N;i++) pa[i]=i;
	memset(pre,0,sizeof pre);
	memset(post,0,sizeof post);
	memset(etiqueta,0,sizeof etiqueta);
	for(int i=1;i<=N;i++) G[i].clear();
	int a,b;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		if(a) G[i].push_back(a);
		if(b) G[i].push_back(b);
	}
	pos = 0;
	preorder(1);
	pos = 0;
	postorder(1);
	//for(int i=0;i<n;i++) cout<<pre[i]<<(char)(i+1==n?10:32);
	//for(int i=0;i<n;i++) cout<<post[i]<<(char)(i+1==n?10:32);
	for(int i=0;i<n;i++){
		Union(pre[i],post[i]);
	}
	map<int,int> val;
	pos=1;
	for(int i=1;i<=n;i++){
		int p = Find(i);
		if(val.count(p)) continue;
		val[p]=pos;
		pos++;
		if(pos>k) pos-=k;
	}
	cout<<"Case #"<<++caso<<": ";
	if(val.size()>=k){
		for(int i=1;i<=n;i++) cout<<val[Find(i)]<<(char)(i==n?10:32);
	}else cout<<"Impossible\n";
}

int main(){
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

