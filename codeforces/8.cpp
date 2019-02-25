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

string f(string x){
	if(x[1]!='z'){
		x[1]++;
		return x;
	}else{
		x[0]++;
		x[1]='a';
		return x;
	}
}

int main(){
	//fast_io()
	int n,k;cin>>n>>k;
	vector<string> v(n);
	string val="Aa";
	for(int i=0;i<k-1;i++){
		v[i]=val;
		val=f(val);
	}
	string s;
	for(int i=k-1;i<n;i++){
		cin>>s;
		if(s=="YES"){
			v[i]=val;
			val=f(val);
		}else{
			v[i]=v[i-k+1];
		}
	}
	for(int i=0;i<n;i++){
		cout<<v[i]<<(char)(i==n-1?10:32);
	}
	return 0;
}

