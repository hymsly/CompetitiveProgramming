#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> G [ N+2 ] ;
void add ( int x , int y ) {
	G[x].push_back(y);
	G[y].push_back(x);
}
deque<int> T[N+2];
bool vis[N+2];

	

void dfs ( int x , int fa ,bool lleva){
	vis[x] = 1;
	for(int i=0;i<G[x].size();i++){
		int p = G[x][i];
		T[p].push_back()
		if(!vis[p]) dfs(p,fa,lleva);
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	if (m&1) {
		cout<<"No solution"<<'\n' ; 
		return 0;
	}
	for ( int i = 0 , x , y ; i < m ; i ++ ) cin >> x >> y , add (x,y) ;
	dfs (i,i,0) ;
	for ( int i = 0 ; i < ans.size() ; i += 2 ) {
		int x[] = { ans [ i ].first, ans [ i ].second, ans [ i + 1 ].first, ans [ i + 1 ].second} ;
		sort( x , x + 4 ) ;
		//for ( int i = 0 ; i < 4 ; i ++ ) cout << x [ i ] << ' ' ;
		//cout << endl ;
		if ( x [ 0 ] == x [ 1 ] ) cout << x [ 2 ] << ' ' << x [ 0 ] << ' ' << x [ 3 ] << '\n' ;
		else if ( x [ 1 ] == x [ 2 ] ) cout << x [ 0 ] << ' ' << x [ 1 ] << ' ' << x [ 3 ] << '\n' ;
		else cout << x [ 0 ] << ' ' << x [ 2 ] << ' ' << x [ 1 ] << '\n' ;
	} 
}
