#include<bits/stdc++.h>

using namespace std;
int n,m;
int M[25][25];
char G[25][25];
int dx[]={1,0,0,-1},dy[]={0,-1,1,0};
int cnt[500];
char land;

void clear(){
	memset(M,-1,sizeof M);
	memset(G,' ',sizeof G);
	memset(cnt,0,sizeof cnt);
}

void dfs(int x,int y,int t){
	M[x][y] = t;
	for(int i=0;i<4;i++){
		int xx = x+dx[i], yy=y+dy[i];
		yy%=m;
		if(yy==-1)yy=m-1;
		if(xx>=0 && x<n) if(G[xx][yy]==land) if(M[xx][yy]==-1) dfs(xx,yy,t);
	}
}

int main(){
	while(cin>>n>>m){
		clear();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++) cin>>G[i][j];
		}
		int x,y;cin>>x>>y;
		land = G[x][y];
		int val=0;
		//cout<<x<<" "<<y<<endl;
		//cout<<"land----"<<land<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(M[i][j]==-1 && G[i][j]==land) dfs(i,j,val++);
			}
		}
		int pos = M[x][y];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(M[i][j]!=-1) cnt[M[i][j]]++;
			}
		}
		//for(int i=0;i<n;i++){
			//for(int j=0;j<m;j++) cout<<M[i][j]<<(char)(j+1==m?10:32);
		//}
		int res = 0;
		for(int i=0;i<40;i++){
			if(i==pos) continue;
			res = max(res,cnt[i]);
		}
		cout<<res<<'\n';
	}

	return 0;
}

