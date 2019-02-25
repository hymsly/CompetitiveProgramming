#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (2e5);

bool used[N+2];

pair<int,int> M[N+2];

ll ST[N+2][25];

int query(int l,int r){
	int d = r-l+1;
	int lg = 31 - (__builtin_clz(d));
	return min(ST[l][lg],ST[r-(1<<lg)+1][lg]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(NULL);
	cin.tie(NULL);
	int n,q;cin>>n>>q;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	bool ok=0;
	vector<int> zero;
	int last = -1;
	int first = -1;
	int ultimozero = -1;
	for(int i=0;i<n;i++){
		if(v[i]==0){
			zero.push_back(i);
		}else{
			first = last;
			last = v[i];
			if(zero.size()==0) continue;
			//if(first != last){
				ultimozero = zero[0];	
			//}
			for(int j=0;j<zero.size();j++) v[zero[j]]=last;
			zero.clear();
		}
	}
	if(zero.size()>0){
		if(last==-1){
			cout<<"YES\n";
			for(int i=0;i<n;i++) cout<<q<<(char)(i+1==n?10:32);
			return 0;
		}else{
			for(int j=0;j<zero.size();j++) v[zero[j]]=last;
			ultimozero = zero[zero.size()-1];
			zero.clear();
		}
	}
	for(int i=0;i<n;i++){
		if(v[i]==q) ok=1;
	}
	if(!ok){
		if(ultimozero==-1){
			cout<<"NO\n";
			return 0;
		}else{
			v[ultimozero] = q;
		}
	}
	//ya tengo, ahora a validar
	/*last = v[0];
	used[last] = 1;
	for(int i=1;i<n;i++){
		if(v[i]==last) continue;
		if(used[v[i]]){
			if(v[i]>last){
				cout<<"NO\n";
				return 0;
			}
		}
		used[v[i]] = 1;
		last = v[i];
	}*/
	
	//initialize M for the intervals with length 1
	for (int i = 0; i < n; i++) ST[i][0] = v[i];
	//compute values from smaller to bigger intervals
	for (int j = 1; (1 << j) <= n; j++){
		for (int i = 0; i + (1 << j) <= n; i++){
			ST[i][j] = min(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
		}
	}
	
	for(int i=1;i<=q;i++) M[i].first = M[i].second = -1;
	for(int i=0;i<n;i++){
		int val = v[i];
		if(M[val].first==-1){
			M[val].first = i;
			M[val].second = i;
		}else{
			M[val].second = i;
		}
	}
	for(int i=1;i<=q;i++){
		if(M[i].first==-1 && M[i].second==-1) continue;
		int mini = query(M[i].first,M[i].second);
		if(mini<i){
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	for(int i=0;i<n;i++) cout<<v[i]<<(char)(i+1==n?10:32);
	
	return 0;
}

