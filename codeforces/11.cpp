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
ll val;
void f(string s){
	stringstream ss(s);
	ss>>val;
}

int main(){
	//fast_io()
	int n,k;cin>>n>>k;
	vector<ll> v(n+1);
	int win=-1;
	string s;
	for(int i=0;i<=n;i++){
		cin>>s;
		if(s=="?") win=i%2;
		f(s);
		v[i]=val;
	}
	if(win==0) cout<<"No"<<endl;
	else if(win==1) cout<<"Yes"<<endl;
	else{
		for(int i=n;i>0;i--){
			cout<<v[i]<<endl;
			v[i-1]+=(k*v[i]);
		}
		if(v[0]==0) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
	return 0;
}

