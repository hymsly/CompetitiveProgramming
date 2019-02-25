#include<bits/stdc++.h>
#define pb(x) push_back(x) 
using namespace std;
typedef long long ll;
const int N = (3e5);
const ll MOD = (1e9+7);

struct Line{
	ll m,h;
	Line(){}
	Line(ll _m,ll _h){
		m = _m;
		h = _h;
	}
};
struct CHT { // for minimum (for maximum just change the sign of lines)
	vector<Line> c;
	int pos=0;
	ll in(Line a, Line b){
		ll x=b.h-a.h,y=a.m-b.m;
		return x/y+(x%y?!((x>0)^(y>0)):0); // ==ceil(x/y)
	}
	void add(ll m, ll h){ // m's should be non increasing
		Line l=(Line){m,h};
		if(c.size()&&m==c.back().m){
			l.h=min(h,c.back().h);c.pop_back();if(pos)pos--;
		}
		while(c.size()>1&&in(c.back(),l)<=in(c[c.size()-2],c.back())){
			c.pop_back();if(pos)pos--;
		}
		c.pb(l);
	}
	inline bool fbin(ll x, int m){return in(c[m],c[m+1])>x;}
	ll eval(ll x){
		// O(log n) query:
		int s=0,e=c.size();
		while(e-s>1){int m=(s+e)/2;
			if(fbin(x,m-1))e=m;
			else s=m;
		}
		return c[s].m*x+c[s].h;
		// O(1) query (for ordered x's):
		while(pos>0&&fbin(x,pos-1))pos--;
		while(pos<c.size()-1&&!fbin(x,pos))pos++;
		return c[pos].m*x+c[pos].h;
	}
} CONVEX;


struct data{
	ll q,a,b,r,d;
	data(){}
	data(ll _q,ll _a,ll _b,ll _r,ll _d){
		q = _q;
		a = _q;
		b = _b;
		r = _r;
		d = _d;
	}
	void read(){
		cin>>q>>a>>b>>r>>d;
	}
};

data IN[N+2];

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n;cin>>n;
	for(int i=1;i<=n;i++) IN[i].read();
	ll ans = 0;
	for(int i=n;i>0;i--){
		CONVEX.add(i,IN[i].r);
		ll m = IN[i].q + i*IN[i].d - CONVEX.eval(IN[i].d);
		if(m<0) continue;
		ll k = max(0LL,(m-IN[i].a)/IN[i].b);
		m %= MOD;
		//if(k==0) continue;
		k %= MOD;
		ll cua = k*(k+1)/2;
		cua %= MOD;
		ans += ( ((m-IN[i].a)*k)%MOD - (IN[i].b*cua)%MOD );
		ans %= MOD;
		ans += MOD;
		ans %= MOD;
	}
	cout<<ans<<'\n';

	return 0;
}

