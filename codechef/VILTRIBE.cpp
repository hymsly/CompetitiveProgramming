#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector< pair<int,int> > v;

int win(int x){
	if(v.size()==0) return -1;
	int lo=0,hi=v.size();
	while((hi-lo)>1){
		int mi = (hi+lo)/2;
		if(v[mi].first>x) hi=mi;
		else lo=mi;
	}
	if(v[lo].first > x) return -1;
	if(v[lo].first==x) return v[lo].second;
	if(hi==v.size()) return -1;
	if(v[lo].second==v[hi].second) return v[lo].second;
	else return -1;
}

int main(){
	//ios_base::sync_with_stdio(0);
	int t;cin>>t;
	string s;
	while(t--){
		int cnt1=0,cnt2=0;
		cin>>s;
		v.clear();
		for(int i=0;i<s.size();i++){
			if(s[i]=='A'){
				v.push_back(make_pair(i,0));
			}else if(s[i]=='B'){
				v.push_back(make_pair(i,1));
			}
		}
		for(int i=0;i<s.size();i++){
			int p = win(i);
			if(p==-1) continue;
			if(p==0) cnt1++;
			if(p==1) cnt2++;
		}
		cout<<cnt1<<" "<<cnt2<<'\n';
	}

	return 0;
}

