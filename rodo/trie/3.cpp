#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int trie[1000002][26];
int cnt[1000002];
bool word[1000002];
int nodo;

void limpiar(int x){
	memset(cnt,0,sizeof cnt);
	memset(word,0,sizeof word);
	memset(trie,0,sizeof trie);
}

void addWord(string s){
	int numNodo = 0;
	int n = s.size();
	for(int i=0;i<n;i++){
		if(trie[numNodo][s[i]-'a']){
			numNodo = trie[numNodo][s[i]-'a'];
			cnt[numNodo]++;
		}else{
			trie[numNodo][s[i]-'a'] = nodo;
			numNodo = nodo++;
			cnt[numNodo]++;
		}
	}
	word[numNodo] = 1;
}

bool oneWord(int u){
	return (cnt[u]==1);
}

bool manyOpt(int u){
	int ans = (word[u]);
	for(int i=0;i<26;i++){
		if(trie[u][i]) ans++;
	}
	if(ans>1) return true;
	else return false;
}

int needed(string s){
	int ans = 1;
	int n = s.size();
	int numNodo = trie[0][s[0]-'a'];
	for(int i=1;i<n;i++){
		bool ok=0;
		if(manyOpt(numNodo)){
			ans++;
			ok=1;
		}
		int antes = cnt[numNodo];
		numNodo = trie[numNodo][s[i]-'a'];
		int ahora = cnt[numNodo];
		if(oneWord(numNodo)){
			break;
		}
	}
	return ans;
}

int main(){
	int n;
	while(cin>>n){
		nodo = 1;
		vector<string> v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
			addWord(v[i]);
		}
		int ans = 0;
		for(int i=0;i<n;i++){
			//cout<<needed(v[i])<<(char)(i+1==n?10:32);
			ans += needed(v[i]);
		}
		printf("%.2f\n",(double)ans/(double)n + (1e-9));
		limpiar(n);
	}

	return 0;
}

