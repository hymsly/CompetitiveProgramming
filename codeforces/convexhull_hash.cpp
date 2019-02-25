#include<bits/stdc++.h>
#define Vector Point
using namespace std;
typedef long long ll;
const ll MOD1 = (1e9+7);
const ll MOD2 = (1e9+9);

struct Point{
	ll x,y;
	Point(){}
	Point(ll _x,ll _y){
		x = _x;
		y = _y;
	}
	ll mod2(){
		return (x*x+y*y);
	}
};

Point operator +(const Point &a ,const Point &b){
	return Point(a.x+b.x,a.y+b.y);
}
Point operator -(const Point &a ,const Point &b){
	return Point(a.x-b.x,a.y-b.y);
}

bool operator <(const Point &a, const Point &b){
	if(a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

ll cross(const Vector &A, const Vector &B){
	return A.x * B.y - A.y * B.x;
}

ll area(const Point &A, const Point &B, const Point &C) {
	return cross(B - A, C - A);
}



vector <Point> ConvexHull(vector <Point> Poly){
	sort(Poly.begin(),Poly.end());
	int nP = Poly.size(),k = 0;
	Point H[ 2*nP ];
	for( int i = 0 ; i < nP ; ++i ){
	while( k >= 2 && area( H [ k - 2 ] , H[ k - 1 ] , Poly[ i] ) <= 0) --k;
		H[ k++ ] = Poly[ i ];
	}
	for( int i = nP - 2 , t = k ; i >= 0 ; --i ){
	while( k > t && area( H[ k - 2 ] , H[ k - 1 ] , Poly[ i ]) <= 0) --k;
		H[ k++ ] = Poly[ i ];
	}
	if( k == 0 )return vector <Point>();
	return vector <Point> ( H , H + k - 1 );
}

vector< pair< ll, pair<ll,ll> > > f(vector<Point> b){
	int len = b.size();
	vector< pair< ll, pair<ll,ll> > > ans;
	for(int i=0;i<len;i++){
		Point uno = b[i],dos = b[(i+1)%len],tres = b[(i-1+len)%len];
		//ans.push_back(make_pair((dos-uno).mod2(),make_pair((tres-uno).mod2(),(tres-dos).mod2())));
		ans.push_back(make_pair((dos-uno).mod2()-(tres-uno).mod2(),make_pair((tres-uno).mod2()+(dos-uno).mod2(),(tres-dos).mod2())));
	}
	return ans;
}

vector< ll > hashSum(vector< pair< ll, pair<ll,ll> > > v,ll mod){
	vector< ll > ans;
	for(int i=0;i<v.size();i++){
		v[i].first %= mod;
		v[i].first += mod;
		v[i].first %= mod;
		v[i].second.first %= mod;
		v[i].second.first += mod;
		v[i].second.first %= mod;
		v[i].second.second %= mod;
		v[i].second.second += mod;
		v[i].second.second %= mod;
	}
	for(int i=0;i<v.size();i++) ans.push_back((v[i].first + v[i].second.first + v[i].second.second)%mod);
	return ans;
}

vector< ll > hashMul(vector< pair< ll, pair<ll,ll> > > v,ll mod){
	vector< ll > ans;
	for(int i=0;i<v.size();i++){
		v[i].first %= mod;
		v[i].first += mod;
		v[i].first %= mod;
		v[i].second.first %= mod;
		v[i].second.first += mod;
		v[i].second.first %= mod;
		v[i].second.second %= mod;
		v[i].second.second += mod;
		v[i].second.second %= mod;
	}
	for(int i=0;i<v.size();i++) ans.push_back(((v[i].first*v[i].second.first)%mod*v[i].second.second)%mod);
	return ans;
}

vector<int> KMP(vector<ll> S,vector<ll> K){
	vector<int> T(K.size() + 1, -1);
    for(int i = 1; i <= K.size(); i++){
        int pos = T[i - 1];
        while(pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
        T[i] = pos + 1;
    }
    vector<int> matches;
    for(int sp = 0, kp = 0; sp < S.size(); sp++){
        while(kp != -1 && (kp == K.size() || K[kp] != S[sp]))
             kp = T[kp];
        kp++;
        if(kp == K.size()) matches.push_back(sp + 1 - K.size());
    }
    return matches;
}

int vis[400005];

bool eq(vector< pair< ll, pair<ll,ll> > > v1,vector< pair< ll, pair<ll,ll> > > v2){
	int len = v1.size();
	vector< ll > hashSum1 = hashSum(v1,MOD1);
	vector< ll > hashSum2 = hashSum(v2,MOD1);
	vector< ll > hashMul1 = hashMul(v1,MOD1);
	vector< ll > hashMul2 = hashMul(v2,MOD1);
	//duplico el 2do
	for(int i=0;i<len;i++) hashSum2.push_back(hashSum2[i]);
	for(int i=0;i<len;i++) hashMul2.push_back(hashMul2[i]);
	vector<int> kmp1 = KMP(hashSum2,hashSum1), kmp2 = KMP(hashMul2,hashMul1);
	for(int i=0;i<kmp1.size();i++) vis[kmp1[i]]++;
	for(int i=0;i<kmp2.size();i++) vis[kmp2[i]]++;
	
	vector< ll > hashSum3 = hashSum(v1,MOD2);
	vector< ll > hashSum4 = hashSum(v2,MOD2);
	vector< ll > hashMul3 = hashMul(v1,MOD2);
	vector< ll > hashMul4 = hashMul(v2,MOD2);
	//duplico el 2do
	for(int i=0;i<len;i++) hashSum4.push_back(hashSum4[i]);
	for(int i=0;i<len;i++) hashMul4.push_back(hashMul4[i]);
	vector<int> kmp3 = KMP(hashSum4,hashSum3), kmp4 = KMP(hashMul4,hashMul3);

	for(int i=0;i<kmp3.size();i++) vis[kmp3[i]]++;
	for(int i=0;i<kmp4.size();i++) vis[kmp4[i]]++;	
	
	for(int i=0;i<=3*len+3;i++){
		if(vis[i]==4) return true;
	}
	
	return false;
}

void show(vector< Point> x){
	cout<<"convex hull"<<endl;
	for(int i=0;i<x.size();i++) cout<<x[i].x<<" "<<x[i].y<<endl;
}

int main(){
	//ios_base::sync_with_stdio(0);
	int n,m;cin>>n>>m;
	vector< Point> p1(n),p2(m);
	for(int i=0;i<n;i++) cin>>p1[i].x>>p1[i].y;
	for(int i=0;i<m;i++) cin>>p2[i].x>>p2[i].y;		

	vector< Point> convex1=ConvexHull(p1),convex2=ConvexHull(p2);
	if(convex1.size() != convex2.size()) cout<<"NO\n";
	else{
		//show(convex1);
		//show(convex2);
		vector< pair< ll, pair<ll,ll> > > v1 = f(convex1);
		vector< pair< ll, pair<ll,ll> > > v2 = f(convex2);
		if(eq(v1,v2)) cout<<"YES\n";
		else cout<<"NO\n";
	}


	return 0;
}

