#include<bits/stdc++.h>

using namespace std;

vector<string> v;
int n;
int fil[30],col[30];

int f(string s){
	int ans = 0;
	for(int i=0;i<s.size();i++) if(s[i]=='1') ans+=(1<<i);
	return ans;
}

void fill(){
	memset(fil,0,sizeof fil);
	memset(col,0,sizeof col);
	for(int i=0;i<n;i++) fil[i] = f(v[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(v[j][i]=='1') col[i]+=(1<<j);
		}
	}
	//for(int i=0;i<n;i++) cout<<fil[i]<<(char)(i+1==n?10:32);
	//for(int i=0;i<n;i++) cout<<col[i]<<(char)(i+1==n?10:32);
}

int main(){
	int t;cin>>t;
	string s;
	while(t--){
		cin>>s;
		n = s.size();
		v.resize(n);
		v[0] = s;
		for(int i=1;i<n;i++) cin>>v[i];
		fill();
		int ans = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=i;k<n;k++){
					for(int l=j;l<n;l++){
						//desde i,j hasta k,l
						bool ok=1;
						for(int m=i;m<=k;m++){
							if(((col[m]%(1<<l+1))>>j) != (1<<(l-j+1))-1) ok=0;
						}
						for(int m=j;m<=l;m++){
							if(((fil[m]%(1<<k+1))>>i) != (1<<(k-i+1))-1) ok=0;
						}
						if(ok){
							/*cout<<"cuadrado valido\n";
							cout<<i<<" "<<j<<endl;
							cout<<k<<" "<<l<<endl;
							for(int m=i;m<=k;m++) for(int r=j;r<=l;r++) cout<<v[m][r]<<(char)(r==l?10:32);*/
							ans = max(ans,(k-i+1)*(l-j+1));
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
		if(t) cout<<'\n';
	}

	return 0;
}

