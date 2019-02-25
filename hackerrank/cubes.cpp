#include<bits/stdc++.h>

using namespace std;

vector< pair<int,int> > v;
vector< pair<int,int> > w;

bool can(int x,int y){//2y*y >= x*x
	if(2*y*y >= x*x) return true;
	else return false;
}

int ans;

void solve(){
	sort(v.begin(),v.end());
	sort(w.begin(),w.end());
	int i=0,j=0;
	for(int i=0;i<v.size();){
		if(j==w.size()) break;
		if(can(v[i].first,w[j].first)){
			if(v[i].second > w[j].second){
				ans += w[j].second;
				v[i].second -= w[j].second;
				j++;
			}else if(v[i].second == w[j].second){
				ans += v[i].second;
				i++;
				j++;
			}else{
				ans += v[i].second;
				w[j].second -= v[i].second;
				i++;
			}
		}else{
			j++;
		}
	}
}

int main(){
	int n,m;cin>>n>>m;
	v.resize(n);
	w.resize(m);
	for(int i=0;i<n;i++) cin>>v[i].first;
	for(int i=0;i<n;i++) cin>>v[i].second;
	for(int i=0;i<m;i++) cin>>w[i].first;
	for(int i=0;i<m;i++) cin>>w[i].second;
	solve();
	cout<<ans<<endl;

	return 0;
}

