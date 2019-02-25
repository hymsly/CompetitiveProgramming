#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=(1e9 + 7);
const int N=(1e5);
int n;
int a,b,c,d,e,f;
ll fact[N+5];
ll memo[N+5];


ll pot(ll a,ll b){
	if(b==0) return 1;
	if(b==1) return a;
	ll val = pot(a,b/2);
	ll ans=1;
	if(b&1) ans*=a;
	ans*=val;
	ans%=MOD;
	ans*=val;
	ans%=MOD;
	return ans;
} 

ll inv(ll x){
	if(memo[x]!=0) return memo[x];
	ll &ans=memo[x]=0;
	ans+=pot(fact[x],MOD-2)%MOD;
	return ans;
}

ll combi(int x,int y){
	if(x<y) return 0;
	ll ans= fact[x];
	ans *= inv(y);
	ans%=MOD;
	ans *= inv(x-y);
	ans%=MOD;
	return ans;
} 
//R==0 G==1 B==2
ll dp[3][11][11][11][11][11][11];

ll func(int last, int cnt1,int cnt2,int cnt3,int cnt4,int cnt5,int cnt6){
	if(cnt1>a ||cnt2>b || cnt3>c || cnt4>d || cnt5>e || cnt6>f) return 0;
	if(dp[last][cnt1][cnt2][cnt3][cnt4][cnt5][cnt6]!=-1) return dp[last][cnt1][cnt2][cnt3][cnt4][cnt5][cnt6]; 
	int tam = cnt1+cnt2+cnt3+cnt4+cnt5+cnt6+1;
	if(tam > n) return 0;
	ll &ans=dp[last][cnt1][cnt2][cnt3][cnt4][cnt5][cnt6]=0;
	ans += combi(n - 1 , tam - 1);
	ans%=MOD;
	if(last!=0) ans += func(0 , cnt1,cnt2,cnt3 + (last==2),cnt4,cnt5 + (last==1),cnt6);
	ans%=MOD;
	if(last!=2) ans += func(2 , cnt1 + (last==0),cnt2,cnt3,cnt4,cnt5,cnt6 + (last==1));
	ans%=MOD;
	if(last!=1) ans += func(1 , cnt1,cnt2 + (last==0),cnt3,cnt4 + (last==2),cnt5,cnt6);
	ans%=MOD;
	return ans;
}

int main(){
	cin>>n>>a>>b>>c>>d>>e>>f;
	memset(dp,-1,sizeof(dp));
	fact[0]=1;
	for(int i=1;i<=n;i++){
		fact[i]=i*fact[i-1];
		fact[i]%=MOD;
	}
	ll ans=func(0 , 0,0,0,0,0,0);
	ans += func(1 , 0,0,0,0,0,0);
	ans%=MOD;
	ans += func(2 , 0,0,0,0,0,0);
	ans%=MOD;
	cout<<ans<<'\n';
	return 0;
}

