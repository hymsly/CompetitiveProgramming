#include<bits/stdc++.h>
using namespace std;
#define Vector Point
typedef long long ll;
typedef long double ld;
const ll MOD2 = (1e9+9);
const ll MOD1 = (1e9+7);
const ld EPS = (1e-9);

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
Point operator *(const Point &a,ll k){
	return Point(a.x*k,a.y*k);
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

vector< pair< ll, pair<ll,ll> > > f(vector<Point> b,ll multi){
	int len = b.size();
	vector< pair< ll, pair<ll,ll> > > ans;
	for(int i=0;i<len;i++){
		Point uno = b[i],dos = b[(i+1)%len],tres = b[(i-1+len)%len];
		ans.push_back(make_pair((dos-uno).mod2()*multi-(tres-uno).mod2()*multi,make_pair((dos-uno).mod2()*multi+(tres-uno).mod2()*multi,(tres-dos).mod2()*multi)));
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
        while(kp != -1 && (kp == K.size() || (K[kp] != S[sp]) /*abs(S[sp]*base - K[kp])>EPS*/  ))
             kp = T[kp];
        kp++;
        if(kp == K.size()) matches.push_back(sp + 1 - K.size());
    }
    return matches;
}

int vis[400005];
ld base,baseCua;

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

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n;cin>>n;
	vector<Point> v1(n),v2(n);
	for(int i=0;i<n;i++) cin>>v1[i].x>>v1[i].y;
	for(int i=0;i<n;i++) cin>>v2[i].x>>v2[i].y;
	ll area1 = 0;
	for(int i=1;i<n-1;i++) area1+=area(v1[0],v1[i],v1[i+1]);
	if(area1 < 0){
		area1 = -area1;
		for(int i=0;i<n/2;i++){
			swap(v1[i],v1[n-i-1]);
		}
	}
	ll area2 = 0;
	for(int i=1;i<n-1;i++) area2+=area(v2[0],v2[i],v2[i+1]);
	if(area2 < 0){
		area2 = -area2;
		for(int i=0;i<n/2;i++){
			swap(v2[i],v2[n-i-1]);
		}
	}
	ll gcd = __gcd(area1,area2);
	area1 /= gcd;
	area2 /= gcd;
	vector< pair< ll, pair<ll,ll> > > cmp1 = f(v1,area2);
	vector< pair< ll, pair<ll,ll> > > cmp2 = f(v2,area1);
	if(eq(cmp1,cmp2)) cout<<"MISMO\n";
	else cout<<"OTRO\n";

	return 0;
}

