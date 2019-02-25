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

vector<ll> pr,ex;
void f(ll x){
	for(ll i=2;i*i<=x;i++){
		ll cnt=0;
		while(x%i==0){
			cnt++;x/=i;
		}
		if(cnt){
			pr.pb(i);
			ex.pb(cnt);
		}
	}
	if(x>1){
		pr.pb(x);
		ex.pb(1);
	}
}

vector< ll > getdivisors( ll x ){
	vector< ll > divisors( 1 , 1 );
	for ( int i = 0 ; i < (int)pr.size() ; i++ ){
				int m = (int)divisors.size();
		for ( int j = 0 ; j < ex[ i ]; j++ ){

			for ( int k = 0 ; k < m; k++ ) divisors.push_back( divisors[ m*j + k ]*pr[ i ] );
		}
	} 
	sort(divisors.begin(),divisors.end());
	return divisors;
}


int main(){
	//fast_io()
	ll n,k;
	cin>>n>>k;
	if(k>=1000000LL){
		cout<<-1<<endl;
	}else{
		if(2*n<(k*(k+1))){
			cout<<-1<<endl;
		}else{
			f(n);
			vector<ll> divisors = getdivisors(n);
			/*for(int i=0;i<divisors.size();i++){
				cout<<divisors[i]<<(char)(i+1==divisors.size()?10:32);
			}*/
			ll val = n/((k*(k+1))/2);
			int pos = upper_bound(divisors.begin(),divisors.end(),val)-divisors.begin();
			pos--;
			ll gcd = divisors[pos];
			vector<ll> ans(k);
			ll sum = 0;
			for(ll i=0;i<k;i++){
				ans[i] = (i+1)*gcd;
				sum += ans[i];
			}
			if(sum<n){
				ans[k-1] +=(n-sum); 
			}
			for(int i=0;i<k;i++) cout<<ans[i]<<(char)(i+1==k?10:32);
		}
	}
	
	return 0;
}

