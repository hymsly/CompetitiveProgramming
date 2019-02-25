#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
const int N = (200);
const ll INF = (1e9);

pair<ll,ll> par[N+2][N+2],impar[N+2][N+2];

ll M[N+2][N+2];
int n,m;

pair<ll,ll> operator +(const pair<ll,ll> &a,const pair<ll,ll> &b){
	return mp(a.fi+b.fi,a.se+b.se);
}
pair<ll,ll> operator -(const pair<ll,ll> &a,const pair<ll,ll> &b){
	return mp(a.fi-b.fi,a.se-b.se);
}
ll ans[N+2];

void build(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			impar[i][j] = impar[i-1][j] + impar[i][j-1] - impar[i-1][j-1];
			par[i][j] = par[i-1][j] + par[i][j-1] - par[i-1][j-1];
			if((i+j)&1){//impar
				if(M[i][j]) impar[i][j].first++;
				else impar[i][j].second++;
			}else{
				if(M[i][j]) par[i][j].first++;
				else par[i][j].second++;
			}
		}
	}
	for(int i=1;i<=min(n,m);i++)ans[i] = INF;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int cua = min(i,j);
			for(int k=1;k<=cua;k++){
				int iniI = i-k,iniJ=j-k;
				pair<ll,ll> posPar = par[i][j] - par[iniI][j] - par[i][iniJ] + par[iniI][iniJ];
				pair<ll,ll> posImpar = impar[i][j] - impar[iniI][j] - impar[i][iniJ] + impar[iniI][iniJ];
				ans[k] = min(ans[k] , min(posPar.fi+posImpar.se,posPar.se+posImpar.fi));
			}
		}
	}
	//for(int i=1;i<=min(n,m);i++) cout<<ans[i]<<(char)(i==min(n,m)?10:32);
	int q;cin>>q;
	while(q--){
		ll x;
		cin>>x;
		int p = lower_bound(ans+1,ans+min(n,m)+1,x+1) - (ans+1);
		cout<<p<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	string s;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=0;j<m;j++) M[i][j+1] = (s[j]-'0');
	}
	build();

	return 0;
}

