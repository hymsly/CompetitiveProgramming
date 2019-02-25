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

int main(){
	//fast_io()
	int n,t;cin>>n>>t;
	vector<int> v(n);
	vector<int> sum1(n);
	vector<int> sum2(n);
	for(int i=0;i<n;i++) cin>>v[i];
	for(int i=0;i<n;i++){
		if(i) sum1[i] = sum1[i-1] + v[i];
		else sum1[i] = v[i];
	}
	reverse(all(v));
	for(int i=0;i<n;i++){
		if(i) sum2[i] = sum2[i-1] + v[i];
		else sum2[i] = v[i];
	}
	int cnt1,cnt2;
	cnt1 = lower_bound(sum1.begin(),sum1.end(),t)-sum1.begin();
	cnt2 = lower_bound(sum2.begin(),sum2.end(),t)-sum2.begin();
	if(cnt1<cnt2){
		cout<<"Nathan"<<endl;
	}else if(cnt1>cnt2) cout<<"Yan"<<endl;
	else cout<<"Empate"<<endl;
	
	return 0;
}

