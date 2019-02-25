#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
typedef long long ll;

struct state {int len,link;unordered_map<int,int> next;}; //clear next!!
state st[100005][9];
int sz,last;
void sa_init(int id){
	last=st[0][id].len=0;sz=1;
	st[0][id].link=-1;
}
void sa_extend(int c,int id){
	int k=sz++,p;
	st[k][id].len=st[last][id].len+1;
	for(p=last;p!=-1&&!st[p][id].next.count(c);p=st[p][id].link)st[p][id].next[c]=k;
	if(p==-1)st[k][id].link=0;
	else {
		int q=st[p][id].next[c];
		if(st[p][id].len+1==st[q][id].len)st[k][id].link=q;
		else {
			int w=sz++;
			st[w][id].len=st[p][id].len+1;
			st[w][id].next=st[q][id].next;st[w][id].link=st[q][id].link;
			for(;p!=-1&&st[p][id].next[c]==q;p=st[p][id].link)st[p][id].next[c]=w;
			st[q][id].link=st[k][id].link=w;
		}
	}
	last=k;
}
vector< vector<int> > v;
int n,m;

int init[9];

int main(){
	clock_t start = clock();
	ios::sync_with_stdio(0);cin.tie(NULL);
	cin>>n>>m;
	v.resize(m);
	for(int i=0;i<m;i++){
		if(i>0)sa_init(i-1);
		int num;
		for(int j=0;j<n;j++){
			cin>>num;
			if(i>0)sa_extend(num,i-1);
			v[i].push_back(num);
		}
	}
	ll ans = 0;
	for(ll i=0,j=0;i<n;i=j){
		memset(init,0,sizeof init);
		while(j<n){
			bool ok=1;
			#pragma omp parallel for
			for(int k=0;k<m-1;k++){
				if(st[init[k]][k].next.count(v[0][j])) init[k] = st[init[k]][k].next[v[0][j]];
				else{
					ok=0;break;
				}
			}
			if(!ok) break;
			else j++;
		}
		ans += ((j-i)*(j-i+1))/2;
	}
	cout<<ans<<'\n';
	printf("Time taken: %.2fs\n", (double)(clock() - start)/CLOCKS_PER_SEC);

	return 0;
}

