#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (2e5);
const ll MOD = (998244353);

struct FT{
	ll F[N+2];
	FT(){memset(F,0,sizeof F);}
	ll query(ll x){
		ll ans = 0;
		while(x){
			ans += F[x];
			x -= (x&-x);
		}
		return ans;
	}
	void update(ll x,ll y){
		while(x<=N){
			F[x]+=y;
			x += (x&-x);
		}
	}
} BIT;

ll POT[N+2];

void init(){
	POT[0]=1;
	for(int i=1;i<=N;i++){
		POT[i]=2*POT[i-1];
		POT[i]%=MOD;
	}
}

string bas(int x){
	string ans="";
	while(x--) ans.push_back('0');
	return ans;
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	init();
	int n,m;cin>>n>>m;
	string a,b;cin>>a>>b;
	if(n<m){
		string base = bas(m-n);
		a = base+a;
	}else if(m<n){
		string base = bas(n-m);
		b = base+b;
	}
	for(int i=0;i<b.size();i++){
		if(b[i]=='1') BIT.update(i+1,1);
	}
	ll ans = 0;
	for(int i=0;i<a.size();i++){
		if(a[i]=='1'){
			ans += POT[a.size()-i-1]*BIT.query(i+1);
			ans %= MOD;
		}
	}
	cout<<ans<<'\n';

	return 0;
}

