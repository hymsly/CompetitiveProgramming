#include<bits/stdc++.h>

using namespace std;
const int N = (1e6);
bool pr[N+5];
void criba(){
	memset(pr,1,sizeof pr);
	for(int i=2;i*i<=N;i++){
		if(pr[i]){
			for(int j=i*i;j<=N;j+=i) pr[j] = 0;
		}
	}
}

int main(){
	criba();
	int valor = 0;
	int ans = 0;
	for(int b=2;b<=1000;b++){
		if(pr[b]){
			for(int a=-999;a<1000;a++){
				int cnt = 1;
				int val;
				while(1){
					val = (cnt*cnt + a*cnt + b);
					if(val<2) break;
					if(pr[val]) cnt++;
					else break;
				}			
				if(cnt > valor){
					ans = a*b;
					valor = cnt;
				}
			}
		}
	}
	cout<<ans<<" "<<valor<<endl;

	return 0;
}

