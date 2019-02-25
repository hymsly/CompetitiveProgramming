#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
string s;
ll f(int x){
	ll ans = 1;
	for(int i=x;i>=x-12;i--){
		ans *= (s[i]-'0');
	}
	return ans;
}

int main(){
	cin>>s;
	ll ans = 0;
	for(int i=12;i<s.size();i++){
		ans = max(ans,f(i));
	}
	cout<<ans<<endl;
	return 0;
}

