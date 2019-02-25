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

int is(pii a,pii b){
	return (sqr(b.fi - a.fi) + sqr(b.se - a.se));
}

int main(){
	//fast_io()
	int n;cin>>n;
	vector<pair<pii,int> > v(n);
	for(int i=0;i<n;i++){
		cin>>v[i].fi.fi>>v[i].fi.se>>v[i].se;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(is(v[i].fi , v[j].fi) == sqr(v[i].se + v[j].se)) cout<<i+1<<" "<<j+1<<endl;
		}
	}
	
	return 0;
}

