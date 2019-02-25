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
const ll N=(1e6);
bool is[N+5];
vector<ll> pr;
int main(){
	//fast_io()
	memset(is,1,sizeof(is));
	for(ll i=2;i*i<=N;i++){
		if(is[i]){
			for(ll j=i*i;j<=N;j+=i) is[j]=0;
		}
	}
	for(ll i=2;i<=N;i++){
		if(is[i]) pr.pb(i);
	}
	cout<<sz(pr)<<endl;
	
	return 0;
}

