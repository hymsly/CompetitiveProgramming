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

map< int , int > M;

int main(){
	//fast_io()
	int n;
	while(cin>>n){
		M.clear();
		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
			M[v[i]-i]++;
		}
		map<int,int>:: iterator it;
		int maxi=0;
		int val=0;
		for(it=M.begin();it!=M.end();it++){
			if((*it).se>maxi) {maxi=(*it).se;val=(*it).fi;}
		}
		cout<<maxi<<endl;
		for(int i=0;i<n;i++){
			cout<<maxi+i<<(char)(i+1==n?10:32);
		}
	}
	
	return 0;
}

