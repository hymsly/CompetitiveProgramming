#include<bits/stdc++.h>

using namespace std;
const int N = (2000);

int D[N+2][N+2];
int nodo[N+2][N+2];

bitset<N> M[2*N + 2];

int n;

void show(){
	cout<<"-----\n";
	for(int i=0;i<2*n;i++){
		string bitsettostring = M[i].to_string<char,std::string::traits_type,std::string::allocator_type>();
		cout<<bitsettostring<<'\n';
	}
	cout<<"-----\n";
}

int main(){
	memset(nodo,-1,sizeof nodo);
	int m;cin>>n>>m;
	int a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		a--;b--;
		M[a].set(n-b-1);
		nodo[a][b] = i;
	}
	for(int i=n;i<2*n;i++){
		M[i].set(2*n-i-1);
	}
	//sacando inversa
	bool ok=0;
	for(int j=0;j<n;j++){
		if(!M[j].test(n-j-1)){//esta apagado el bit que pertenece a la identidad
			int change = -1;
			for(int k=j+1;k<n;k++){
				if(M[k].test(n-j-1)){
					change = k;
					break;
				}
			}
			swap(M[j],M[change]);
			swap(M[j+n],M[change+n]);
			/*bitset<N> aux = M[i];
			M[i] = M[change];
			M[change] = aux;
			aux = M[i+n];
			M[i+n] = M[change+n];
			M[change+n] = aux;*/
		}
		for(int i=0;i<n;i++){
			if(i==j) continue;
			if(M[i].test(n-j-1)){
				//flipamos
				M[i]^=M[j];
				M[i+n]^=M[j+n];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(M[i+n].test(n-j-1)) D[j][i] = 1;
			else D[j][i] = 0;
		}
	}

	vector<string> ans(m);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(nodo[i][j]==-1) continue;
			if(D[i][j]) ans[nodo[i][j]] = "NO";
			else ans[nodo[i][j]] = "YES";
		}
	}
	for(int i=0;i<m;i++) cout<<ans[i]<<'\n';

	return 0;
}

