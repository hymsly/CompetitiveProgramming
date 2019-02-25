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
int caso;
int n,m;
vector<int> v;
vector<int> G[52];


void doit(){
	cin>>n>>m;
	v.resize(n);
	for(int i=0;i<n;i++) cin>>v[i];
	for(int i=0;i<n;i++){
		G[i].resize(m);
		for(int j=0;j<m;j++) cin>>G[i][j];
	}
	int ans=0;
	for(int i=0;i<n;i++) cout<<v[i]<<(char)(i+1==n?10:32);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<G[i][j]<<(char)(j+1==m?10:32);
		}
	}
	
	cout<<"Case #"<<++caso<<": "<<ans<<endl;
}

int main(){
	//fast_io()
	int t;cin>>t;
	while(t--){
		doit();
	}
	
	return 0;
}

