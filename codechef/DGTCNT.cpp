#include<bits/stdc++.h>
using namespace std;
#define mp(x,y) make_pair((x),(y))
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
int n;
string s;

map< pair < pair < int , int > , pair< int,vector<ll> > > , ll> memo;

ll dp( int pos , vector<ll> v , int menor ,int left){
	if ( pos == n ){
		ll ans=1;
		for(int i=0;i<10;i++) ans*=v[i];
		if(ans==0) return 0;
		else return 1;
	}
	pair < pair < int , int > , pair<int,vector<ll> > > p = mp( mp(pos ,menor),mp(left,v));
	if ( memo.find( p ) != memo.end() ) return memo[ p ];
	ll ans=0;
	if ( menor ){
		for ( int i = 0 ; i < 10 ; i++ ){
			vector<ll> aux = v;
			if(!left || i!=0) aux[i]--;
			ans += dp( pos + 1 , aux , 1 ,left && (i==0));
		}
	}else{
		for ( int i = 0 ; i <= s[ pos ]-'0' ; i++){
			vector<ll> aux = v;
			if(!left || i!=0) aux[i]--;
			ans += dp( pos + 1 , aux , i < s[ pos ]-'0' ,left && (i==0));
		}
	}
	memo[p] = ans;
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
	fast_io()
	int t;cin>>t;
	string a,b;
	while(t--){
		memo.clear();
		cin>>a>>b;
		vector<ll> v(10);
		for(int i=0;i<10;i++) cin>>v[i];
		n = b.size();
		s = b;
		ll ans1 = dp(0,v,0,1);
		memo.clear();
		a = prev(a);
		s = a;
		n=a.size();
		ll ans2 = dp(0,v,0,1);
		cout<<ans1-ans2<<'\n';
	}
	
	return 0;
}

