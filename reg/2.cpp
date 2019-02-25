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
string F[105];
ull f[105];

int main(){
	//fast_io()
	F[0] = "0";
	F[1] = "1";
	f[0] = 1;
	f[1] = 1;
	for(int i=2;i<=92;i++){
		//F[i] = F[i-1] + F[i-2];
		f[i] = f[i-1] + f[i-2];
	}
	cout<<f[92]<<endl;
	//cout<<sz(F[20])<<endl;
	
	return 0;
}

