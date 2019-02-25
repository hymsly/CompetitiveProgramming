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

ll memo[15][105][105][5];
ll k;
string s;
ll pot[15];

ll dp(int pos,ll sum1,ll sum2,int menor){
	if(pos==s.size()){
		if(sum1%k==0 && sum2%k==0){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(memo[pos][sum1][sum2][menor]!=-1) return memo[pos][sum1][sum2][menor];
	ll &ans = memo[pos][sum1][sum2][menor] = 0;
	if(menor){
		for(ll i=0;i<10;i++){
			ans += (dp(pos+1,((sum1+i)%k+k)%k,((sum2+i*pot[s.size()-pos-1])%k+k)%k,menor));
		}
	}else{
		for(ll i=0;i<=s[pos]-'0';i++){
			ans += (dp(pos+1,((sum1+i)%k+k)%k,((sum2+i*pot[s.size()-pos-1])%k+k)%k,i<s[pos]-'0'));
		}
	}
	return ans;
}

void proces(){
	ll ans = 1;
	ans%=k;
	pot[0]=ans;
	for(int i=1;i<15;i++){
		ans*=10;
		ans%=k;
		pot[i] = ans; 
	}
}

string tos(ll t){stringstream st; st<<t;return st.str();}

int main(){
	//fast_io()
	ll a,b;
	int t;cin>>t;
	while(t--){
		cin>>a>>b>>k;
		if(k>=100){
			cout<<0<<endl;
			continue;
		}
		ll val1=0,val2=0;
		memset(memo,-1,sizeof(memo));
		memset(pot,0,sizeof(pot));
		proces();
		s = tos(b);
		val1 = dp(0,0,0,0);
		if(a>0){
			a--;
			memset(memo,-1,sizeof(memo));
			s = tos(a);
			val2 = dp(0,0,0,0);
		}
		cout<<val1-val2<<endl;
	}
	
	return 0;
}

