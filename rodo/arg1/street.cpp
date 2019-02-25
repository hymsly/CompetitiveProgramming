#include<bits/stdc++.h>

using namespace std;
const int N = (1e7);
int n,a,b;
int T[N+2];
int R[N+2];

void fillR(){
	int g,seed,p;
	cin>>R[0]>>g>>seed>>p;
	for(int i=1;i<n;i++){
		R[i] = (R[i-1]*g+seed)%p;
	}
}


void bfs(int source){
	T[source] = 0;
	queue<int> Q;
	Q.push(source);
	while(!Q.empty()){
		int p = Q.front();
		Q.pop();
		int len = R[p];
		if(2*len < n){
			for(int i=-len;i<=len;i++){
				int nodo = ((p+i)%n+n)%n;
				if(T[nodo] != -1) continue;
				T[nodo] = T[p] + 1;
				if(nodo==b) return;
				Q.push(nodo);
			}
		}else{
			for(int i=0;i<n;i++){
				if(T[i] != -1) continue;
				T[i] = T[p] + 1;
				if(i==b) return;
				Q.push(i);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n>>a>>b;
	fillR();
	memset(T,-1,sizeof T);
	bfs(a);
	cout<<T[b]<<'\n';

	return 0;
}

