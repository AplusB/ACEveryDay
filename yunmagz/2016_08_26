//AIM Tech Round 3 (Div. 2)
//D - Recover the String
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=772002;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
char str[1111111];

int main()
{
	int a,b,c,d;
	int len = 0;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int k,r;
	k = r = 1;
	while(k*(k-1)/2 < a) ++k;
	while(r*(r-1)/2 < d) ++r;
	if(k*(k-1)/2 != a || r*(r-1)/2 != d)
	{
		puts("Impossible");
		return 0;
	}
	bool f = 1;
	if(a == 0 && d == 0)
	{
		if(b == 0 && c == 0) puts("0");
		else if(b == 0 && c == 1) puts("10");
		else if(b == 1 && c == 0) puts("01");
		else puts("Impossible");
		return 0;
	}
	else if(a == 0)
	{
		if(b == 0 && c == 0)
		{
			while(r--) str[len++] = '1';
		}
		else if(b+c == r)
		{
			while(c--) str[len++] = '1';
			str[len++] = '0';
			while(b--) str[len++] = '1';
		}
		else f = 0;
	}
	else if(d == 0)
	{
		if(b == 0 && c == 0)
		{
			while(k--) str[len++] = '0';
		}
		else if(b+c == k)
		{
			while(b--) str[len++] = '0';
			str[len++] = '1';
			while(c--) str[len++] = '0';
		}
		else f = 0;
	}
	else
	{
		if(b+c == k*r)
		{
			while(b)
			{
				while(r > b)
				{
					str[len++] = '1';
					--r;
				}
				str[len++] = '0';
				--k;
				b -= r;
			}
			while(r--) str[len++] = '1';
			while(k--) str[len++] = '0';
		}
		else f = 0;
	}

	if(!f)
	{
		printf("Impossible");
		return 0;
	}
	str[len] = 0;
	puts(str);

	return 0;
}
