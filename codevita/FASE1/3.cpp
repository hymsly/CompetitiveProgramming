#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define SZ(x) (int)x.size()
typedef long long ll;
vector<string> autoc;
int n,m;

vector<string> cut(string s){
	stringstream ss(s);
	string val;
	vector<string> ans;
	while(ss>>val){
		ans.pb(val);
	}
	return ans;
}

int dist(string &x,string &y){
	int len1 = x.size();
	int len2 = y.size();
	int dp[len1+1][len2+1];
	for(int i=0;i<=len1;i++)dp[i][0]=i;
	for(int i=0;i<=len2;i++)dp[0][i]=i;
	for(int i=1;i<=len1;i++){
		for(int j=1;j<=len2;j++){
			int costo;
			if(x[i-1]==y[j-1])costo=0;
			else costo = 1;
			dp[i][j] = min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+costo));
		}
	}
	return dp[len1][len2];
}

string corregir(string s){
	string ans = s;
	for(int i=0;i<n;i++){
		if(dist(s,autoc[i])<=3){
			ans = autoc[i];
			break;
		}
	}
	return ans;
}

string toLower(string &s){
	string ans = "";
	for(int i=0;i<SZ(s);i++) ans.pb(tolower(s[i]));
	return ans;
}

string getName(vector<string> &s){
	string ans = "";
	for(int i=0;i<SZ(s);i++){
		ans+=s[i];
		if(i+1!=SZ(s))ans+=" ";
	}
	return ans;
}

map<string,int> M;
int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	string s;
	cin>>n;
	autoc.resize(n);
	for(int i=0;i<n;i++) cin>>autoc[i];
	for(int i=0;i<n;i++) autoc[i]=toLower(autoc[i]);
	cin>>m;
	getline(cin,s);
	for(int i=0;i<m;i++){
		getline(cin,s);
		vector<string> cutter =cut(s);
		for(int i=0;i<SZ(cutter);i++) cutter[i]=corregir(toLower(cutter[i]));
		string name = getName(cutter);
		M[name]++;
	}
	map<string,int> :: iterator it;
	for(it=M.begin();it!=M.end();it++){
		cout<<(*it).first<<":"<<(*it).second<<'\n';
	}
	

	return 0;
}

