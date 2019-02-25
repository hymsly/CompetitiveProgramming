#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int trie[100005][10];
bool word[100005];
int nodo;

void limpiar(){
	nodo = 1;
	memset(trie,0,sizeof(trie));
	memset(word,0,sizeof(word));
}

bool addWord(string s){
	//cout<<"agregando..."<<s<<endl;
	int n = s.size();
	int numNodo = 0;
	bool ans = true;
	for(int i=0;i<n;i++){
		if(trie[numNodo][s[i]-'0']){
			numNodo = trie[numNodo][s[i]-'0'];
		}else{
			trie[numNodo][s[i]-'0'] = nodo;
			numNodo = nodo++;
		}
		//cout<<numNodo<<endl;
		if(word[numNodo]) ans = false;
	}
	word[numNodo] = true;
	return ans;
}

bool isPref(string s){
	int n = s.size();
	int numNodo=0;
	for(int i=0;i<n;i++){
		if(trie[numNodo][s[i] - '0']){
			numNodo = trie[numNodo][s[i]-'0'];
		}else return false;
	}
	return true;
}

int main(){
	//ios_base::sync_with_stdio(0);
	int t;cin>>t;
	int n;
	while(t--){
		limpiar();
		cin>>n;
		string s;
		bool ok=true;
		for(int i=0;i<n;i++){
			cin>>s;
			if(isPref(s)) ok=false;
			else ok &= addWord(s);
		}
		if(ok) cout<<"YES\n";
		else cout<<"NO\n";
	}

	return 0;
}

