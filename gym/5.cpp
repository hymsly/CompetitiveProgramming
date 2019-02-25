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
const int N=(1e3);

char M[N+5][N+5];

int main(){
	//fast_io()
	int maxi=0;
	int cnt=0;
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin>>M[i][j];
	}
	int ok=1;
	for(int i=1;i<n;i++){
		if(ok){
			for(int j=1;j<=m;j++){
				if(M[i][j]=='.') cnt++;
				else if(M[i][j]=='L') cnt=0;
				maxi = max(maxi,cnt);
			}
			ok=1-ok;
		}else{
			for(int j=m;j>=1;j--){
				if(M[i][j]=='.') cnt++;
				else if(M[i][j]=='L') cnt=0;
				maxi = max(maxi,cnt);
			}
			ok=1-ok;
		}
	}
	cout<<maxi<<endl;
	
	return 0;
}

