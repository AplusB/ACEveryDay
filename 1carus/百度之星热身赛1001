#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#define endl '\n'

using namespace std;

const int MAXN = 1e6 + 5;

int n;
long long dp[MAXN];
const int MOD = 1000000007;

void init()
{
	dp[1] = 1;dp[2] = 2;dp[3] = 4;
	int i;
	for(i = 4;i <= MAXN;i++)
	{
		dp[i] = ((dp[i - 2] % MOD * (long long)(i - 1)) % MOD + dp[i - 1] % MOD) % MOD;
	}	
}

int main()
{
	init();
	int T,cont = 1;
	scanf("%d",&T);
	while(T--)
	{
		 scanf("%d",&n);
		 cout << "Case #" << cont++ << ":" << endl; 
		 cout << dp[n] << endl;
	}
	return 0;
}
