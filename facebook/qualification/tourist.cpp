#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,k,v;

vector<string> s;
int caso;

void doit(){
	cin>>n>>k>>v;
	s.resize(n);
	for(int i=0;i<n;i++) cin>>s[i];
	v%=n;
	int ini = (((v-1)*k)%n+n)%n;
	vector<int> v(k);
	for(int i=0;i<k;i++){
		v[i] = (ini+i)%n;
	}
	sort(v.begin(),v.end());
	cout<<"Case #"<<++caso<<": ";
	for(int i=0;i<k;i++){
		cout<<s[v[i]]<<(char)(i+1==k?10:32);
	}
}

int main(){
	int t;cin>>t;
	while(t--) doit();

	return 0;
}

