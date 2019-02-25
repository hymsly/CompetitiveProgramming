#include<bits/stdc++.h>

using namespace std;
const int N = 100000;
const int BLOCK=200;
map<int,int> G[BLOCK+2];

int M[N+2];

void agregar(){
	int k,b;
	cin>>k>>b;
	b%=k;
	if(k>BLOCK){
		while(b <= N){
			M[b]++;
			b+=k;
		}
	}else{
		G[k][b]++;
	}
}

void borrar(){
	int k,b;cin>>k>>b;
	b%=k;
	if(k>BLOCK){
		while(b <= N){
			M[b]--;
			b+=k;
		}
	}else{
		G[k][b]--;
	}
}

void query(){
	int q;
	cin>>q;
	int ans = M[q];
	for(int i=1;i<=BLOCK;i++){
		int p = q%i;
		if(G[i].count(p)) ans+=G[i][p];
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n;cin>>n;
	char s;
	for(int i=0;i<n;i++){
		cin>>s;
		if(s=='+') agregar();
		else if(s=='-') borrar();
		else query();
	}

	return 0;
}

