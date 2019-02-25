#include<bits/stdc++.h>

using namespace std;
const int N = 200;

int amigo[N+2],enemigo[N+2];
int n;

int Find(int x,int pa[]){
	return (x==pa[x]?x:pa[x]=Find(pa[x],pa));
}

void Union(int x,int y,int pa[]){
	int xx = pa[x];
	int yy = pa[y];
	pa[xx] = yy;
}

void solve(){
	cin>>n;
}

int main(){
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

