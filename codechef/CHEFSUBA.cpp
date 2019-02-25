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

map<int,int> M;

int main(){
	//fast_io()
	int n,m,p;
	cin>>n>>p>>m;
	if(p>n) p=n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	reverse(all(v));
	string s;cin>>s;
	vector<int> d;
	int cnt = 0;
	for(int i=0;i<p;i++){
		cnt+=v[i];
	}
	for(int i=0;i<2*n-p;i++){
		d.push_back(cnt);
		cnt-=v[i%n];
		cnt+=v[(i+p)%n];
	}
	//for(int i=0;i<d.size();i++) cout<<d[i]<<(char)(i+1==d.size()?10:32);
	vector<int> ans;
	for(int i=0;i<=n-p;i++){
		M[d[i]]++;
	}
	ans.push_back((*M.rbegin()).fi);
	int eliminar = 0;
	for(int i=n-p+1;i<d.size();i++){
		M[d[i]]++;
		if(M[d[eliminar]]>1) M[d[eliminar]]--;
		else M.erase(d[eliminar]);
		eliminar++;
		ans.push_back((*M.rbegin()).fi);
	}
	//for(int i=0;i<ans.size();i++) cout<<ans[i]<<(char)(i+1==ans.size()?10:32);
	int pos = 0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='!'){
			pos++;
			if(pos==ans.size()) pos = 0;
		}else cout<<ans[pos]<<endl;
	}	
	
	return 0;
}

