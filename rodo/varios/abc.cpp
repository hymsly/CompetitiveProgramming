#include<bits/stdc++.h>

using namespace std;
int n,m;

int A[55][55];
bool vis[55][55];

void clear(){
	memset(A,-1,sizeof A);
	memset(vis,0,sizeof vis);
}

int dx[]={1,1,1,-1,-1,-1,0,0},dy[]={0,1,-1,0,1,-1,-1,1};

int dfs(int x,int y,int pos){
	//cout<<x<<" "<<y<<" "<<pos<<endl;
	int ans = 1;
	vis[x][y] = 1;
	for(int i=0;i<8;i++){
		int xx = x+dx[i];
		int yy = y+dy[i];
		if(xx <=0 || xx > n || yy<=0 || yy>m) continue;
		if(vis[xx][yy]) continue;
		if(A[xx][yy]==pos+1) ans = max(ans,1+dfs(xx,yy,pos+1));
	}
	return ans;
}
int caso;

int main(){
	while(cin>>n>>m){
		if(n==0 && m==0) break;
		clear();
		char letra;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>letra;
				A[i][j] = letra-'A';
			}
		}
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) cout<<A[i][j]<<(char)(j==m?10:32);
		}*/
		int ans = 0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(A[i][j]==0) ans = max(ans,dfs(i,j,0));
			}
		}
		cout<<"Case "<<++caso<<": "<<ans<<'\n';
	}

	return 0;
}

