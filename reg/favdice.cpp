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

int main(){
	//fast_io()
	int t;cin>>t;
	int n;
	while(t--){
		cin>>n;
		double ans=0;
		for(int i=1;i<=n;i++){
			ans+=(1.0/(double)i);
		}
		ans*=n;
		printf("%.2f\n",ans);
	}
	
	return 0;
}

