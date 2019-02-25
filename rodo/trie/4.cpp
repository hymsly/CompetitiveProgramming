#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int trie[100002][26];
int memo[100002];
int nodo = 1;

void addWord(string s){
	int n = s.size();
	int u = 0;
	for(int i=0;i<n;i++){
		if(trie[u][s[i]-'a']){
			u = trie[u][s[i]-'a'];
		}else{
			trie[u][s[i]-'a'] = nodo;
			u = nodo++; 
		}
	}
}

int dp(int x){
	if(memo[x] != -1) return memo[x];
	int &ans = memo[x] = 0;
	set<int> S;
	for(int i=0;i<26;i++){
		if(trie[x][i]){
			S.insert(dp(trie[x][i]));
		}
	}
	while(S.find(ans)!=S.end()){
		ans++;
	}
	return ans;
}

void rec(int x){
	cout<<x<<" "<<memo[x]<<endl;
	for(int i=0;i<26;i++){
		if(trie[x][i]) rec(trie[x][i]);
	}
}

int main(){
	//ios_base::sync_with_stdio(0);
	int n,k;
	cin>>n>>k;
	memset(memo,-1,sizeof memo);
	vector< string > v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
		addWord(v[i]);
	}
	int gundy = dp(0);
	cout<<gundy<<endl;
	if(k==1){
		if(gundy==1) cout<<"First\n";
		else cout<<"Second\n";
	}else{
		if(gundy==1){
			if(k%2==1) cout<<"First\n";
			else cout<<"Second\n";
		}else if(gundy==0){
			cout<<"Second\n";
		}else{
			cout<<"First\n";
		}
	}
	rec(0);

	return 0;
}

