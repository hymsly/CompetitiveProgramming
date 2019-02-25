#include<bits/stdc++.h>

using namespace std;

int a,b,c,d;
int time1,time2,hour;
void solve(){
	cin>>a>>b>>c>>d;
	time1 = a*60+b;
	time2 = c*60+d;
	cin>>hour;
	time1 += 60*hour;
	cout<<time1-time2<<'\n';
}

int main(){
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

