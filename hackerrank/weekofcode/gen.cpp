#include<bits/stdc++.h>

using namespace std;

int main(){
	int n=1000;
	cout<<3*n<<endl;
	vector<pair<int,int> > v(n);
	for(int i=0;i<n;i++){
		int p = rand()%100000+1;
		int q = rand()%100001;
		v[i] = make_pair(p,q);
		cout<<"+ "<<p<<" "<<q<<endl;
	}
	for(int i=0;i<n;i++){
		cout<<"? ";
		int p = rand()%100001;
		cout<<p<<endl;
	}
	for(int i=0;2*i<n;i++){
		cout<<"- "<<v[i].first<<" "<<v[i].second<<endl;
	}
	for(int i=0;2*i<n;i++){
		cout<<"? ";
		int p = rand()%100001;
		cout<<p<<endl;
	}

	return 0;
}

