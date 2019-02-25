#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define SZ(x) (int)x.size()
typedef long long ll;
typedef long double ld;
const ld EPS = (1e-9);
vector<ld> pos;
vector<ld> ilu;
int n;
bool valid(int mask){
	vector< pair<ld,ld> > segments;
	for(int i=0;i<n;i++)if(mask & (1<<i))segments.push_back(mp(pos[i]-ilu[i]/2.0,pos[i]+ilu[i]/2.0));
	sort(segments.begin(),segments.end());
	if(segments[0].first>EPS) return false;
	ld final = segments[0].second;
	bool ok=1;
	for(int i=1;i<segments.size();i++){
		if(segments[i].first>final+EPS) ok=0;
		final = max(final,segments[i].second);
	}
	if(final<pos[n-1])ok=0;
	return ok;
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	pos.resize(n);
	ld d;cin>>d;
	pos[0]=0.0;
	for(int i=1;i<n;i++) pos[i]=pos[i-1]+d;
	ilu.resize(n);
	for(int i=0;i<n;i++) cin>>ilu[i];
	int ans = (1<<n)-1;
	if(!valid(ans)){
		cout<<"INSUFFICIENT LAMPS";
		return 0;
	}
	for(int mask=1;mask<(1<<n);mask++){
		if(valid(mask)){
			if(__builtin_popcount(mask) < __builtin_popcount(ans)) ans =mask;
		}
	}
	cout<<__builtin_popcount(ans)<<'\n';
	int cnt = __builtin_popcount(ans);
	vector<int> puede,nopuede;
	for(int i=0;i<n;i++){
		if(ans & (1<<i))puede.push_back(i+1);
		else nopuede.push_back(i+1);
	}
	for(int i=0;i<puede.size();i++) cout<<puede[i]<<(char)(i+1==puede.size()?10:32);
	for(int i=0;i<nopuede.size();i++) cout<<nopuede[i]<<(char)(i+1==nopuede.size()?10:32);
	

	return 0;
}

