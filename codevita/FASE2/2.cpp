#include<bits/stdc++.h>



using namespace std;

#define SZ(x) (int)x.size()

#define mp make_pair

#define fi first
#define pb push_back

#define se second

#define fore(i,a,b) for(int i=a,to=b;i<to;i++)

typedef long long ll;

typedef long double ld;


int getId(string x){
	reverse(x.begin(),x.end());
	x.pop_back();
	reverse(x.begin(),x.end());
	int ans = 0;
	for(int i=0;i<SZ(x);i++){
		ans*=10;
		ans+=(x[i]-'0');
	}
	return ans;
}

struct result{
	int white,black;
	int score;//1 gana white,0 empta y -1 gana black
	int ronda;
	result(){}
	result(string input){
		stringstream ss(input);
		string player;ss>>player;
		white = getId(player);
		ss>>player;
		black = getId(player);
		string resta;ss>>resta;
		if(resta=="0.5-0.5")score=0;
		if(resta=="1-0")score=1;
		if(resta=="0-1")score=-1;
		ss>>ronda;
	}
	void show(){
		cout<<white<<" "<<black<<" "<<score<<" "<<ronda<<endl;
	}
};

vector<result> v;

pair<int,int> query(int id,int time){
	int monto=0;
	int blackMonto=0;
	for(int i=0;i<SZ(v);i++){
		if(v[i].ronda>time) continue;
		if(v[i].white == id){
			if(v[i].score==1)monto += 2;
			if(v[i].score==0)monto ++;
		}else if(v[i].black == id){
			if(v[i].score==-1)monto += 2,blackMonto++;
			if(v[i].score==0)monto ++;
		}
	}
	return mp(monto,blackMonto);
}
struct user{
	int id;
	int score;
	int blackScore;
	user(){}
	user(int _id,int _score,int _blackScore){
		id = _id;
		score = _score;
		blackScore = _blackScore;
	}
};
int n,r;
vector<user> U;

int A[50];

bool operator <(const user &a,const user &b){
	if(a.score!=b.score) return a.score < b.score;
	if(a.blackScore != b.blackScore) return a.blackScore < b.blackScore;
	return a.id>b.id;
}

void proces(){
	for(int i=1;i<=n;i++){
		pair<int,int> p = query(i,r);
		A[i] = p.fi;
		U.pb(user(i,p.fi,p.se));
	}
}

void query3(int id1,int id2,int time){
	int res = abs(query(id1,time).fi - query(id2,time).fi);
	if(res%2==0){
		cout<<res/2<<".0"<<endl;
	}else{
		cout<<res/2<<".5"<<endl;
	}
}

void query2(int id1,int id2){
	int monto=0;
	for(int i=0;i<SZ(v);i++){
		if(v[i].white == id1 && v[i].black == id2){
			if(v[i].score==1)monto++;
			else if(v[i].score==-1)monto--;
		}else if(v[i].white == id2 && v[i].black == id1){
			if(v[i].score==1)monto--;
			else if(v[i].score==-1)monto++;
		}
	}
	monto = abs(monto);
	cout<<monto<<".0"<<endl;
}

vector<int> read(string s){
	stringstream ss(s);
	int x;
	vector<int> ans;
	while(ss>>x) ans.pb(x);
	return ans;
}

void show(user cur){
	cout<<"P"<<cur.id<<":"<<cur.score/2;
	if(cur.score%2==0)cout<<".0"<<endl;
	else cout<<".5"<<endl;
}


int main(){

	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

	string s;
	cin>>n>>r;
	getline(cin,s);
	int tot = n*(n-1)*r/2;
	for(int i=0;i<tot;i++){
		getline(cin,s);
		v.pb(result(s));
	}
	proces();
	sort(U.begin(),U.end());
	show(U[n-1]);
	show(U[0]);
	int q;cin>>q;
	getline(cin,s);
	while(q--){
		getline(cin,s);
		vector<int> asd = read(s);
		if(SZ(asd)==2) query2(asd[0],asd[1]);
		else if(SZ(asd)==3) query3(asd[0],asd[1],asd[2]);
	}



	return 0;

}
