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
const ll INF=(1e18);

int n,k;
vector<pair<int,int> > v;

ll memo[400][400][400];

ll dp(int pos,int cnt,int last){
    //cout<<pos<<" "<<cnt<<" "<<last<<endl;
    if(pos+1==n){
		if(cnt+1==k) return 0;
		else return INF;
    }
    if(memo[pos][cnt][last]>0) return memo[pos][cnt][last];
    ll &ans=memo[pos][cnt][last]=0;
    ans=min( dp(pos+1 , cnt , last) + v[pos+1].se*(v[pos+1].fi - v[last].fi) , dp(pos+1 ,cnt+1 ,pos+1) );
    return ans;
}

int main() {
    cin>>n>>k;
    pair<int,int> p;
    for(int i=0;i<n;i++){
        cin>>p.fi>>p.se;
        v.push_back(p);
    }
    cout<<dp(0,0,0)<<endl;
    
    return 0;
}


