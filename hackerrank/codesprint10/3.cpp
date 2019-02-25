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
const int N=(1e5);


bool us[N+5];

string f(ll x){
	string ans="";
	for(int i=0;i<60;i++){
		ans.pb(x%2 + '0');
		x/=2;
	}
	reverse(all(ans));
	return ans;
}

ll fact[N+5];
const ll MOD=(1e9+7);

ll pot(ll x,ll y){
	if(y==0) return 1LL;
	if(y==1) return x;
	ll val = pot(x,y/2);
	ll ans=1;
	if(y&1) ans*=x;
	ans*=val;
	ans%=MOD;
	ans*=val;
	ans%=MOD;
	return ans;
}

ll inv(ll x){
	return pot(x,MOD-2)%MOD;
}

ll C(ll x,ll y){
	return ( ( ( fact[x]*inv( fact[y] ) ) % MOD ) * inv( fact[x-y] ) ) % MOD;
}

int main(){
	//fast_io()
	fact[0]=1;
	for(ll i=1;i<=N;i++){
		fact[i]=(i*fact[i-1])%MOD;
	}
	int n,k;
	cin>>n>>k;
	vector<ll> v(n);
	vector<string> s(n);
	for(int i=0;i<n;i++) cin>>v[i];
	for(int i=0;i<n;i++){
		s[i] = f(v[i]);
	}
	vector<int> ans(60);
	int posi = n;
	for(int i=0;i<60;i++){
		int cnt=0;
		for(int j=0;j<n;j++){
			if(us[j]) continue;
			if(s[j][i]=='1'){
				cnt++;
			}
		}
		if(cnt<k){
			ans[i]=0;
		}else{
			ans[i]=1;
			for(int j=0;j<n;j++){
				if(us[j]) continue;
				if(s[j][i]=='0'){
					us[j]=1;
					posi--;
				}
			}
		}
	}
	ll res=0;
	for(int i=0;i<60;i++){
		res*=2;
		res+=ans[i];
	}
	cout<<res<<endl;
	cout<<C(posi,k)<<endl;
	
	
	return 0;
}

