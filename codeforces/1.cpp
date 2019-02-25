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
const long double PI=acos(-1.0);
long double getang(ll x,ll y){
    long double ang = atan2((long double)y,(long double)x);
    if(ang<0) ang+=2.0*PI;
    return ang;
}

int main() {
	//fast_io()    
    int n;cin>>n;
    vector<pair<long double,int> > v(n);
    ll a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        v[i].fi=getang(a,b);
        v[i].se = i+1;
    }
    sort(all(v));
    long double mini=2.0*PI;
    int ans1,ans2;
    for(int i=0;i<n;i++){
        if(i){
            long double value = min(abs(v[i].fi - v[i-1].fi) , 2.0*PI - abs(v[i].fi - v[i-1].fi) );
            if(value < mini){
                ans1=v[i].se;
                ans2=v[i-1].se;
                mini = value;
            }
        }else{
            long double value = min(abs(v[i].fi - v[n-1].fi) , 2.0*PI - abs(v[i].fi - v[n-1].fi) );
            if(value< mini){
                ans1=v[i].se;
                ans2=v[n-1].se;
                mini = value;
            }
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
    
    return 0;
}
