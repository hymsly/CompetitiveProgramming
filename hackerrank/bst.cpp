#include<bits/stdc++.h>

using namespace std;

struct Node{
	int val;
	int der,izq;
	Node(){
		der = -1;
		izq = -1;
	}
	Node(int _val,int _der,int _izq){
		val = _val;
		der = _der;
		izq = _izq;
	}
};

int nodo = 1;

Node T[2005];

void add(int x,int y){
	int last = 0;
	while(1){
		if(x > T[last].val){
			if(T[last].der==-1){
				T[last].der = y;
				T[y] = Node(x,-1,-1);
				return;
			}else{
				last = T[last].der;
			}
		}else{
			if(T[last].izq==-1){
				T[last].izq = y;
				T[y] = Node(x,-1,-1);
				return;
			}else{
				last = T[last].izq;
			}
		}
	}
}

int peso[2005];
bool vis[2005];
int dp(int x){
	if(peso[x]!=-1) return peso[x];
	int &ans = peso[x] = 0;
	if(T[x].izq!=-1) ans = max(ans,dp(T[x].izq)+1);
	if(T[x].der!=-1) ans = max(ans,dp(T[x].der)+1);
	return ans;
}

int main(){
	memset(peso,-1,sizeof peso);
	int n;cin>>n;
	int num;cin>>num;
	vis[num]=1;
	T[0] = Node(num,-1,-1);
	for(int i=1;i<n;i++){
		cin>>num;
		if(vis[num]) continue;
		vis[num] = 1;
		add(num,nodo++);
	}
	int maxi = dp(0);
	int ans = 0;
	for(int i=0;i<nodo;i++){
		ans += peso[i];
	}
	cout<<maxi<<endl<<ans<<endl;

	return 0;
}

