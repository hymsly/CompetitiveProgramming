#include<bits/stdc++.h>

using namespace std;
int n,c;

vector<int> divisores;
vector<int> res;

bool f(int x){
	int cnt = 0;
	int aux = c;
	res.clear();
	while(aux > 1){
		if(aux%x==0){
			res.push_back(x);
			aux /= x;
			cnt++;
		}else{
			int p = lower_bound(divisores.begin(),divisores.end(),x) - divisores.begin();
			if(p<=1) return false;
			x = divisores[p-1];
		}
	}
	if(cnt <= n){
		return true;
	}
	return false;
}

void solve(){
	cin>>n>>c;
	if(n==1){
		cout<<c<<'\n';
		return;
	}
	divisores.clear();
	for(int i=1;i*i<=c;i++){
		if(c%i==0){
			divisores.push_back(i);
			if(c != (i*i)) divisores.push_back(c/i);
		}
	}
	if(divisores.size()==2){
		for(int i=1;i<n;i++) cout<<i<<" ";
		cout<<c<<'\n';
		return;
	}
	sort(divisores.begin(),divisores.end());
	//for(int i=0;i<divisores.size();i++) cout<<divisores[i]<<(char)(i+1==divisores.size()?10:32);
	int len = divisores.size();
	int lo=0,hi=len-1;
	while((hi-lo)>1){
		//cout<<lo<<" "<<hi<<endl;
		int mi = (hi+lo)/2;
		if(f(divisores[mi])) hi=mi;
		else lo=mi;
	}
	f(divisores[hi]);
	sort(res.begin(),res.end());
	int less = n-res.size();
	//cout<<less<<endl;
	vector<pair<int,int> > ans;
	ans.push_back(make_pair(1,less));
	for(int i=0;i<res.size();i++){
		if(res[i]==ans[ans.size()-1].first) ans[ans.size()-1].second++;
		else ans.push_back(make_pair(res[i],1));
	}
	int maxi = ans.size()-1;
	for(int i=ans.size()-2;i>=0;i--){
		if(ans[i].first+1==ans[i+1].first) maxi = i;
		else break;
	}	
	reverse(ans.begin()+maxi,ans.end());
	int val=0;
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].second;j++){
			cout<<ans[i].first+val<<(char)(j+1==ans[i].second && i+1==ans.size()?10:32);
			val++;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

