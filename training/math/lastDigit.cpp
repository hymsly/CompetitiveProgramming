#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (1e6);

bool pr[N+2];
vector<ll> primo;
void init(){
	memset(pr,1,sizeof pr);
	for(int i=2;i*i<=N;i++){
		if(pr[i]) for(int j=i*i;j<=N;j+=i) pr[j] = 0;
	}
	for(int i=2;i<=N;i++) if(pr[i]) primo.push_back(i);
}
vector<ll> expo;

ll f(ll x,ll y){
	ll ans = 0;
	while(x>=y){
		ans++;
		x/=y;
	}
	return ans;
}

int pot(int x,int y){
	if(y==0) return 1;
	if(y==1) return x;
	int ans = 1;
	if(y&1) ans = x;
	int val = pot(x,y/2);
	ans *= val;
	ans %= 10;
	ans *= val;
	ans %= 10;
	return ans;
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	init();
	ll n;
	expo.resize(primo.size());
	while(cin>>n){
		if(n==0) break;
		for(int i=0;i<expo.size();i++) expo[i] = 0;
		for(int i=0;i<primo.size();i++){
			if(primo[i]>n) break;
			expo[i] = f(n,primo[i]);
		}
		expo[0]-=expo[2];
		expo[2] = 0;
		int ans = 1;
		for(int i=0;i<primo.size();i++){
			if(primo[i]>n) break;
			//cout<<primo[i]<<" "<<expo[i]<<endl;
			ans *= pot(primo[i]%10,expo[i]);
			ans %= 10;
		}
		cout<<ans<<'\n';
	}


	return 0;
}

