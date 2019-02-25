#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).rbegin(),(v).rend()
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
	vector<pii> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i].fi;
		v[i].se = i+1;
	}
	sort(all(v));
	if(n==1) cout<<1<<endl;
	else{
		if(v[0].fi == v[1].fi){
			cout<<"-1"<<endl;
		}else cout<<v[0].se<<endl;
	}
	
	return 0;
}

