#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v[26];

int f(int x){
	int ans = 0;
	for(int i=1;i<v[x].size();i++){
		ans = max(ans,v[x][i]-v[x][i-1]);
	}
	return ans;
}

int main(){
	//ios_base::sync_with_stdio(0);
	string s;cin>>s;
	for(int i=0;i<26;i++) v[i].push_back(0);
	for(int i=0;i<s.size();i++){
		v[s[i]-'a'].push_back(i+1);
	}	
	for(int i=0;i<26;i++) v[i].push_back(s.size()+1);
	int mini = s.size();
	for(int i=0;i<26;i++){
		mini = min(mini,f(i));
	}
	cout<<mini<<'\n';

	return 0;
}

