#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = (1e6);

bool primo[N+5];
 
void criba(){
    memset(primo,1,sizeof(primo));
    primo[0] = 0;
    primo[1] = 0;
    for(ll i=2;i*i<=N;i++){
        if(primo[i]){
            for(ll j=i*i;j<=N;j+=i) primo[j] = 0;
        }
    }
}

vector<ll> pr,ex;

ll cua(ll val){
    ll y = (ll)(sqrt(val)+0.05);
    if(y*y==val) return y;
    return -1;
}

ll mul(ll a, ll b, ll c){
    ll x = 0, y = a % c;
    while(b > 0){
         
        if(b % 2 == 1)x = (x + y)%c;
        y = (y * 2) % c;
        b /= 2;
    }
    return x%c;
}

ll modd(ll a,ll b,ll c){
    ll x=1,y=a; 
    while(b > 0){
         
        if(b % 2 == 1)x = mul(x,y,c);
        y = mul(y, y, c); 
        b /= 2;
    }
    return x%c;
}

bool Miller(ll p,int iter){

    if(p < 2)return false;
    if(p != 2 && p % 2 == 0)return false;
     
    ll s = p - 1;
    while(s % 2 == 0)s/=2;
     
    for(int i = 0;i < iter; i++){
        ll a = rand() % (p - 1) + 1, temp = s;
        ll mod = modd(a, temp, p);
        while(temp != p - 1 && mod != 1 && mod != p - 1){
            mod = mul(mod, mod, p);
            temp *= 2;
        }
        if(mod != p - 1 && temp % 2 == 0)return false;
    }
    return true;
}


bool is_primo(ll val){
	return Miller(val,20); 
}

ll pot(ll x, ll y,ll mod){//(x^y)%mod
    ll ans = 1;
    if(y == 1) return x%mod;
	if(y&1) ans = x;
	ll val = pot(x,y/2,mod);
	ans *= val;
	ans %= mod;
	ans *= val;
	ans %= mod;
	return ans;
}

ll PollardRho(ll val){
    srand (time(NULL));
    ll x = (rand()%(val-2))+2;
    ll y = x;
    ll c = (rand()%(val-1))+1;
    ll d = 1;  
    while (d==1){
        x = (pot(x, 2, val) + c + val)%val;
        y = (pot(y, 2, val) + c + val)%val;
        y = (pot(y, 2, val) + c + val)%val;
        d = __gcd(abs(x-y), val);
        if (d==val) return PollardRho(val);
    }
    return d;
}

void fact(ll val){
	for(ll i=2;i<=N;i++){
        if(primo[i]){
            if((i*i*i) > val) break;
            ll cnt = 0;
            while(val%i==0){
                val/=i;
                cnt++;
            }
			pr.push_back(i);
			ex.push_back(cnt);
        }
    }
    if(val==1) return;
    ll raiz = cua(val);
    if(raiz!=-1){
    	pr.push_back(raiz);
    	ex.push_back(2LL);
    }else if(is_primo(val)){
    	pr.push_back(val);
    	ex.push_back(1LL);
    }else{
		ll prime = PollardRho(val);
		val /= prime;
		if(val < prime) swap(val,prime);
		pr.push_back(prime);
		ex.push_back(1LL);
		pr.push_back(val);
		ex.push_back(1LL);
    }
}


int main(){
	ll n,x,y;
	cin>>n>>x>>y;
	if(y%x!=0){
		cout<<"0\n";
		return 0;
	}
	criba();
	fact(y);
	

	return 0;
}

