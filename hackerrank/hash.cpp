#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = (1e9 + 7);
const int B = 29;
const int N = 200000;

unordered_map<ll,int> H;//cantidad
unordered_map<ll,int> L;//inicial del string
vector<int> G[N+2];
int A[26];
string s,x;
void clear(){
	H.clear();
	L.clear();
	for(int i=0;i<=N;i++) G[i].clear();
	memset(A,0,sizeof A);
}


ll pot[N+2];
void init(){
	pot[0] = 1;
	for(int i=1;i<=N;i++){
		pot[i] = pot[i-1]*B;
		pot[i] %= MOD;
	}
}

void get(){
	int len = x.size();
	ll val = 0;
	for(int i=0;i<len;i++){
		val += pot[len-i-1]*(s[i]-'a');
		val %= MOD;
	}
	H[val]++;
	L[val] = 0;
	for(int i=len;i<s.size();i++){
		val -= pot[len-1]*(s[i-len]-'a');
		val %= MOD;
		val += MOD;
		val %= MOD;
		val *= B;
		val %= MOD;
		val += (s[i]-'a');
		val %= MOD;
		H[val]++;
		L[val] = i-len+1;
	}
}

bool comp(int a,int b){
	for(int i=0;i<x.size();i++){
		if(s[i+a] < s[i+b]) return true;
		else if(s[i+b] > s[i+1]) return false;
	}
    return false;
}

bool ok(int p){
	int C[26];
	for(int i=0;i<26;i++) C[i] = A[i];
	for(int i=0;i<x.size();i++){
		C[s[i+p]-'a']--;
	}
	for(int i=0;i<26;i++){
		if(C[i]!=0) return false;
	}
	return true;
}

int search(int rep){
	vector<int> ans;
	for(int i=0;i<G[rep].size();i++){
		int ini = G[rep][i];
		if(ok(ini)){
			ans.push_back(ini);
		}
	}
	if(ans.size()){
		sort(ans.begin(),ans.end(),comp);
		/*cout<<"se repite "<<rep<<" veces\n";
		for(int i=0;i<ans.size();i++) cout<<ans[i]<<(char)(i+1==ans.size()?10:32);*/
		return ans[0];
	}else{
		return -1;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	init();
	int t;cin>>t;
	string a,b;
	while(t--){
		cin>>x>>s;
		clear();
		for(int i=0;i<x.size();i++) A[x[i]-'a']++;
		get();
		unordered_map<ll,int> :: iterator it;
		for(it=H.begin();it!=H.end();it++){
			G[(*it).second].push_back(L[(*it).first]);
		}
		int res = -1;
		for(int i=200000;i>=0;i--){
			if(G[i].size()){
				res = search(i);
				if(res != -1) break;
			}
		}
		cout<<(res==-1?"-1":s.substr(res,x.size()))<<'\n';
	}

	return 0;
}

