#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N=(2500);

bool M[N+2];

int main(){
	//ios_base::sync_with_stdio(0);
	int t;
	scanf("%d",&t);
	int n,k;
	while(t--){
		scanf("%d%d",&n,&k);
		vector< vector<int> > v(n);
		int tam;
		for(int i=0;i<n;i++){
			scanf("%d",&tam);
			v[i].resize(tam);
			for(int j=0;j<tam;j++) scanf("%d",&v[i][j]);
		}
		int res=0;
		for(int i=0;i<n;i++){
			memset(M,0,sizeof(M));
			for(int j=0;j<v[i].size();j++) M[v[i][j]]=1;
			for(int j=i+1;j<n;j++){
				int ans = v[i].size();
				for(int l=0;l<v[j].size();l++){
					if(!M[v[j][l]]) ans++;
				}
				if(ans==k) res++;
			}
		}
		printf("%d\n",res);
	}

	return 0;
}


