#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = (1e9+7);
const int N = (1e6);
ll fibo[N+2];

void init(){
	fibo[0]=0;
	fibo[1]=1;
	for(int i=2;i<=N;i++) fibo[i]=(fibo[i-1]+fibo[i-2])%MOD;
}
int n,m;

ll get1(int x){
	if(x==1) return 1;
	if(x==2) return 0;
	return fibo[x-2];
}


ll get2(int x){
	if(x==1) return 0;
	return fibo[x-1];
}

void solve(){
	cin>>m>>n;
	ll sum1=0,sum2=0;
	ll num;
	for(int i=0;i<m;i++){
		cin>>num;
		sum1+=num;
		sum1%=MOD;
	}
	sum1*=m;
	sum1%=MOD;
	for(int i=0;i<m;i++){
		cin>>num;
		sum2+=num;
		sum2%=MOD;
	}
	sum2*=m;
	sum2%=MOD;
	ll ans = get1(n)*sum1 + get2(n)*sum2;
	ans%=MOD;
	cout<<ans<<'\n';
}

int main(){
	init();
	int t;cin>>t;
	while(t--) solve();
	

	return 0;
}

