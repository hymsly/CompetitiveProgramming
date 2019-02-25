#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld EPS = (1e-9);
const ld INF = (1e200);
#define mp make_pair
#define SZ(x) (int)x.size()

struct prob{
	char id;
	ll scoreTotal;
	ll cntCases;
	prob(){}
	prob(char _id,ll _scoreTotal,ll _cntCases){
		id = _id;
		scoreTotal = _scoreTotal;
		cntCases = _cntCases;
	}
	void show(){
		cout<<id<<" "<<scoreTotal<<" "<<cntCases<<endl;
	}
} P[30];

struct user{
	vector< pair<ld,bool> > scores;
	int id;
	user(){
		scores.clear();
	}
	user(int _id,int problems){
		id = _id;
		scores.clear();
		scores.resize(problems);
		for(int i=0;i<problems;i++)scores[i]=mp(0.0L,false);
	}
	void add(int problem,ll casosbien,ll casostotal,ll scoreTotal){
		if(scores[problem].second) return;
		if(casosbien==casostotal)scores[problem]=mp((ld)scoreTotal,true);
		else{
			scores[problem].first = max(scores[problem].first,(ld)scoreTotal*(ld)casosbien/(ld)casostotal);
		}
		//cout<<"add "<<id<<" "<<problem<<" "<<scores[problem].first<<endl;
		return;
	}
	pair<ld,ld> aggregate(){
		ld partialScore = 0.0;
		ld totalScore = 0.0;
		for(int i=0;i<SZ(scores);i++){
			if(scores[i].second)totalScore+=scores[i].first;
			else partialScore+=scores[i].first;
		}
		return mp(totalScore,partialScore);
	}
} U[10005];

struct result{
	int userId;
	ld totalScore;
	ld partialScore;
	result(){}
	result(int _userId,ld _totalScore,ld _partialScore){
		userId = _userId;
		totalScore = _totalScore;
		partialScore = _partialScore;
	}
};

bool operator<(const result &a,const result &b){
	if(abs(a.totalScore-b.totalScore)<EPS) return a.partialScore>b.partialScore;
	return a.totalScore>b.totalScore;
}
bool equal(double i, double j){
    return (abs(i - j) < EPS);
}
void printDecimal(double d){
	d = round(d*100)/100;
	if(equal(d,floor(d)))printf("%.1f\n", d);
	else if(equal(d*10,floor(d*10)))printf("%.1f\n", d);
    else printf("%.2f\n", d);
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n;cin>>n;
	for(int i=0;i<n;i++){
		char id;cin>>id;
		P[id-'A'].id = id;
		cin>>P[id-'A'].scoreTotal>>P[id-'A'].cntCases;
	}
	//for(int i=0;i<n;i++)P[i].show();
	int u,m;cin>>u>>m;
	for(int i=0;i<=u;i++) U[i] = user(i,n);
	int useZero = 1;
	for(int i=0;i<m;i++){
		int id;cin>>id;
		if(id==0) useZero=0;
		char probId;cin>>probId;
		ll cntCasos = P[probId-'A'].cntCases;
		int submissionID;cin>>submissionID;
		ll cntAcc = 0;
		for(ll i=0;i<cntCasos;i++){
			string judge;cin>>judge;
			if(judge=="A")cntAcc++;
		}
		U[id].add(probId-'A',cntAcc,cntCasos,P[probId-'A'].scoreTotal);
	}
	vector<result> ans;
	for(int i=useZero;i<u+useZero;i++){
		pair<ld,ld> res = U[i].aggregate();
		//cout<<i<<" "<<res.first<<" "<<res.second<<endl;
		if(res.first+res.second<EPS) continue;
		ans.push_back(result(i,res.first,res.second));
	}
	sort(ans.begin(),ans.end());
	int pos = 1;
	ld maximo = INF;
	for(int i=0;i<SZ(ans);i++){
		if(equal(ans[i].totalScore + ans[i].partialScore,maximo)) printf("%d %d %d ",pos,ans[i].userId,(int)ans[i].totalScore);
		else printf("%d %d %d ",i+1,ans[i].userId,(int)ans[i].totalScore),pos=i+1,maximo = ans[i].totalScore + ans[i].partialScore;
		printDecimal((double)ans[i].partialScore);
	}
	//cout<<"1 2 200 98.33\n2 1 100 15.0";

	return 0;
}

