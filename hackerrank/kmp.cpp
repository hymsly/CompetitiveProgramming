#include<bits/stdc++.h>

using namespace std;

void lsp(string K)
{
        vector<int> T(K.size() + 1, -1);
        for(int i = 1; i <= K.size(); i++)
        {
                int pos = T[i - 1];
                while(pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
                T[i] = pos + 1;
        }
 		for(int i=0;i<=K.size();i++){
 			cout<<T[i]<<(char)(i==K.size()?10:32);
		 }
}

int main(){
	int n;cin>>n;
	vector<string> v(n);
	for(int i=0;i<v.size();i++) cin>>v[i];
	for(int i=0;i<v.size();i++){
		lsp(v[i]);
	}

	return 0;
}

