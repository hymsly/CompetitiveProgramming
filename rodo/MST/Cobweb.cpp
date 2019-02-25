#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (1e5);

pair<int,int> D[N+2];

bool used[N+2];
int ans;
int pa[N+2];
int Find(int x){
	return (pa[x]==x?x:pa[x]=Find(pa[x]));
}

void Union(int x,int y){
	int xx = Find(x),yy = Find(y);
	if(xx == yy) return;
	ans--;
	pa[xx] = yy;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) pa[i]=i;
	for(int i=1;i<=m;i++) cin>>D[i].first>>D[i].second;
	int q;cin>>q;
	vector<int> v(q);
	for(int i=0;i<q;i++)cin>>v[i],used[v[i]]=1;
	ans = n;
	for(int i=1;i<=m;i++) if(!used[i]) Union(D[i].first,D[i].second);
	vector<int> res;
	for(int i=q-1;i>=0;i--){
		res.push_back(ans);
		Union(D[v[i]].first,D[v[i]].second);
	}
	reverse(res.begin(),res.end());
	for(int i=0;i<res.size();i++) cout<<res[i]<<(char)(i+1==res.size()?10:32);

	return 0;
}

