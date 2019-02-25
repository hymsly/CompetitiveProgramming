#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=(1e6);
const ll M=(1e5);
bool pr [ N+1 ] ;
multiset<int> d [ M+1 ] ; 
ll m [ M+1 ]  , xd [ M+1 ] ; 
vector<ll> v ;
ll a , b  , r ;
ll cnt ;
int main(){
	ios_base::sync_with_stdio(0);
	for ( int i = 2 ; i * i <= N ; i ++ ){
		if ( ! pr[ i ] ){
			for ( int j = i * i ; j <= N ; j += i ) pr[ j ] = true;
		}
	}
	for ( int i = 2 ; i < N ; i ++ ){
		if ( ! pr[ i ] ) v.push_back(i);
	}
	cin >> a >> b ;
	for ( int i = 0 ; i <= M ; i ++ ){
		m [ i ] = 1 , xd [ i ] = i + a ;
	}
	for ( int i = 0 ; i < v.size() ; i++ ) {
		r = ( a / v [ i ] ) * v [ i ] ;
		if ( r < a ) r += v [ i ] ;
		for ( ; r <= b ; r += v [ i ] ) {
			cnt = 1 ;
			ll pos = r - a;
			while ( xd [ pos ] % v [ i ] == 0 ){
				xd [ pos ] /= v [ i ] ;
				cnt ++ ;
			}
			d [ pos ] .insert ( cnt ) ;
			m [ pos ] *= cnt ;
		}
	}
	for ( ll i = 0 ; i <= b - a ; i ++ ){
		if ( xd [ i ] > 1 ) {
			d[ i ].insert(2LL) ;
			m[ i ]*=2LL;
		}
	}
	ll ans=0;
	for ( ll i=0;i<=b-a;i++) {
		while ( !d[ i ].empty () ) {
			ll x=*(d [ i ].rbegin()) ;
			ans+=m[ i ] ;
			m [ i ]/= x ;
			d [ i ].erase( d [ i ] .find ( x -- ) ) ;
			if ( x > 1 ){
				d[ i ].insert ( x );
				m[ i ]*= x ;
			}
		}
	}
	cout<<ans<<'\n';
}
