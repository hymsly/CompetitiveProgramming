#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (4e5);

ll A[N+2], B[N+2] , C[N+2];


int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n;cin>>n;
	ll ans = 0;
	vector<ll> uno,dos,ninguno;
	string s;ll t;
	int len = 0;
	for(int i=0;i<n;i++){
		cin>>s>>t;
		if(s=="11"){
			ans +=t;
			len++;
		}else if(s=="10") uno.push_back(t);
		else if(s=="01") dos.push_back(t);
		else ninguno.push_back(t);
	}
	sort(uno.rbegin(),uno.rend());
	sort(dos.rbegin(),dos.rend());
	sort(ninguno.rbegin(),ninguno.rend());
	if(uno.size()>dos.size()){
		swap(uno,dos);
	}
	for(int i=1;i<=uno.size();i++){
		A[i] = A[i-1] + uno[i-1];
	}
	for(int i=1;i<=dos.size();i++){
		B[i] = B[i-1] + dos[i-1];
	}
	for(int i=1;i<=ninguno.size();i++){
		C[i] = C[i-1] + ninguno[i-1];
	}
	ll maxi = 0;
	for(int i=0;i<=len;i++){
		ll cur = C[i] + A[uno.size()];
		int pos  = (len-i + uno.size());
		if(pos>dos.size()) pos = dos.size();
		cur += B[pos];
		maxi = max(maxi,cur);
	}
	cout<<ans+maxi<<'\n';
	


	return 0;
}

