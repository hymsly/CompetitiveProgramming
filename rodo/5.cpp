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

ll memo[70][5];
ll cnt[70][2];

string s;

ll dp(int pos,int menor){
	if(pos==s.size()) return 0;
	if(memo[pos][menor]!=-1) return memo[pos][menor];
	ll &ans = memo[pos][menor] = 0;
	if(menor){
		for(int i=0;i<2;i++){
			ans += (i*cnt[s.size()-pos-1][menor] + dp(pos+1,menor));
		}
	}else{
		for(int i=0;i<=s[pos]-'0';i++){
			ans += (i*cnt[s.size()-pos-1][i<s[pos]-'0'] + dp(pos+1,i<s[pos]-'0'));
		}
	}
	return ans;
}

void pro(ll x){
	ll ans1=0;
	ll ans2=1;
	cnt[0][0] = ans1+1;
	cnt[0][1] = ans2;
	int pos=1;
	while(x){
		ll xd =x%2;
		ans1+=xd*ans2;
		ans2*=2;
		cnt[pos][0] = ans1+1;
		cnt[pos][1] = ans2;
		pos++;
		x/=2;
	}
}

string tos(ll t){
	string ans="";
	while(t>0){
		ans.pb(t%2+'0');
		t/=2;
	}
	reverse(all(ans));
	return ans;
}

int main(){
	//fast_io()
	ll a,b;
	while(cin>>a>>b){
		ll val1=0,val2=0;
		if(b>0){
			memset(memo,-1,sizeof(memo));
			memset(cnt,0,sizeof(cnt));
			pro(b);
			s = tos(b);
			val1 = dp(0,0);
		}
		if(a>1){
			a--;
			memset(memo,-1,sizeof(memo));
			memset(cnt,0,sizeof(cnt));
			pro(a);
			s = tos(a);
			val2 = dp(0,0);
		}
		cout<<val1-val2<<endl;
	}
	
	return 0;
}

