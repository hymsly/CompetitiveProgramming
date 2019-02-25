#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> G[20];
bool GG[20][20];
ll dp[21][(1<<19)+2];
bool vis[21][(1<<19)+2];
int main(){
	int n,m;
	cin>>n>>m;
	long long res=0;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x--;y--;
		G[x].push_back(y);
		G[y].push_back(x);
		GG[x][y]=GG[y][x]=1;
	}
	for(int i=0;i<n;i++)sort(G[i].begin(),G[i].end());
	while(n>2){
		int a=n-1;
		for(int i=0;i<n;i++)for(int j=0;j<(1<<n);j++)vis[i][j]=dp[i][j]=0;
		dp[a][1<<a]=1;
		vis[a][1<<a]=1;
		queue<pair<int,int> > q;
		q.push({a,1<<a});
		while(!q.empty()){
			int x=q.front().first,mask=q.front().second;
			q.pop();
			for(int j:G[x]){
				if((mask>>j)&1)continue;
				int msk=mask^(1<<j);
				dp[j][msk]+=dp[x][mask];
				if(!vis[j][msk])vis[j][msk]=1,q.push({j,msk});
			}
		}
		long long ans=0;
		for(int i=0;i<a;i++)if(GG[i][a]){
			for(int mask=1;mask<(1<<n);mask++)if(dp[i][mask]>0){
				ans+=dp[i][mask];
			}
		}
		ans-=G[a].size();
		ans/=2;
		assert(ans>=0);
		for(int i=0;i<a;i++){
			if(G[i].size() && G[i].back()==a) G[i].pop_back();
		}
		G[a].clear();
		for(int i=0;i<n;i++) GG[i][a] = 0,GG[a][i] = 0;
		res+=ans;
		n--;
	}
	cout<<res<<endl;
}
