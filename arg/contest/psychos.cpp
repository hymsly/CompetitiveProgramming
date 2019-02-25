#include<bits/stdc++.h>

using namespace std;

int T[262144];
int N = 1;
int n;

void update(int x,int val){
	x+=N;
	while(x){
		T[x] = max(T[x],val);
		x>>=1;
	}
}

int query(int x,int y){//[x,y>
	x+=N;
	y+=N;
	int ans = 0;
	while(x<y){
		if(x&1) ans = max(ans,T[x++]);
		if(y&1) ans = max(ans,T[--y]);
		x>>=1;
		y>>=1;
	}
	return ans;
}



int main(){
	cin>>n;
	while(N<n) N<<=1;
	vector<pair<int,int> > lis;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	for(int i=0;i<n;i++){
		while( lis.size() && lis.back().first < v[i] ){
			lis.pop_back();
		}
		if(lis.size()==0){
			update(i,0);
			lis.push_back(make_pair(v[i],i));
			continue;
		}
		int maximo = query(lis.back().second+1,i);
		update(i,maximo+1);
		lis.push_back(make_pair(v[i],i));
	}
	int ans = 0;
	for(int i=0;i<n;i++) ans = max(ans,query(i,i+1));
	//for(int i=0;i<n;i++) cout<<query(i,i+1)<<(char)(i+1==n?10:32);
	cout<<ans<<'\n';

	return 0;
}

