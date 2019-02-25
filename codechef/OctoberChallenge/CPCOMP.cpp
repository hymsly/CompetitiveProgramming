#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (5000);

int pa[N+2];

int Find(int x){
	return (pa[x]==x?x:pa[x]=Find(pa[x]));
}

void Union(int x,int y){
	pa[Find(x)] = Find(y);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n;cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	for(int i=0;i<n;i++) pa[i]=i;
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++) if(__gcd(v[i],v[j])==1)Union(i,j);
	set<int> S;
	for(int i=0;i<n;i++) S.insert(Find(i));
	cout<<S.size()<<'\n';

	return 0;
}

