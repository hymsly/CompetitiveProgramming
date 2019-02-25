#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 10000;
const int N = 1000;

struct edge{
  int v;
  ll w;
  edge(){} edge(int v, int w) : v(v), w(w) {}
};

map<string,int> cd;

vector<edge> g[N+2];

long long d[N+2][N+2];

int karp(int n){
	for(int i = 0;i<n;++i)
    if(!g[i].empty())
    	g[n].push_back(edge(i,0));
	n++;
	for(int i = 0;i<n;++i) fill(d[i],d[i]+(n+1),INT_MAX);
	
	d[n-1][0] = 0;

	for (int k = 1;k<=n;++k) for (int u = 0;u<n;++u){
		if(d[u][k-1]==INT_MAX) continue;
    	for(int i = g[u].size()-1;i>=0;--i) d[g[u][i].v][k] = min(d[g[u][i].v][k],d[u][k-1]+g[u][i].w);
	}

	bool flag = true;

	for(int i = 0;i<n;++i) if(d[i][n]!=INT_MAX) flag = false;
	
	if(flag) return true;

	double ans = 1e15;

	for(int u = 0;u+1<n;++u){
    	if(d[u][n]==INT_MAX) continue;
    	double W = -1e15;

    	for(int k = 0;k<n;++k) if(d[u][k]!=INT_MAX) W = max(W,(double)(d[u][n]-d[u][k])/(n-k));
    	ans = min(ans,W);
	}

	ans = -ans;
	cout<<ans<<'\n';
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	string cur(2, '0');
	for (int i = 0; i < 26; ++i) {
    	for (int j = 0; j < 26; ++j) {
    		cur[0] = char(i + 'a');
    		cur[1] = char(j + 'a');
    		cd[cur] = i * 26 + j;
    	}
	}
	int n;
	while (cin>>n) {
    	if(n==0) break;
		string line;
		for (int i = 0; i < N; ++i) {
    		g[i].clear();
		}
		for (int i = 0; i < n; ++i) {
			cin >> line;
			if (line.size() < 2) continue;
			int u = cd[line.substr(0, 2)];
			int v = cd[line.substr(line.size() - 2, 2)];	
			g[u].push_back(edge(v, -line.size()));
		}
		if (karp(cd.size())) {
			cout << "No solution." << endl;
		}
	}
	return 0;
}
