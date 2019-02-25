#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int V = (45);
const ll INF = (1e18);
const ll asd = (1e12);
ll graph[V][V];

int bfs(ll rGraph[V][V], int s, int t, int parent[])
{
    // Create a visited array and mark all vertices as not visited
    bool visited[V];
    memset(visited, 0, sizeof(visited));
 
    // Create a queue, enqueue source vertex and mark source vertex
    // as visited
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    // Standard BFS Loop
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        for (int v=0; v<V; v++)
        {
            if (!visited[v] && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = 1;
            }
        }
    }
 
    // If we reached sink in BFS starting from source, then return
    // true, else false
    return (visited[t]);
}
 
// A DFS based function to find all reachable vertices from s.  The function
// marks visited[i] as true if i is reachable from s.  The initial values in
// visited[] must be false. We can also use BFS to find reachable vertices
void dfs(ll rGraph[V][V], int s, bool visited[]){
    visited[s] = true;
    for (int i = 0; i < V; i++)
       if (rGraph[s][i] && !visited[i])
           dfs(rGraph, i, visited);
}
 
ll minCut(int s, int t){
    ll rGraph[V][V];
    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++)
             rGraph[u][v] = graph[u][v];
 
    int parent[V];
 
    while (bfs(rGraph, s, t, parent)){
        ll path_flow = INF;
        for (int v=t; v!=s; v=parent[v]){
            int u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (int v=t; v != s; v=parent[v]){
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
    }
 
    bool visited[V];
    memset(visited, false, sizeof(visited));
    dfs(rGraph, s, visited);
 
    ll ans = 0;
    for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++)
         if (visited[i] && !visited[j] && graph[i][j])
              ans += graph[i][j];
    return ans;
}

// Driver program to test above functions
int main()
{
    // Let us create a graph shown in the above example
    int n,m;
    cin>>n>>m;
    int k,f;
    int maxi = 0;
    for(int i=0;i<m;i++){
    	cin>>k>>f;
    	int a,b,c;
    	if(k==2){
    		cin>>a>>b;
    		a--;
    		b--;
    		graph[a][b] = 2*f;
    		graph[b][a] = 2*f;
    		maxi += 2*f;
		}else{
			cin>>a>>b>>c;
			a--;
			b--;
			c--;
    		graph[a][b] = f;
    		graph[b][a] = f;
    		graph[a][c] = f;
    		graph[c][a] = f;
    		graph[c][b] = f;
    		graph[b][c] = f;
    		maxi += f;
		}
	}
	//for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(graph[i][j]==0) graph[i][j] = asd;
	ll ans = INF;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ans = min(ans,minCut(i, j));
		}
	}
	cout<<maxi-ans<<endl;
 
    return 0;
}
