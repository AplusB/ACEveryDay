#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

long long m;
long long ans,sum;

long long f(long long x)
{
	return x * x * x;
}

void dfs(long long dis,long long cur,long long res)
{
	if(cur == 0)
	{
		if(dis > ans)ans = dis,sum = res;
		else if(dis == ans && sum < res)sum = res;
		return;
	}	
	
	long long i;
	for(i = 1;i <= cur;i++)if(f(i + 1) > cur)break;
	
	dfs(dis + 1,cur - f(i),res + f(i));
	dfs(dis + 1,f(i) - 1 - f(i - 1),res + f(i - 1));
}

int main()
{
	scanf("%lld",&m);
	
	dfs(0,m,0);
	
	cout << ans << " " << sum << endl;
	return 0;
}
