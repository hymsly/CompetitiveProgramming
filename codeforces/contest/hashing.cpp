#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define SZ(v) (int)v.size()
typedef long long Long;
typedef pair<int, int> Pair;
const int N = (1e5);

struct HASH
{
	int B;
	Long MOD;
	vector<Long> pot;
	vector<Long> hpref;
	//vector<Long> sumpref;
	//vector<Long> multpref;
	HASH()
	{
		B = 29;
		MOD = (Long)(1e9 + 7);
	}
	HASH(int _B, Long _MOD)
	{
		B = _B;
		MOD = _MOD;
	}
	void setString(string &s)
	{
		int len = SZ(s);
		hpref.resize(len);
		pot.resize(len);
		pot[0] = 1LL;
		for (int i = 1; i < s.size(); i++)
			pot[i] = (pot[i - 1] * B) % MOD;
		//PREFIJOS
		hpref[0] = (s[0] - 'a' + 1);
		for (int i = 1; i < s.size(); i++)
		{
			hpref[i] = (hpref[i - 1] * B + (s[i] - 'a' + 1)) % MOD;
		}
		//SUMA Y MULTIPLICACION, SIRVE PARA VALIDAR SI UN STRING ES UN ORDENAMIENTO DE OTRO STRING
		/*sumpref.resize(len);
		multpref.resize(len);
		sumpref[0] = (s[0] - 'a' + 1);
		multpref[0] = (s[0] - 'a' + 1);
		for (int i = 1; i < s.size(); i++)
		{
			sumpref[i] = (sumpref[i - 1] + (s[i] - 'a' + 1)) % MOD;
			multpref[i] = (multpref[i - 1] * (s[i] - 'a' + 1)) % MOD;
		}*/
	}
	Long hsub(int i, int j)
	{
		if (i == 0)
			return hpref[j];
		return ((hpref[j] - hpref[i - 1] * pot[j - i + 1]) % MOD + MOD) % MOD;
	}
	/*Pair ordenString(int i, int j)
	{
		if (i == 0)
			return {sumpref[j], multpref[j]};
		return {((sumpref[j] - sumpref[i - 1]) % MOD + MOD) % MOD, (multpref[j] * inv(multpref[i - 1], MOD)) % MOD};
	}*/
} h1, h2;

string a;
bool eval(Long len1, Long len2)
{
	set<pair<Long, Long>> zero, uno;
	Long pos = 0;
	pair<Long, Long> cur1, cur2;
	for (int i = 0; i < SZ(a); i++)
	{
		Long valor1, valor2;
		if (a[i] == '0')
		{
			valor1 = h1.hsub(pos, pos + len1 - 1);
			valor2 = h2.hsub(pos, pos + len1 - 1);
			pos += len1;
			cur1 = mp(valor1, valor2);
			zero.insert(mp(valor1, valor2));
		}
		else
		{
			valor1 = h1.hsub(pos, pos + len2 - 1);
			valor2 = h2.hsub(pos, pos + len2 - 1);
			pos += len2;
			cur2 = mp(valor1, valor2);
			uno.insert(mp(valor1, valor2));
		}
	}
	if (zero.size() == 1 && uno.size() == 1 && (cur1.fi != cur2.fi || cur1.se != cur2.se))
		return true;
	return false;
}
struct tup
{
	Long gcd, x, y;
	tup() {}
	tup(Long a, Long b, Long c)
	{
		gcd = a;
		x = b;
		y = c;
	}
};
tup extGcd(Long a, Long b)
{
	if (b == 0)
		return tup(a, 1, 0);
	tup ret = extGcd(b, a % b);
	return tup(ret.gcd, ret.y, ret.x - a / b * ret.y);
}
struct euclides
{
	Long a, b, n; //a*x+b*y==n
	Long x0, y0;
	Long pasoX, pasoY;
	//a*(x0+k*pasoX) + b*(x1-k*pasoY)==c
	Long miniK, maxiK;
	bool valid; //representa si existe respuesta o no
	euclides()
	{
		valid = false;
	}
	euclides(Long _a, Long _b, Long _n)
	{
		a = _a;
		b = _b;
		n = _n;
	}
	void evalGcd()
	{
		Long m = __gcd(a, b);
		if (n % m)
			return;
		valid = true;
		tup cur = extGcd(a, b);
		x0 = cur.x * n / m;
		y0 = cur.y * n / m;
		pasoX = b / m;
		pasoY = a / m;
		miniK = (b * y0 - n) / (pasoY * b);
		maxiK = (n - a * x0) / (pasoX * a);
	}
	Pair kth(Long k)
	{
		return {x0 + k * pasoX, y0 - k * pasoY};
	}
};

int main()
{
	ios::sync_with_stdio(0);
	string s;
	cin >> a >> s;
	h2 = HASH(29, (1e9 + 9));
	h1.setString(s);
	h2.setString(s);
	Long cnt0 = 0, cnt1 = 0;
	for (int i = 0; i < SZ(a); i++)
	{
		if (a[i] == '0')
			cnt0++;
		else
			cnt1++;
	}
	euclides EC = euclides(cnt0, cnt1, SZ(s));
	EC.evalGcd();
	Long ans = 0;
	if (EC.valid)
	{
		for (Long k = EC.miniK; k <= EC.maxiK; k++)
		{
			Pair value = EC.kth(k);
			if (value.first <= 0 || value.second <= 0)
				continue;
			if (eval(value.first, value.second))
				ans++;
		}
	}
	cout << ans << endl;

	return 0;
}
