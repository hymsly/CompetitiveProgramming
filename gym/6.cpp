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
	int n,k,m;
	cin>>n>>m>>k;
	int val = (7*n)/10 + ((7*n)%10 > 0) - k;
	if(val < 0) val=0;
	if(val > n-m) val=-1;
	cout<<val<<endl;
	cout<<(100*(k+n-m))/n<<endl;
	
	return 0;
}

