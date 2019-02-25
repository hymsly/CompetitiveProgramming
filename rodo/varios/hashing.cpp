#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = (1e9+7);
const int N = (1e5);
const int B = 29;

ll M[N+2];
ll H[N+2];

ll POT(ll x,ll y){
	if(y==0) return 1;
	if(y==1) return x;
	ll ans = 1;
	if(y&1) ans = x;
	ll val = POT(x,y/2);
	ans *= val;
	ans %= MOD;
	ans *= val;
	ans %= MOD;
	return ans;
}

ll inv(ll x){
	return POT(x,MOD-2)%MOD;
}

ll Hpref(int i,int j){
	cout<<"string original "<<i<<" "<<j<<endl;
	return (((H[j]-H[i])%MOD+MOD)%MOD*inv(i))%MOD;
}
ll Mpref(int i,int j){
	cout<<"string inverso "<<i<<" "<<j<<endl;
	return (((M[j]-M[i])%MOD+MOD)%MOD*inv(i))%MOD;
}

void solve(string s){
	memset(M,0,sizeof M);
	memset(H,0,sizeof H);
	string w = s;
	reverse(s.begin(),s.end());
	int n = s.size();
	for(int i=1;i<=n;i++){
		M[i] = M[i-1]*B+(s[i-1]-'a'+1);
		H[i] = H[i-1]*B+(w[i-1]-'a'+1);
	}
	int ans = -1;
	for(int i=n;i>=1;i--){
		cout<<"verificando si los strings son iguales "<<s.substr(0,i)<<" "<<w.substr(n-i,i)<<endl;
		if(Hpref(n-i+1,n) == Mpref(1,i)){//si es palindrome
			ans = i;
			break;
		}
	}
	cout<<"maximo palindromo es:"<<ans<<endl;
	cout<<w;
	for(int i=n-ans-1;i>=0;i--) cout<<w[i];
	cout<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	string s;
	while(cin>>s) solve(s);

	return 0;
}

