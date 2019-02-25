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
string s;
int caso=1;
void doit(){
	int pos=0;
	int val=0;
	for(int i=0;i<sz(s);i++){
		if(s[i]-'0'>val){
			pos=i;
			val = s[i] - '0';
		}else if(s[i]-'0'<val){
			s[pos]--;
			for(int i=pos+1;i<sz(s);i++){
				s[i]='9';
			}
			break;
		}
	}
	if(s[0]=='0') s= s.substr(1,sz(s));
	cout<<"Case #"<<caso++<<": "<<s<<endl;
}

int main(){
	//fast_io()
	int t;cin>>t;
	while(t--){
		cin>>s;
		doit();
	}

	
	return 0;
}

