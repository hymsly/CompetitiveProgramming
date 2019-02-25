#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll DP[262144];
int N;

void update(ll valor,int p){
	p += N;
	DP[p] = max(DP[p],valor);
	for(;p>1;p>>=1){
		DP[p>>1] = max(DP[p],DP[p^1]);
	}
}

ll query(int l,int r){
	l += N;
	r += N;
	ll ans = 0;
	for(;l<r;l>>=1,r>>=1){
		if(l&1) ans = max(ans,DP[l++]);
		if(r&1) ans = max(ans,DP[--r]);
	}
	return ans;
}

bool cmp(pair< pair<int,int> , ll > a, pair< pair<int,int> , ll > b){
	if(a.first.first!=b.first.first) return a.first.first < b.first.first;
	else return a.first.second < b.first.second;
}

vector< pair< pair<int,int> , ll > > repetido ( vector< pair< pair<int,int> , ll > > v){
	vector< pair< pair<int,int> , ll > > ans;
	for(int i=0;i<v.size();i++){
		if(ans.size()==0){
			ans.push_back(v[i]);
		}else if(ans[ans.size()-1].first == v[i].first){
			ans[ans.size()-1].second += v[i].second;
		}else{
			ans.push_back(v[i]);
		}
	}
	return ans;
}

map<int,int> comp;
set<int> nums;

void compress(vector< pair< pair<int,int> , ll > > &v){
	for(int i=0;i<v.size();i++){
		nums.insert(v[i].first.second);
	}
	int m=1;
	set<int> :: iterator it;
	for(it=nums.begin();it!=nums.end();it++){
		comp[(*it)] = m++;
	}
}

int main(){
	//ios_base::sync_with_stdio(0);
	int n;cin>>n;
	vector< pair< pair<int,int> , ll > > v(n);
	for(int i=0;i<n;i++) cin>>v[i].first.first>>v[i].first.second>>v[i].second;
	sort(v.begin(),v.end(),cmp);
	vector< pair< pair<int,int> , ll > > p = repetido(v);
	compress(p);
	n = p.size();
	for(int i=0;i<n;i++){
		p[i].first.second = comp[p[i].first.second];
	}
	N=1;
	while(N<n) N<<=1;
	ll ans = 0;
	vector< pair<int,ll> > adds;
	for(int i=0;i<n;i++){
		if(i>0){
			if(p[i].first.first > p[i-1].first.first){
				for(int j=0;j<adds.size();j++){
					update(adds[j].second,adds[j].first);
				}
				adds.clear();
			}
		}
		ll res = p[i].second + query(0,p[i].first.second);
		//cout<<p[i].first.first<<" "<<p[i].first.second<<" "<<p[i].second<<" "<<res<<endl;
		ans = max(ans,res);
		adds.push_back(make_pair(p[i].first.second,res));
	}
	cout<<ans<<endl;

	return 0;
}

