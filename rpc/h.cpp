#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (1e4);
const ld dos=log10(2);
const ld cinco=log10(5);
const ld EPS = (1e-6);

ld A[N+2],B[N+2];

void init(){
	A[0] = 1;
	B[0] = 1;
	for(int i=1;i<=N;i++) A[i] = A[i-1] + dos;
	for(int i=1;i<=N;i++) B[i] = B[i-1] + cinco;
	for(int i=0;i<=N;i++){
		A[i] = floor(A[i]+EPS);
		B[i] = floor(B[i]+EPS);
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	init();
	int t;cin>>t;
	int a,b;
	while(t--){
		cin>>a>>b;
		int ans;
		if(a==b){
			ans = a+1;
		}else if(a>b){
			ans = b;
			ans += (int) (A[a-b]);
		}else{
			ans = a;
			ans += (int) (B[b-a]);
		}
		cout<<ans<<'\n';
	}

	return 0;
}

