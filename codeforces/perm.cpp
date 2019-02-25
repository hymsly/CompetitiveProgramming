#include<bits/stdc++.h>

using namespace std;
const int N = (1e6);

int A[N+2];
int pos[N+2];

int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>A[i];
		pos[A[i]] = i;
	}
	long long ans = 0;
	for(int i=1;i<=n;i++){
		if(A[i]==i) continue;
		ans++;
		swap(A[i],A[pos[i]]);
		swap(pos[A[i]],pos[A[pos[i]]]);
	}
	if(ans%2==0){
		if(n%2==0){
			cout<<"Petr\n";
		}else cout<<"Um_nik\n";
	}else{
		if(n%2==1){
			cout<<"Petr\n";
		}else cout<<"Um_nik\n";
	}

	return 0;
}

