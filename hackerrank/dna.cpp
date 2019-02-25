#include<iostream>
#include<vector>

using namespace std;
const int N = (5e5);

int ans[N+2];


string S;

string f(int k){
	string n = S.substr(0,k-1);
	string m = n;
	n.push_back(S[0]);
	string ans = m+n;
	return ans;
}


void KMP(string K,int x){
    vector<int> T(K.size() + 1, -1);
    for(int i = 1; i <= K.size(); i++){
        int pos = T[i - 1];
        while(pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
        T[i] = pos + 1;
    }
    for(int sp = 0, kp = 0; sp < S.size(); sp++){
        while(kp != -1 && (kp == K.size() || K[kp] != S[sp]))
             kp = T[kp];
        kp++;
        if(kp == K.size()){
        	//matches.push_back(sp + 1 - K.size());
        	ans[sp-K.size()+x]=x;
		}
    }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>S;
	int n = ((int) S.size()+1)/2;
	for(int k=1;k<=n;k++){
		if(S[0]!=S[k-1]) continue;
		string t = f(k);
		KMP(t,k);
	}
	for(int i=0;i<S.size();i++){
		cout<<ans[i]<<(char)(i==S.size()?10:32);
	}

	return 0;
}

