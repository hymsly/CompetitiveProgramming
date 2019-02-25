#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (50000);

ll f[N+2];

ll lcm(ll x,ll y){
	return x*y/__gcd(x,y);
}
ll mod = 1;

int modulos[] = {2,3,4,7,13};

void init(){
	for(int i=0;i<5;i++) mod = lcm(mod,modulos[i]);
	f[0] = 0;
	f[1] = 1;
	for(int i=2;i<=N;i++){
		f[i] = 2*f[i-1]+f[i-2];
		f[i]%=mod;
	}
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	init();
	int x;
	while(cin>>x){
		if(x==0){
			cout<<-1<<'\n';
			continue;
		}
		ll p = f[x];
		bool ok = 1;
		for(int i=0;i<5;i++){
			if(p%modulos[i]==0){
				cout<<"Pell’s number "<<x<<" is divisible by "<<modulos[i]<<'\n';
				ok = 0;
			}
		}
		if(ok) cout<<-1<<'\n';
	}

	return 0;
}

