#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (1e9);

struct Segment{
    ll x1, y1, x2, y2;
	Segment(){}
	ll manyPoint(){
		ll dif1 = abs(x2-x1);
		ll dif2 = abs(y2-y1);
		return (__gcd(dif1,dif2)+1);
	}
};

bool in(int x, int l, int r){
    if (l > r) swap(l, r);
    return (l <= x && x <= r);
}

struct line{
    ll A, B, C;
    line(){};
    line(Segment a){
        A = a.y1 - a.y2;
        B = a.x2 - a.x1;
        C = -A * a.x1 - B * a.y1;
    };
};

ll det(ll a, ll b, ll c, ll d){
    return a * d - b * c;
}

bool inter(Segment a, Segment b, ll& x, ll& y){
    line l1(a), l2(b);
    ll dx = det(l1.C, l1.B, l2.C, l2.B);
    ll dy = det(l1.A, l1.C, l2.A, l2.C);
    ll d = det(l1.A, l1.B, l2.A, l2.B);
    if (d == 0) return false;
    if (dx % d != 0 || dy % d != 0) return false;
    x = -dx / d;
    y = -dy / d;
    if (!in(x, a.x1, a.x2) || !in(y, a.y1, a.y2)) return false;
    if (!in(x, b.x1, b.x2) || !in(y, b.y1, b.y2)) return false;
    return true;
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n;cin>>n;
	vector<Segment> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i].x1>>v[i].y1>>v[i].x2>>v[i].y2;
	}
	ll ans = 0;
	for(int i=0;i<n;i++){
		ans += v[i].manyPoint();
		set< pair<ll,ll> > repetidas;
		ll x,y;
		for(int j=0;j<i;j++){
			if (inter(v[i], v[j], x, y)) repetidas.insert(make_pair(x,y));
		}
		//cout<<v[i].manyPoint()<<" "<<repetidas.size()<<endl;
		ans -= repetidas.size();
	}
	cout<<ans<<'\n';

	return 0;
}

