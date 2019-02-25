#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = (2e5);

int caso;
double ans;
int n,m;
ll up[N+2],
ll down[N+2];

ll M[N+2];

void solve(){
	cin>>n>>m;
	for(int i=0;i<=N;i++) up[i]=INF;
	for(int i=0;i<=N;i++) down[i]=0;
	ll h1,h2,w,x,y,z;
	cin>>h1>>h2>>w>>x>>y>>z;
	M[1] = h1;
	M[2] = h2;
	for(int i=3;i<=n;i++){
		M[i] = (w*M[i-2] + x*M[i-1] + y)%z;
	}
	ll a,b,u,d;
	while(m--){
		cin>>a>>b>>u>>d;
		if(a>b){
			for(int i=a;i<b;i++){
				
			}
		}else if(a<b){
			
		}
	}
	
	printf("Case # %d %.6f\n",++caso,ans);
}

int main(){
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

