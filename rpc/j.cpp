#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,t;

vector<int> neg,group;

bool valid(int x){
	for(int i=0;i<t;i++){
		int val = (neg[i]&x);
		if(__builtin_popcount(val)>1) return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	while(cin>>n>>m>>t){
		neg.resize(t);
		for(int i=0;i<t;i++){
			neg[i] = 0;
			int a,num;cin>>a;
			while(a--){
				cin>>num;
				num--;
				neg[i]+=(1<<num);
			}
		}
		group.resize(m);
		for(int i=0;i<m;i++){
			group[i] = 0;
			int a,num;cin>>a;
			while(a--){
				cin>>num;
				num--;
				group[i]+=(1<<num);
			}
		}
		int maxi=-1,mini=n+1;
		for(int mask=0;mask<(1<<n);mask++){
			if(!valid(mask)) continue;
			int cntG=0;
			for(int i=0;i<m;i++){
				int val = (group[i]&mask);
				if(val){
					cntG++;
				}
			}
			if(cntG>maxi){
				maxi = cntG;
				mini = __builtin_popcount(mask);
			}else if(cntG==maxi){
				int used = __builtin_popcount(mask);
				if(used < mini) mini = used;
			}
		}
		cout<<maxi<<" "<<mini<<'\n';
	}

	return 0;
}

