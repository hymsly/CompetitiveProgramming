#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const ld EPS = (1e-9);

int px,py,n;
ld p;
ld memo[50][50][3001];
bool vis[50][50][3001];
bool vis2[50][3001];
ld dp(int posx,int posy,int k){
	if(k==0){
		if(posx==py && posy==px) return 1.0L;
		else return 0.0L;
	}
	if(vis[posx][posy][k]) return memo[posx][posy][k];
	vis[posx][posy][k] = 1;
	ld &ans = memo[posx][posy][k] = 0.0L;
	ans = (1.0L-p)*dp(posx,posy,k-1);
	int resta = n-1;
	if(abs(posx-posy)==1){
		ans += (p/(ld)(n-1))*dp(posy,posx,k-1);
		resta--;
	}
	if(posx>0 && posx-1!=posy) ans += (p/(ld)(n-1))*dp(posx-1,posy,k-1),resta--;
	if(posy>0 && posy-1!=posx) ans += (p/(ld)(n-1))*dp(posx,posy-1,k-1),resta--;
	if(posx<n-1 && posx+1!=posy) ans += (p/(ld)(n-1))*dp(posx+1,posy,k-1),resta--;
	if(posy<n-1 && posy+1!=posx) ans += (p/(ld)(n-1))*dp(posx,posy+1,k-1),resta--;
	if(resta>0) ans += ((ld)resta*p/(ld)(n-1))*dp(posx,posy,k-1);
	return ans;
}

ld memo2[50][3001];

ld dp2(int posx,int k){
	if(k==0){
		if(posx==px) return 1.0L;
		else return 0.0L;
	}
	if(vis2[posx][k]) return memo2[posx][k];
	vis2[posx][k] = 1;
	ld &ans = memo2[posx][k] = 0.0;
	ans += (1.0L-p)*dp2(posx,k-1);
	int resta = n-1;
	if(posx>0) ans += (p/(ld)(n-1))*dp2(posx-1,k-1),resta--;
	if(posx<n-1) ans += (p/(ld)(n-1))*dp2(posx+1,k-1),resta--;
	if(resta>0) ans += ((ld)resta*p/(ld)(n-1))*dp2(posx,k-1);
	return ans;
}
int caso = 1;
void solve(){
	int k;
	memset(vis,0,sizeof vis);
	memset(vis2,0,sizeof vis2);
	int x,y;
	cin>>n>>p>>x>>y>>k;
	if(n==1){
		printf("Case %d: %.5f\n",caso++,1.0);
		return;
	}
	if(p<EPS){
		if(x==y) printf("Case %d: %.5f\n",caso++,1.0);
		else printf("Case %d: %.5f\n",caso++,0.0);
		return;
	}
	px = x;
	py = y;
	if(x!=y) printf("Case %d: %.5f\n",caso++,(double)dp(x,y,k));
	else printf("Case %d: %.5f\n",caso++,(double)dp2(x,k));
}

int main(){
	//freopen ("assessment.in","r",stdin);
	int t;cin>>t;
	while(t--) solve();


	return 0;
}
