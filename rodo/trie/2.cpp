#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int trie[100005][26];
int cnt[100005][26];
int nodo;

void limpiar(){
	memset(trie,0,sizeof trie);
	memset(cnt,0,sizeof cnt);
	nodo = 1;
}

void addWord(string s){
	//cout<<"agregando..."<<s<<endl;
	int n = s.size();
	int numNodo = 0;
	for(int i=0;i<n;i++){
		cnt[numNodo][s[i]-'A']++;
		if(trie[numNodo][s[i]-'A']){
			numNodo = trie[numNodo][s[i]-'A'];
		}else{
			trie[numNodo][s[i]-'A'] = nodo;
			numNodo = nodo++;
		}
	}
}

int cntPref(string s){
	//cout<<"analizando..."<<s<<endl;
	int n = s.size();
	int numNodo = 0;
	for(int i=0;i<n;i++){
		//cout<<trie[numNodo][s[i]-'A']<<" "<<cnt[numNodo][s[i]-'A']<<endl;
		if(trie[numNodo][s[i]-'A'] && cnt[numNodo][s[i]-'A']){
			//cout<<"entre\n";
			//cnt[numNodo][s[i]-'A']--;
			numNodo = trie[numNodo][s[i]-'A'];
		}else return i;
	}
	return n;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	while(cin>>n){
		if(n==-1) break;
		limpiar();
		string s;
		for(int i=0;i<n;i++){
			cin>>s;
			addWord(s);
		}
		int ans = 0;
		vector<string> v(n);
		for(int i=0;i<n;i++) cin>>v[i];
		sort(v.rbegin(),v.rend());
		for(int i=0;i<n;i++){
			ans += cntPref(v[i]);
		}
		cout<<ans<<'\n';
	}

	return 0;
}

