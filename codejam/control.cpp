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
int caso;
int d,n;


void doit(){
	cin>>d>>n;
	double maxi = 0.0;
	int a,b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		maxi = max(maxi , (double)(d-a)/(double)b);
	}
	double ans = (double) d/maxi;
	printf("Case #%d: %.6f\n",++caso,ans);	
}


int main(){
	//fast_io()
	int t;cin>>t;
	while(t--){
		doit();
	}
	
	
	return 0;
}

