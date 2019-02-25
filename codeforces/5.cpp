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
	int d,m;
	for(int i=0;i<n;i++) cin>>v[i];
	cin>>d>>m;
	if(m>n) cout<<0<<endl;
	else{
		int ans=0;
		int pos=0;
		int tot=accumulate(v.begin(),v.begin()+m,0);
		while(true){
			if(tot==d) ans++;
			if(pos+m==n) break;
			tot+=v[pos+m];
			tot-=v[pos];
			pos++;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

