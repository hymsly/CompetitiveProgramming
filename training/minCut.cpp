#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = (1e12);
const int N = 50;

ll g[N+2][N+2];
ll dist[N+2];
bool vis[N+2];

void addEdge(int u, int v, ll c){
    g[u][v] += c;
    g[v][u] += c;
}

ll Wagner(vector<int> &v){//vertices
	ll mincut = INF;
    while(v.size() > 1){
        int u = v[0];
        for(int i=0;i<v.size();i++){
            vis[v[i]] = false;
            dist[v[i]] = g[u][v[i]];
        }
        vis[u] = true;
        for(int t=0;t<v.size()-2;t++){
        	for(int i=0;i<v.size();i++){
            	if (!vis[v[i]]){
            		if(vis[u] || dist[v[i]] > dist[u]) u = v[i];
				}
        	}
            vis[u] = true;
            for(int i=0;i<v.size();i++){
            	if (!vis[v[i]]) dist[v[i]]+=g[u][v[i]];
        	}
        }
        int t = -1;
        for(int i=0;i<v.size();i++){
            if (!vis[v[i]]) t = v[i];
        }
        mincut = min(mincut, dist[t]);
        v.erase(find(v.begin(),v.end(),t));
		for(int i=0;i<v.size();i++){
            addEdge(u, v[i], g[v[i]][t]);
        }
    }
    return mincut;
}

int main(){
    int n, m;cin>>n>>m;
    ll tot = 0;
    for(int i=0;i<m;i++){
        int k, f, u;
		cin>>k>>f;
        vector<int> group;
        for(int j=0;j<k;j++){
            cin>>u;u--;
            group.push_back(u);
        }
        tot += 2*f;
        if (k == 2) addEdge(group[0], group[1], 2 * f);
        else{
            addEdge(group[0], group[1], f);
            addEdge(group[1], group[2], f);
            addEdge(group[2], group[0], f);
        }
    }
    vector<int> vertices;
	for(int i=0;i<n;i++) vertices.push_back(i);
    ll mincut = Wagner(vertices);
    cout<<(tot - mincut)/2<<'\n';
    return 0;
}
