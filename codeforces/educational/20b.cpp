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
const int INF=(1e9);


int main(){
	//fast_io()
	int n;cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	vector<int> zero;
	for(int i=0;i<n;i++){
		if(v[i]==0) zero.pb(i);
	}
	int pos=0;
	for(int i=0;i<n;i++){
		int d1=INF,d2=INF;
		if(pos>0) d1 = i-zero[pos-1];
		if(pos<zero.size()){
			d2 = zero[pos]-i;
			if(i==zero[pos]) pos++;
		}
		cout<<min(d1,d2)<<(char)(i+1==n?10:32);
	}
	
	return 0;
}

