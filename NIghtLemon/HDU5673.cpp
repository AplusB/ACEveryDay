#include<bits/stdc++.h>
//#Motzkin Number 默慈金数
//#Catalan Number 卡塔兰数
//#线性求逆元 
using namespace std;

#define MAXN 1000007
typedef long long ll;
const ll MOD = 1000000007;

ll remod[MAXN];
ll a[MAXN];

void init()
{
	remod[1] = 1LL;
	for(int i=2;i<MAXN;i++)
		remod[i] = ((MOD - MOD / i) * remod[MOD % i]) % MOD;
}

int main()
{
	init();
	int T ;
	ll Nmax = 2LL ,n ; 
	a[1] = 1;
	a[2] = 2;
	cin>>T;
	while(T--){
		cin>>n;
		if(n>Nmax) {
			for(ll i=Nmax +1; i<=n; i++)
				a[i] = ((a[i-1] * (2*(i-1)+3) +3*(i-1)*a[i-2]) % MOD * remod[i-1+3])% MOD;
			Nmax = n;
		}
		cout<<a[n]<<endl;
	}
	return 0;
} 
