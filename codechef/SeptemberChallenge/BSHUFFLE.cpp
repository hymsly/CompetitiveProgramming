#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void show(vector<int> &v){
	for(int i=0;i<v.size();i++) cout<<v[i]<<(char)(i+1==v.size()?10:32);
}


void solve(int n){
	cout<<"solve para tamanio "<<n<<endl;
	map<vector<int>,ll > M;
	vector< int > v(n);
	for(int i=0;i<n;i++) v[i] = i;
	ll totOp = 1;
	for(int i=0;i<n;i++) totOp*=n;
	for(ll mask=0;mask<totOp;mask++){
		vector<int> base = v;
		vector<int> changes(n);
		ll cur = mask;
		for(int i=0;i<n;i++){
			changes[i] = cur%n;
			cur/=n;
		}
		for(int i=0;i<n;i++) swap(base[i],base[changes[i]]);
		M[base]++;
	}
	map<vector<int>,ll> :: iterator it;
	vector< pair<ll,vector<int> > > F;
	for(it=M.begin();it!=M.end();it++){
		F.push_back(make_pair((*it).second,(*it).first));
	}
	cout<<"se generaron en total "<<F.size()<<" distintos arreglos de un maximo de " <<totOp<<'\n';
	sort(F.begin(),F.end());
	cout<<"menos probable "<<F[0].first<<"\n";
	show(F[0].second);
	cout<<"mas probable "<<F[F.size()-1].first<<"\n";
	show(F[F.size()-1].second);
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	/*for(int i=1;i<=8;i++){
		solve(i);
	}*/
	int n;cin>>n;
	if(n==1){
		cout<<1<<'\n'<<1<<'\n';
		return 0;
	}
	//maximo es n 0 1 2 3..
	vector<int> base(n);
	for(int i=0;i<n;i++) base[i] = i;
	int flip = (n+1)/2-1;
	int aux = base[0];
	for(int i=0;i<flip;i++){
		base[i] = base[i+1];
	}
	base[flip] = aux;
	for(int i=flip+1;i<n-1;i++) base[i]++;
	base[n-1] = (n+1)/2;
	for(int i=0;i<n;i++) cout<<base[i]+1<<(char)(i+1==n?10:32);

	cout<<n;
	for(int i=1;i<n;i++) cout<<" "<<i;
	cout<<'\n';

	//solve(n);

	return 0;
}

