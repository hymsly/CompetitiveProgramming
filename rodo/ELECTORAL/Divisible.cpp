#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll D[12][22][22];

void update(ll x){
	for(int i=10;i>=2;i--){
		for(int j=1;j<=20;j++){
			for(int k=0;k<j;k++){
				int p = (k+x)%j;
				p+=j;
				p%=j;
				D[i][j][p] += D[i-1][j][k];
			}
		}
	}
	for(int j=1;j<=20;j++) D[1][j][((x%j) + j)%j]++;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n,q;
	int sete=1;
	while(cin>>n>>q){
		if(n==0 && q==0) break;
		memset(D,0,sizeof D);
		for(int i=0;i<n;i++){
			ll a;cin>>a;
			update(a);
		}
		ll d,x;
		cout<<"SET "<<sete++<<":\n";
		int caso = 1;
		while(q--){
			cin>>d>>x;
			cout<<"QUERY "<<caso++<<": "<<D[x][d][0]<<'\n';
		}
	}

	return 0;
}

