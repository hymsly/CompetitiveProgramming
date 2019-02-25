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
map<int,int> M;
int n,k;

int main(){
	//fast_io()
	int t;cin>>t;
	while(t--){
		M.clear();
		cin>>n>>k;
		int cnt;
		vector< vector<int> > v(n);
		for(int i=0;i<n;i++){
			cin>>cnt;
			v[i].resize(cnt);
			for(int j=0;j<cnt;j++){
				cin>>v[i][j];
				M[v[i][j]]++;
			}
		}
		if(sz(M)<k) cout<<"sad\n";
		else{
			bool okok=0;
			for(int i=0;i<n;i++){
				bool ok=1;
				for(int j=0;j<sz(v[i]);j++){
					if(M[v[i][j]]==1){
						ok=0;
						break;
					}
				}
				if(ok){
					okok=1;
					cout<<"some\n";
					break;
				}
			}
			if(!okok) cout<<"all\n";
		}
	}
	
	return 0;
}

