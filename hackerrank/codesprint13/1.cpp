#include<bits/stdc++.h>

using namespace std;

bool vis[103];

int main(){
	int n;cin>>n;
	int num;
	for(int i=0;i<n;i++){
		cin>>num;
		vis[num]=1;
	}
	vector<int> v;
	for(int i=1;i<=n;i++) if(!vis[i]) v.push_back(i);
	for(int i=0;i<v.size();i++) cout<<v[i]<<(char)(i+1==v.size()?10:32);

	return 0;
}

