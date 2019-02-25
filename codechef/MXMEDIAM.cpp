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
		vector<int> v(2*n);
		vector<int> a(n),b(n);
		for(int i=0;i<2*n;i++){
			cin>>v[i];
		}
		sort(all(v));
		int ans = (n+1)/2;
		for(int i=0;i<n;i++) a[i] = v[i];
		for(int i=0;i<n;i++) b[i] = v[2*n-i-1];
		cout<<b[ans-1]<<endl;
		for(int i=0;i<n;i++){
			cout<<a[i]<<" "<<b[i]<<(char)(i+1==n?10:32);
		}
	}
	
	return 0;
}

