#include<bits/stdc++.h>

using namespace std;

struct num{
	int cnt[10];
	num(){
		for(int i=0;i<10;i++) cnt[i]=0;	
	}
	num(string x){
		for(int i=0;i<10;i++) cnt[i]=0;
		for(int i=0;i<x.size();i++){
			cnt[x[i]-'0']++;
		}
	}
} M[25];
int B[25];//belleza

int val[10];
int n;
int pa[20];
int Find(int x){
	return (pa[x]==x?x:pa[x]=Find(pa[x]));
}

void Union(int x,int y){
	int xx = Find(x);
	int yy = Find(y);
	pa[xx] = yy;
}

int f(int mask){
	vector<int> v;
	v.push_back(0);
	for(int i=0;i<n;i++){
		if(mask & (1<<i)) v.push_back(B[i]);
	}
	/*sort(v.begin(),v.end());
	//for(int i=0;i<v.size();i++) cout<<v[i]<<(char)(i+1==v.size()?10:32);
	int ans = 0;
	do{
		int val = v[0];
		for(int i=1;i<v.size();i++){
			val += (v[i]^v[i-1]);
		}
		ans = max(ans,val);
	}while(next_permutation(v.begin(),v.end()));
	return ans;*/
	vector<pair<int,pair<int,int> > > w;
	for(int i=0;i<v.size();i++){
		for(int j=i+1;j<v.size();j++){
			w.push_back(make_pair(v[i]^v[j],make_pair(i,j)));
		}
	}
	sort(w.rbegin(),w.rend());
	for(int i=0;i<20;i++) pa[i]=i;
	int ans = 0;
	for(int i=0;i<w.size();i++){
		if(Find(w[i].second.first) == Find(w[i].second.second)) continue;
		ans += w[i].first;
		Union(w[i].second.first,w[i].second.second);
	}
	return ans;
}

bool vis[(1<<20)];

int main(){
	int q;cin>>n>>q;
	for(int i=0;i<n;i++) cin>>B[i];
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		M[i] = num(s); 	
	}
	int maxi = 0;
	vector<int> v;
	for(int mask=(1<<n)-1;mask>0;mask--){
		memset(val,0,sizeof val);
		for(int j=0;j<n;j++){
			if(mask & (1<<j)){
				for(int i=0;i<10;i++){
					val[i] += M[j].cnt[i];
				}
			}
		}
		bool ok=1;
		for(int i=0;i<10;i++){
			if(val[i]>q) ok=0;
		}
		if(!ok) continue;
		v.push_back(mask);
		//maxi = max(maxi,f(mask));
	}
	memset(vis,1,sizeof vis);
	for(int i=0;i<v.size();i++){
		if(!vis[v[i]]) continue;
		maxi = max(maxi,f(v[i]));
		for(int j=v[i];j>0;j=(j-1)&v[i]){
			vis[j]=0;
    	}
	}
	cout<<maxi<<'\n';

	return 0;
}

