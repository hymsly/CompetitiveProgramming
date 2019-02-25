#include<bits/stdc++.h>

using namespace std;
#define SZ(x) (ll)x.size()
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,to=b;i<to;i++)
typedef long long ll;
typedef long double ld;
const ll N = (5e4);
ll n;
ll A[N+2];

void error(){
	int value = 5/0;
}

void ask(ll x1,ll x2,ll x3,ll &res){
	cout<<"1 "<<x1+1<<" "<<x2+1<<" "<<x3+1<<endl;
	cin>>res;
}

void guess(ll pos){
	ll a1,a2,val,x;
	ask(pos,pos+1,pos+2,a1);
	ask(pos+1,pos+2,pos+3,a2);
	val = a1^a2;
	ask(pos,pos+3,pos+1,x);
	A[pos+1] = val^x;
	ask(pos,pos+3,pos+2,x);
	A[pos+2] = val^x;
	A[pos] = a1^A[pos+1]^A[pos+2];
	A[pos+3] = a2^A[pos+1]^A[pos+2];
}

void guess5(ll pos){
	ll a1,a2,a3,a4,a5;
	ask(pos,pos+1,pos+2,a1);
	ask(pos+1,pos+2,pos+3,a2);
	ask(pos+2,pos+3,pos+4,a3);
	ask(pos+3,pos+4,pos,a4);
	ask(pos+4,pos,pos+1,a5);
	A[pos+3] = a1^a3^a5;
	A[pos] = a1^a2^A[pos+3];
	A[pos+1] = a4^a5^A[pos+3];
	A[pos+4] = a2^a3^A[pos+1];
	A[pos+2] = a5^a1^A[pos+4];
}

void guess10(ll pos){
	ll a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;
	ask(pos,pos+1,pos+2,a1);
	ask(pos+1,pos+2,pos+3,a2);
	ask(pos+2,pos+3,pos+4,a3);
	ask(pos+3,pos+4,pos+5,a4);
	ask(pos+4,pos+5,pos+6,a5);
	ask(pos+5,pos+6,pos+7,a6);
	ask(pos+6,pos+7,pos+8,a7);
	ask(pos+7,pos+8,pos+9,a8);
	ask(pos+8,pos+9,pos,a9);
	ask(pos+9,pos,pos+1,a10);
	A[pos+5] = a1^a2^a4^a5^a6^a8^a9;
	A[pos+8] = a6^a7^A[pos+5];
	A[pos+1] = a9^a10^A[pos+8];
	A[pos+4] = a2^a3^A[pos+1];
	A[pos+7] = a5^a6^A[pos+4];
	A[pos] = a8^a9^A[pos+7];
	A[pos+3] = a1^a2^A[pos];
	A[pos+6] = a4^a5^A[pos+3];
	A[pos+9] = a7^a8^A[pos+6];
	A[pos+2] = a10^a1^A[pos+9];
}

void guess7(ll pos){
	ll a1,a2,a3,a4,a5,a6,a7;
	ask(pos,pos+1,pos+2,a1);
	ask(pos+1,pos+2,pos+3,a2);
	ask(pos+2,pos+3,pos+4,a3);
	ask(pos+3,pos+4,pos+5,a4);
	ask(pos+4,pos+5,pos+6,a5);
	ask(pos+5,pos+6,pos,a6);
	ask(pos+6,pos,pos+1,a7);
	A[pos+5] = a1^a2^a4^a5^a6;
	A[pos+1] = a6^a7^A[pos+5];
	A[pos+4] = a2^a3^A[pos+1];
	A[pos] = a5^a6^A[pos+4];
	A[pos+3] = a1^a2^A[pos];
	A[pos+6] = a4^a5^A[pos+3];
	A[pos+2] = a1^a7^A[pos+6];
}

void answer(){
	cout<<2<<endl;
	for(ll i=0;i<n;i++)cout<<A[i]<<(i+1==n?"":" ");
	cout<<endl;
	ll res;
	cin>>res;
}

void solve(){
	cin>>n;
	ll resto;
	if(n%4==0) resto=0;
	else if(n%4==1)resto=5;
	else if(n%4==2)resto=10;
	else resto=7;
	ll value = n - resto;
	for(ll i=0;i<value;i+=4){
		guess(i);
	}
	if(resto==5)guess5(value);
	else if(resto==10)guess10(value);
	else if(resto==7)guess7(value);
	answer();
}


int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	ll t;cin>>t;
	while(t--)solve();

	return 0;
}
