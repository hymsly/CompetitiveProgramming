#include<iostream>
#include<cstring>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
ll M[42];
ll cnt;

ll f(ll x){
	memset(M,0,sizeof(M));
	ll ans=1;
	for(ll i=2;i*i<=x;i++){
		int ex=0;
		while(x%i==0){
			ex++;
			x/=i;
		}
		if(ex){
			M[ex]++;
			ans*=(ll)(ex+1);
		}
	}
	if(x>1){
		ans*=2;
		M[1]++;
	}
	return ans;
}
 
ll confe(){
	ll ans=0;
	int val=41;
	for(val;val>=0;val--){
		if(M[val]!=0) break;
	}
	while(val>0){
		ans+=cnt;
		cnt /= (val+1);
		cnt *= val;
		M[val]--;
		M[val-1]++;
        if(M[val]==0){
			val--;
		}
	}
	return ans;
}
 
int main(){
	fast_io()
	ll a,b;
	cin>>a>>b;
	ll ans=0;
	for(ll i =a ;i<=b;i++){
		cnt = f(i);
		ans+=confe();
	}
	cout<<ans<<'\n';
 
	return 0;
}
