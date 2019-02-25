#include<bits/stdc++.h>
using namespace std;
const int N=(2e7);


int M[N+5];
bool is[N+5];
void f(int x){
	for(int i=2;i<=x;i++){
		if(is[i]){
			int cnt=0;
			int aux = x;
			while(aux) cnt+=aux/i,aux/=i;
			M[i]+=cnt;
		}
	}
}

void ff(int x){
	for(int i=2;i<=x;i++){
		if(is[i]){
			int cnt=0;
			int aux = x;
			while(aux) cnt+=aux/i,aux/=i;
			M[i]-=cnt;
		}
	}
}

int pot(int x,int y){
	if(y==0) return 1;
	if(y==1) return x%10;
	int ans = 1;
	if(y&1) ans*=x;
	ans%=10;
	int val = pot(x,y/2);
	ans*=val;
	ans%=10;
	ans*=val;
	ans%=10;
	return ans;
}

void criba(){
	memset(is,1,sizeof(is));
	for(int i=2;i*i<=N;i++){
		if(is[i]){
			for(int j=i*i;j<=N;j+=i) is[j]=0;
		}
	}
}

int main(){
	criba();
	int n,m;
	while(scanf("%d %d",&n,&m)>0){
		memset(M,0,sizeof(M));
		f(n);
		ff(n-m);
		if(M[2]>M[5]){
			M[2]-=M[5];
			M[5]=0;
		}else{
			M[5]-=M[2];
			M[2]=0;
		}
		int ans = 1;
		for(int i=2;i<=n;i++){
			ans *= pot(i,M[i]);
			ans %= 10;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}

