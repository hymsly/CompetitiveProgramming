#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll M[1005];

ll f(int x){
	ll ans = 1;
	for(int i=2;i*i<=x;i++){
		int j = 1;
		while(x%i==0){
			j*=i;
			x/=i;
		}
		ans *= M[j];
	}
	ans *= M[x];
	return ans;
}

int main(){
	int a,b;
	while(cin>>a>>b){
		M[a] = b;
	}
	int ans = -1;
	ll valor = 0;
	for(int i=1;i<1000;i++){
		ll val = f(i);
		if(val > valor){
			valor = val;
			ans = i;
		}
	}
	cout<<ans<<" "<<valor<<endl;

	return 0;
}

