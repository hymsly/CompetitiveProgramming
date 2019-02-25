#include<bits/stdc++.h>

using namespace std;
const unsigned int N = (3e8);
const unsigned int M = (4e6);
unsigned int a,b,c,d,n;

unsigned int vis[M + 2];

unsigned int f(unsigned int x){
	return (a*x*x*x + b*x*x + c*x + d);
}
bool prime(unsigned int x){
	if(x==2 || x==3 || x==5) return true;
	if(x%6!=1 && x%6!=5) return false;
	x -= 6;
	x /=3;
	unsigned int pos = x/32;
	unsigned int ter = x%32;
	if(vis[pos] & (1<<ter)) return true;
	return false;
}
void init(){
	for(unsigned int i=0;i<=M;i++) vis[i] = 4294967295U;
	for(unsigned int i=5;i*i<=N;i++){
		if(prime(i)){
			for(unsigned int j=i*i;j<=N;j+=i){
				if(!prime(j)) continue;
				unsigned int value = j - 6;
				value /=3;
				unsigned int pos = value/32;
				unsigned int ter = value%32;
				if(vis[pos] & (1<<ter)) vis[pos] ^= (1<<ter);
			}
		}
	}
}

int main(){
	init();
	cin>>n>>a>>b>>c>>d;
	unsigned int ans = 0;
	for(int i=2;i<=n;i++){
		if(!prime(i)) continue;
		unsigned int cnt = 0,aux = n;
		while(aux){
			cnt += (aux/i);
			aux /= i;
		}
		ans += cnt*f(i);
	}
	cout<<ans<<'\n';

	return 0;
}
