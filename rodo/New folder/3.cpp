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
const int N=(1e6);


ll M[N+5];
bool is[N+5];
void f(ll x){
	for(ll i=2;i<=x;i++){
		if(is[i]){
			ll cnt=0;
			ll aux = x;
			while(aux) cnt+=aux/i,aux/=i;
			M[i]+=cnt;
		}
	}
}

void ff(ll x){
	for(ll i=2;i<=x;i++){
		if(is[i]){
			ll cnt=0;
			ll aux = x;
			while(aux) cnt+=aux/i,aux/=i;
			M[i]-=cnt;
		}
	}
}

ll pot(ll x,ll y){
	if(y==0) return 1;
	if(y==1) return x%10;
	ll ans = 1;
	if(y&1) ans*=x;
	ans%=10;
	ll val = pot(x,y/2);
	ans*=val;
	ans%=10;
	ans*=val;
	ans%=10;
	return ans;
}

void criba(){
	memset(is,1,sizeof(is));
	for(ll i=2;i*i<=N;i++){
		if(is[i]){
			for(ll j=i*i;j<=N;j+=i) is[j]=0;
		}
	}
}
void mostrar(){
	for(int i=2;i<=10;i++) cout<<M[i]<<endl;
	cout<<endl;
}

int main(){
	//fast_io()
	criba();
	ll n,m;
	cin>>n>>m;
	f(n);
	ff(n-m);
	ff(m);
	if(M[2]>M[5]){
		M[2]-=M[5];
		M[5]=0;
	}else{
		M[5]-=M[2];
		M[2]=0;
	}
	ll ans = 1;
	for(int i=2;i<=n;i++){
		ans *= pot(i,M[i]);
		ans %= 10;
	}
	cout<<ans<<endl;
	
	return 0;
}

