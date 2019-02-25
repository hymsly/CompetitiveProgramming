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
	int t;cin>>t;
	string s;
	while(t--){
		cin>>s;
		ll pos = sz(s);
		ll cnt=0;
		ll ans=0;
		for(int i=0;i<sz(s);i++){
			if(s[i]=='1') cnt++;
		}
		for(ll i=sz(s)-1;i>=0;i--){
			if(s[i]=='1'){
				if(i<pos-1) ans+=(cnt)*(pos-i);
				pos = i;
				cnt--;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

