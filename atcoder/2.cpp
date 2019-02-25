#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> G[22];
vector<int> C[22];

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int l;cin>>l;
	int p = 31 - __builtin_clz(l);
	int edge = 0;
	for(int i=1;i<20;i++){
		G[i].push_back(i+1);
		C[i].push_back(0);
		edge ++;
	}
	for(int i=1;i<p+1;i++){
		G[i].push_back(i+1);
		C[i].push_back((1<<(i-1)));
		edge++;
	}
	l-=(1<<p);
	int base = (1<<(p+1));
	for(int i=0;i<p;i++){
		if(l&(1<<i)){
			G[p-i].push_back(p+1);
			C[p-1].push_back(base + (1<<i))
		}
	}
	cout<<20<<" "<<edge<<'\n';
	for(int i=1;i<20;i++){
		for(int j=0;j<G[i].size();j++){
			cout<<i<<" "<<G[i][j]<<" "<<C[i][j]<<'\n';
		}
	}

	return 0;
}

