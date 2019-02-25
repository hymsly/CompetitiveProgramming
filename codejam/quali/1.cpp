#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll M[32];

void init(){
	M[0] = 1LL;
	for(int i=1;i<32;i++) M[i] = 2*M[i-1];
}

ll f(string s){
	ll ans = 0;	
	for(int i=0;i<s.size();i++){
		if(s[i]=='S') ans++;
	}
	return ans;
}

int caso;

void solve(){
	ll d;string s;
	cin>>d>>s;
	ll maxi = f(s);
	if(maxi > d){
		cout<<"Case #"<<++caso<<": ";
		cout<<"IMPOSSIBLE\n";
		return;
	}
	ll act = 0;
	int j=0;
	vector<int> v;
	for(int i=0;i<s.size();i++){
		if(s[i]=='C'){
			j++;
			v.push_back(i);
		}
		else act+=M[j];
	}
	int ans = 0;
	j--;
	int n = s.size();
	n--;
	while(act > d){
		//cout<<j<<" "<<n<<" "<<act<<endl;
		//cout<<"posiciones de C\n";
		//for(int i=0;i<v.size();i++) cout<<v[i]<<(char)(i+1==v.size()?10:32);
		if(v[j]==n){
			j--;
			n--;
		}else{
			act -= M[j];
			v[j]++;
			ans++;
		}
	}
	cout<<"Case #"<<++caso<<": ";
	cout<<ans<<'\n';
}

int main(){
	init();
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

