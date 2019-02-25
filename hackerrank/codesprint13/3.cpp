#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,m,k;

ll res(vector<ll> v){
	if(v.size()==0) return 0;
	//for(int i=0;i<v.size();i++) cout<<v[i]<<(char)(i+1==v.size()?10:32);
	map<ll,ll> M;
	ll val = 1;	
	for(int i=0;i<v.size();i++){
		val *= v[i];
		val%=m;
		M[val]++;
	}
	ll ans = 0;
	if(M.count(k)) ans += M[k];
	val = 1;
	for(int i=0;i<v.size();i++){
		val *= v[i];
		val %= m;
		if(M[val]==1) M.erase(val);
		else M[val]--;
		ll search = (val*k)%m;
		if(M.count(search)) ans += M[search];
	}
	return ans;
}

void solve1(){
	ll ans = 0;
	vector<ll> v;
	ll num;
	for(int i=0;i<n;i++){
		cin>>num;
		//cout<<num<<endl;
		if(num%m==0){
			ans += res(v);
			v.clear();
		}else v.push_back(num);
	}
	ans += res(v),
	cout<<ans<<'\n';
}

void solve0(){
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	vector<int> ceros;
	for(int i=0;i<n;i++) if(v[i]%m==0) ceros.push_back(i);
	if(ceros.size()==0){
		cout<<"0\n";
		return;
	}
	int maxi = ceros[ceros.size()-1];
	ll ans = 0;
	for(int i=0;i<n;i++){
		int p = lower_bound(ceros.begin(),ceros.end(),i)-ceros.begin();
		if(p==ceros.size()) break;
		ans += (n-ceros[p]);
	}
	cout<<ans<<'\n';
}


void solve(){
	cin>>n>>m>>k;
	if(k==0){
		solve0();
	}else solve1();
}

int main(){
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

