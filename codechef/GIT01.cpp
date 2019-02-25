#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

char M[105][105];
int n,m;

int f(){
	int a=0,b=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if((i+j)%2 == 0){
				if(M[i][j]=='R') a+=5;
				else b+=3;
			}else{
				if(M[i][j]=='R') b+=5;
				else a+=3;
			}
		}
	}
	return min(a,b);
}

int main(){
	//ios_base::sync_with_stdio(0);
	int t;cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>M[i][j];
		cout<<f()<<'\n';
	}

	return 0;
}

