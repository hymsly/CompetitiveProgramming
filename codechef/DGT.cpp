#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s;
ll dp( int pos , vector<pair<int,int> > v , int menor ,int left){
	if ( pos == n ){
		for(int i=0;i<v.size();i++){
			if(v[i].second!=0) return 0;
		}
		return 1;
	}
	ll ans=0;
	if ( menor ){
		for ( int i = 0 ; i < 10 ; i++ ){
			vector< pair<int,int> > aux = v;
			if(!left || i!=0){
				for(int j=0;j<aux.size();j++){
					if(aux[j].first == i){
						aux[j].second--;
						break;
					}
				}
			}
			ans += dp( pos + 1 , aux , 1 ,left && (i==0));
		}
	}else{
		for ( int i = 0 ; i <= s[ pos ]-'0' ; i++){
			vector< pair<int,int> > aux = v;
			if(!left || i!=0){
				for(int j=0;j<aux.size();j++){
					if(aux[j].first == i){
						aux[j].second--;
						break;
					}
				}
			}
			ans += dp( pos + 1 , aux , i < s[ pos ]-'0' ,left && (i==0));
		}
	}
	return ans;
}

ll dgt(string x,vector< pair<int,int> > debe,int maxi){
	ll ans=0;
	if(maxi>x.size()) return 0;
	else{
		ans+=dp(0,debe,0,1);
		cout<<s<<endl;		
		for(int i=0;i<debe.size();i++){
			cout<<debe[i].first<<" "<<debe[i].second<<endl;
		}
		cout<<endl;
	}
	return ans;
}

ll f(string x,vector<int> v){
	n=(int)x.size();
	s=x;
	ll ans=0;
	for(int mask=1;mask<(1<<10);mask++){
		vector< pair<int,int> > should;
		int cnt=0;
		for(int j=0;j<10;j++){
			if(mask & (1<<j)){
				cnt+=v[j];
				should.push_back(make_pair(j,v[j]));
			}
		}
		ans += dgt(x,should,cnt);		
	}
	return ans;
}

ll toi(string s){istringstream is(s);ll x;is>>x;return x;}
string tos(ll t){stringstream
 st; st<<t;return st.str();}

string prev(string x){
	ll 	cte = toi(x);
	cte--;
	return tos(cte);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;cin>>t;
	string a,b;
	while(t--){
		cin>>a>>b;
		vector<int> v(10);
		a = prev(a);
		for(int i=0;i<10;i++) cin>>v[i];
		//cout<<f(b,v)<<endl;
		//cout<<f(a,v)<<endl;
		cout<<( toi(b) - toi(a) ) - ( f(b,v) - f(a,v) )<<endl;
		
	}

	
	return 0;
}

