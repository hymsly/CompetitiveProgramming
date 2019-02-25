#include<bits/stdc++.h>
#define ll long long 
#define mp make_pair
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define REP(i,n) for(int i=0;i<n;i++)
#define F(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N = (5000);

int memo[N+2];

int gun(int x){
	if(x<1) return 0;
	if(memo[x] != -1) return memo[x];
	set<int> S;
	for(int i=0;i<x;i++){
		S.insert(gun(i-1)^gun(x-i-2));
	}
	int ans = 0;
	while(S.find(ans)!=S.end()) ans++;
	return memo[x] = ans;
}

int gundy(string s){
	if(s.size()<3) return 0;
	int n = s.size();
	int so = 0;
	//cout<<"tamaño "<<n<<endl;
	for(int i=1;i<n-1;i++){
		if(s[i-1]!=s[i+1]) continue;
		int j=i;
		while(j<n-1){
			if(s[j-1]!=s[j+1]) break;
			j++;
		}
		//cout<<"-----"<<i<<" "<<j<<endl;
		so^=gun(j-i);
		i = j;
	}
	return so;
}

int main(){
	memset(memo,-1,sizeof memo);
	string s;
	cin>>s;
	int ans = gundy(s);
	
	if(ans==0){
		cout<<"Second"<<endl;
	}
	else{
		cout<<"First"<<endl;
		for(int i=1;i<s.size()-1;i++){
			if(s[i-1] == s[i+1]){//es posible
				int p = gundy(s.substr(0,i)),q = gundy(s.substr(i+1,s.size()-i-1));
				if(p==q){
					cout<<i+1<<'\n';
					break;
				}
			}
		}
	}
	
	
	return 0;
	
}
