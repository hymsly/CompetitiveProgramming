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
string n,s;
ll memo[5][12][2];

ll dp(int pos1,int pos2,int menor){
	cout<<pos1<<" "<<pos2<<" "<<menor<<endl;
	if(pos2 == s.size()){
		if(pos1 == n.size()) return 1;
		else return 0;
	}
	//if(memo[pos1][pos2][menor]!=-1) return memo[pos1][pos2][menor];
	ll &ans = memo[pos1][pos2][menor] = 0;
	if(pos1<n.size()){
		if(menor){
			for(int i=0;i<10;i++){
				if(i+'0' == n[pos1]) ans += dp(pos1+1,pos2+1,1);
				else ans += dp(pos1,pos2+1,1);
			}
		}else{
			for(int i=0;i<=s[pos2]-'0';i++){
				if(i+'0' == n[pos1]) ans += dp(pos1+1,pos2+1,i < s[ pos2 ]-'0');
				else ans += dp(pos1,pos2+1,i < s[ pos2 ]-'0');
			}
		}
	}else{
		if(menor){
			for(int i=0;i<10;i++){
				ans += dp(pos1,pos2+1,1);
			}
		}else{
			for(int i=0;i<=s[pos2]-'0';i++){
				ans += dp(pos1,pos2+1,i < s[ pos2 ]-'0');
			}
		}
	}
	return ans;
}

long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}

string prev(string x){
	ll 	cte = toi(x);
	cte--;
	return tos(cte);
}

int main(){
	//fast_io()
	string a,b;
	while(cin>>a>>b>>n){
		memset(memo,-1,sizeof(memo));
		if(n=="-1" && a=="-1" && b=="-1") break;
		if(n=="0"){
			
		}else{
			s = b;
			ll val1 = dp(0,0,0);
			ll val2 = 0;
			if(a!="0"){
				s = prev(a);
				memset(memo,-1,sizeof(memo));
				val2 = dp(0,0,0);
			}
			cout<<val1<<" "<<val2<<endl;
			cout<<val1-val2<<endl;
		}
	}
	
	return 0;
}

