#include<stdio.h>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
#define len(v) int((v).size())
map<int,int> m ;
vector<int> v [ 65537 ] ;
int n , N , e , a , b ;
int query ( int l , int r , int mi ){
	int res = 0 ;
	for ( l += N , r += N ; l < r ; l >>= 1 , r >>= 1 ) {
		if ( l & 1 ) {
			res += lower_bound ( v [ l ] .begin() , v [ l ] .end() , mi ) - v [ l ] .begin() ;
			l ++ ;
		}
		if ( r & 1 ) {
			r -- ;
			res += lower_bound ( v [ r ] .begin() , v [ r ] .end() , mi ) - v [ r ] .begin() ;
		}
	}
	return res ;
}
int main(){
	scanf ( "%d" , & n ) ;
	N = 1 ;
	while ( N < n ) N <<= 1 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		scanf ( "%d" , &e ) ;
		if ( m.count ( e ) == 0 ) v [ i + N ] . push_back ( -1 ) ;
		else v [ i + N ] . push_back ( m [ e ] ) ;
		m [ e ] = i ;
	}
	int x , y ;
	for ( int k = N - 1 ; k > 0 ; k -- ) {
		x = y = 0 ;
		while ( x < len( v [ k << 1 ] ) && y < len ( v [ k << 1 | 1 ] ) ){
			if ( v [ k << 1 ] [ x ] < v [ k << 1 | 1 ] [ y ] ) v [ k ] . push_back ( v [ k << 1 ] [ x ] ) , x ++ ;
			else if ( v [ k << 1 ] [ x ] > v [ k << 1 | 1 ] [ y ] ) v [ k ] . push_back ( v [ k << 1 | 1 ] [ y ] ) , y ++ ;
			else v [ k ] . push_back ( v [ k << 1 | 1 ] [ y ] ), v [ k ] . push_back ( v [ k << 1 ] [ x ] ) , y ++ , x ++ ;
		}
		if ( x == len ( v [ k << 1 ] ) ) while ( y < len ( v [ k << 1 | 1 ] ) ) v [ k ] .push_back ( v [ k << 1 | 1 ] [ y ] ) , y ++ ;
		if ( y == len ( v [ k << 1 | 1 ] ) ) while ( x < len ( v [ k << 1 ] ) ) v [ k ] .push_back ( v [ k << 1 ] [ x ] ) , x ++  ;
	}
	scanf ( "%d" , & e ) ;	while ( e -- ) {
		scanf ( "%d %d" , & a , & b ) ;
		a-- ;
		printf( "%d\n" , query ( a , b , a ) ) ;
	}
	return 0 ;
}
