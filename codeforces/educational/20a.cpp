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

int M[105][105];

int main(){
	//fast_io()
	int n,k;
	cin>>n>>k;
	if(k>sqr(n)) cout<<-1<<endl;
	else{
		int pos=0;
		for(int i=1;i<=n;i++){
			if(k<=1) break;
			for(int j=i;j<=n;j++){
				if(k<=1) break;
				M[i][j] = 1;
				M[j][i] = 1;
				if(i!=j) k-=2;
				else{
					k--;
					pos=i;
				}
			}
		}
		if(k>0){
			M[pos+1][pos+1] = 1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<M[i][j]<<(char)(j==n?10:32);
			}
		}
	}	
	return 0;
}

