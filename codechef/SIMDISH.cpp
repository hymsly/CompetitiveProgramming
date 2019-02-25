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

map<string,int> M;

bool is(){
	map<string,int> :: iterator it;
	int cnt=0;
	for(it=M.begin();it!=M.end();it++){
		if((*it).se==2) cnt++;
	}
	if(cnt>=2) return true;
	else return false;
}

int main(){
	//fast_io()
	int t;cin>>t;
	while(t--){
		M.clear();
		string s;
		for(int i=0;i<8;i++){
			cin>>s;
			M[s]++;
		}
		if(is()) cout<<"similar\n";
		else cout<<"dissimilar\n";
	}
	
	
	return 0;
}

