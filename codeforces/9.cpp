#include<bits/stdc++.h>
using namespace std;
const int N=(1e6);
vector<int> v;
vector< pair < pair<int,int> ,int > > q;
vector< int > ans;
int cnt[N+5];
int res;
int main(){
	int n;cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++) scanf("%d",&v[i]);
	int t;
	scanf("%d",&t);
	ans.resize(t);
	//cin>>t;
	q.resize(t);
	for(int i=0;i<t;i++){
		scanf("%d%d",&q[i].first.first,&q[i].first.second);
		//cin>>q[i].fi.fi>>q[i].fi.se;
		q[i].first.first--;q[i].first.second--;
		q[i].second=i;
	}
	sort(q.begin(),q.end());
	int in=0,end=n-1;
	for(int i=0;i<n;i++){
		cnt[v[i]]++;
		if(cnt[v[i]]==1) res++;
	}
	for(int i=0;i<t;i++){
		for(int pos=in;pos<q[i].first.first;pos++){
			cnt[v[pos]]--;
			if(cnt[v[pos]]==0) res--;
		}
		in=q[i].first.first;
		if(end<q[i].first.second){
			for(int pos=end;pos<=q[i].first.second;pos++){
				cnt[v[pos]]++;
				if(cnt[v[pos]]==1) res++;
			}
		}else{
			for(int pos=end;pos>q[i].first.second;pos--){
				cnt[v[pos]]--;
				if(cnt[v[pos]]==0) res--;
			}
		}
		end=q[i].first.second;
		ans[q[i].second]=res;
	}
	for(int i=0;i<t;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}

