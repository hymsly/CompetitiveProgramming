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
	int n;cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	int last = v[1];
	int di = v[1]-v[0];
	int cnt = 0;
	int ans=0;
	for(int i=2;i<n;i++){
		if((v[i]-last)*di > 0){
			cnt++;
		}else{
			ans+=(cnt);
			cnt=0;
			di = v[i]-last;
		}
		last = v[i];
	}
	ans+=cnt;
	cout<<ans<<endl;
	
	return 0;
}

