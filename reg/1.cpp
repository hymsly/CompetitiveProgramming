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
	for(int i=0;i<n;i++) cin>>v[i];
	int mini=1000000;
	for(int mask=0;mask<(1<<n);mask++){
		int val=0;
		for(int j=0;j<n;j++){
			if(mask & (1<<j)){
				val+=v[j];
			}else val-=v[j];
		}
		mini=min(mini,abs(val));
	}
	cout<<mini<<endl;
	
	return 0;
}

