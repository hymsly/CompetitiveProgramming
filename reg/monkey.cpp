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

vector<int> v;

bool f(int x){
	int pos=0;
	for(int i=0;i<v.size();i++){
		if(v[i]-pos>x) return false;
		else if(v[i]-pos==x) x--;
		pos=v[i];
	}
	return true;
}

int main(){
	//fast_io()
	int t;cin>>t;
	int n;
	int caso=0;
	while(t--){
		cin>>n;
		v.resize(n);
		for(int i=0;i<n;i++) cin>>v[i];
		int lo=0,hi=(1e8);
		while(hi-lo>1){
			int mi=(lo+hi)/2;
			if(f(mi)) hi=mi;
			else lo=mi;
		}
		cout<<"Case "<<++caso<<": "<<hi<<endl;
	}
	
	return 0;
}

