#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (1e5);
vector<int> pr,ex;
vector<int> getdivisores(int x){
	for(int i=2;i*i<=x;i++){
		int cnt = 0;
		while(x%i==0){
			cnt++;x/=i;
		}
		if(cnt){
			pr.push_back(i);ex.push_back(cnt);
		}
	}
	if(x>1){
		pr.push_back(x);ex.push_back(1);
	}
	vector<int> ans(1,1);
	for(int i=0;i<pr.size();i++){
		int val = 1;
		int len = ans.size();
		for(int j=0;j<ex[i];j++){
			val*=pr[i];
			for(int k=0;k<len;k++) ans.push_back(ans[k]*val);
		}
	}
	sort(ans.begin(),ans.end());
	return ans;
}
string s;
int n;
bool valid(int x){
	for(int i=0;i<x;i++){
		int len = n/x;
		bool ok=1;
		int pos = i;
		for(int j=0;j<len;j++){
			if(s[pos]=='P') ok=0;
			pos += x;
			pos %= n;
		}
		if(ok) return true;
	}
	return false;
}
bool can[N+2];
int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	cin>>s;
	n = s.size();
	vector<int> divi = getdivisores(n);
	for(int i=0;i<divi.size();i++) can[divi[i]]=valid(divi[i]);
	int ans = 0;
	for(int i=1;i<n;i++){
		int p = __gcd(i,n);
		if(can[p])ans++;
	}
	cout<<ans<<'\n';

	return 0;
}

