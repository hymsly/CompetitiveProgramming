#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(x) push_back(x)

#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
#define fi first
#define se second
#define sz(v) ((int)v.size())
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int N=(1.5e5);


int in[N+5];
int pa[N+5];
int ranked[N+5];

int Find(int x){
	if(pa[x]==x) return x;
	return Find(pa[x]);
}
void Union(int x,int y){
	int xset=Find(x);
	int yset=Find(y);
	if(ranked[xset]<ranked[yset]) pa[xset]=yset;
	else if(ranked[xset]>ranked[yset]) pa[yset]=xset;
	else{
		pa[yset]=xset;
		ranked[xset]++;
	}
}

vector<int> G[N+5];

int main(){
	//fast_io()
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) pa[i]=i;
	int a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		in[a]++;
		in[b]++;
		Union(a,b);
	}
	for(int i=1;i<=n;i++){
		G[Find(i)].pb(i);
	}
	/*for(int i=1;i<=n;i++){
		for(int j=0;j<sz(G[i]);j++){
			cout<<G[i][j]<<(char)(j==sz(G[i])-1?10:32);
		}
	}*/
	for(int i=1;i<=n;i++){
		for(int j=0;j<sz(G[i]);j++){
			//cout<<G[i][j]<<" "<<in[G[i][j]]<<endl;
			if(in[G[i][j]]!=sz(G[i])-1){
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
	
	return 0;
}

