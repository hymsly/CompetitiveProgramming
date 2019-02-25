#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = (1e9);
ll ST[100002][25];
ll A[100002];
int n;
int N = 1;

vector<int> T[262144];

ll f(ll x,ll y){
	return __gcd(x,y);
}

vector<int> merge(vector<int> a,vector<int> b){
	int i=0,j=0;
	vector<int> ans;
	while(i<a.size() || j<b.size()){
		if(i==a.size()) ans.push_back(b[j++]);
		else if(j==b.size()) ans.push_back(a[i++]);
		else if(a[i] < b[j]){
			ans.push_back(a[i++]);
		}else ans.push_back(b[j++]);
	}
	return ans;
}

void build(){
	for(int i=0;i<n;i++) ST[i][0] = A[i];
	for(int j=1;(1<<j)<=n;j++){
		for(int i=0;i+(1<<j)<=n;i++) ST[i][j] = f(ST[i][j-1] , ST[i + (1<<(j-1))][j-1]);
	}
	for(int i=0;i<n;i++) T[N+i].push_back(A[i]);
	for(int i=N-1;i>0;i--) T[i] = merge(T[2*i],T[2*i+1]);
}

ll query(int l,int r){//[l,r>
	int d = r-l;
	int lg = 31 - (__builtin_clz(d));
	return f(ST[l][lg],ST[r-(1<<lg)][lg]);
}

int many(vector<int> v,int x){
	int ans = 0;
	for(int i=0;i<v.size();i++){
		vector<int> &p = T[v[i]];
		int lo=-1,hi=p.size();
		while((hi-lo)>1){
			int mi = (hi+lo)/2;
			if(p[mi]>x) hi=mi;
			else lo = mi;
		}
		ans += hi;
	}
	return ans;
}

int query2(int l,int r,int gcd){
	l += N;
	r += N;
	vector<int> res;
	while(l<r){
		if(l&1){
			res.push_back(l++);
		}
		if(r&1) res.push_back(--r);
		l>>=1;
		r>>=1;
	}
	return many(res,gcd) - many(res,gcd-1);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int q;
	cin>>n;
	while(N < n) N<<=1;
	for(int i=0;i<n;i++) cin>>A[i];
	build();
	int l,r;
	cin>>q;
	while(q--){
		cin>>l>>r;
		l--;
		ll gcd = query(l,r);
		ll cnt = query2(l,r,gcd);
		cout<<(r-l-cnt)<<'\n';
	}

	return 0;
}
