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
	int t;cin>>t;
	int a,b;
	while(t--){
		cin>>a>>b;
		int ans1=0,ans2=0;
		for(int i=1;;i++){
			if(i&1){
				ans1+=i;
				if(ans1>a){
					cout<<"Bob"<<endl;
					break;
				}
			}else{
				ans2+=i;
				if(ans2>b){
					cout<<"Limak"<<endl;
					break;
				}
			}
		}
	}
	
	return 0;
}

