#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (5e4);

int n;

map< pair<int,int> ,int > star;
vector<int> G[N+2];
int memo[N+2][2];
bool vis[N+2];
vector<int> tree[N+2];

int dp(int x,int add){
	if(memo[x][add]!=-1) return memo[x][add];
	int &ans = memo[x][add] = 0;
	if(add) ans++;
	for(int i=0;i<tree[x].size();i++){
		ans += dp(tree[x][i],1-add);
	}
	return ans;
}

void dfs(int x){
	vis[x] = 1;
	for(int i=0;i<G[x].size();i++){
		int p = G[x][i];
		if(vis[p]) continue;
		dfs(p);
		tree[x].push_back(p);
	}
}

ll sqr(ll x){
	return x*x;
}

ll dist(ll x,ll y,ll xx,ll yy){
	return sqr(x-xx)+sqr(y-yy);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	while(cin>>n){
		star.clear();
		for(int i=0;i<n;i++) G[i].clear(),tree[i].clear();
		memset(vis,0,sizeof vis);
		memset(memo,-1,sizeof memo);
		vector< pair<int,int> > v(n);
		for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
		for(int i=0;i<n;i++) star[v[i]]=i;
		for(int i=0;i<n;i++){
			for(int k=-5;k<=5;k++){
				for(int l=-5;l<=5;l++){
					int xx = v[i].first+k;
					int yy = v[i].second +l;
					if(xx==v[i].first && yy==v[i].second)continue;
					if(dist(xx,yy,v[i].first,v[i].second)<=25 && star.count(make_pair(xx,yy))){
						G[i].push_back(star[make_pair(xx,yy)]);
						G[star[make_pair(xx,yy)]].push_back(i);
					}
				}
			}
		}
		vector<int> roots;
		for(int i=0;i<n;i++){
			if(!vis[i]){
				roots.push_back(i);
				dfs(i);
			}
		}
		int ans = 0;
		for(int i=0;i<roots.size();i++){
			ans += min(dp(roots[i],1),dp(roots[i],0));
		}
		cout<<ans <<'\n';
	}

	return 0;
}

