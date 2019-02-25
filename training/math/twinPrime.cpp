#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = (2e7);
const int M = (1e5);

bool pr[N+2];
int f[M+2];


void criba(){
	memset(pr,1,sizeof pr);
	for(ll i=2;i*i<=N;i++){
		if(pr[i]){
			for(ll j=i*i;j<=N;j+=i) pr[j]=0;
		}
	}
	int pos = 0;
	for(ll i=2;pos<M;i++){
		if(pr[i] && pr[i+2]) f[pos++]=i;
	}
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	criba();
	int x;
	while(cin>>x){
		cout<<"("<<f[x-1]<<", "<<f[x-1]+2<<")"<<'\n';
	}

	return 0;
}

