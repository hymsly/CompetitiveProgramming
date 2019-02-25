#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(x) push_back(x)

#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
#define fi first
#define se second
#define sz(v) ((int)v.size())
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
int a1,a2,b1,b2;

int main(){
	//fast_io()
	string s;cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='A'){
			if(s[i+1]=='A') a1++;
			else a2++;
		}else{
			if(s[i-1]=='A') b1++;
			else b2++;
		}		
	}
	if(a1 == b2 && a2 == b1) cout<<"Sim"<<endl;
	else cout<<"Nao"<<endl;
	
	return 0;
}

