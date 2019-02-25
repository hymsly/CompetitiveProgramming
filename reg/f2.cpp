#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=(2e5 + 100);

struct str{
	int p,r;
	ll w;
	str(){}
};

bool orden(str s1,str s2){
	if(s1.r != s2.r) return s1.r < s2.r;
	return s1.p < s2.p;
}

vector <str> p(N+5);

ll BIT[N+5];
void update(int x,long long w){
	for(;x<=N;x+=x&-x) BIT[x] +=w;
}
ll query(int x){
	ll sum = 0;
	for(;x>0;x-=x&-x) sum+= BIT[x];
	return sum;
}

map<int,int> comp;
set<int> nums;
void compress(){
	int m=1;
	for(set<int>::iterator it=nums.begin();it!=nums.end();it++) comp[*it] = m++;
}

int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		cin>>p[i].p>>p[i].r>>p[i].w;
		nums.insert(p[i].p);
		nums.insert(p[i].r);
	}
	compress();
	for(int i=0;i<n;i++){
		p[i].p = comp[p[i].p];
		p[i].r = comp[p[i].r];
	}
	sort(p.begin(),p.begin() + n,orden);
	vector<str> p2;
	for(int i=0;i<n;i++){
		int sz2 = p2.size();
		if(sz2 == 0 || (p2[sz2 -1].p != p[i].p || p2[sz2-1].r) != p[i].r) p2.push_back(p[i]);
		else p2[sz2-1].w += p[i].w;
	}
	p = p2;
	n = p2.size();
	ll ans = p[0].w;
	vector<int> adds;
	adds.push_back(0);
	for(int i=1;i<n;i++){
		if(p[i-1].r < p[i].r){
			for(int x=0;x<adds.size();x++){
				update(p[adds[x]].p,p[adds[x]].w);
			}
			adds.clear();
		}
		adds.push_back(i);
		ans = max(ans,p[i].w) + query(p[i].p - 1);
	}
	cout<<ans<<endl;
	return 0;
}
