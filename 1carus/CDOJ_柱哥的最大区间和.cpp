#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define endl '\n'

using namespace std;

const int MAXN = 5e6 + 5;
int pre[MAXN],suf[MAXN],n,num[MAXN];

int main()
{
	while(scanf("%d",&n) == 1)
	{
		int i;
		for(i = 1;i <= n;i++)
		{
			scanf("%d",&num[i]);
		}
		
		memset(pre,-0x3f,sizeof(pre));
		memset(suf,-0x3f,sizeof(suf));
		
		int sum = 0;
		for(i = 1;i <= n;i++)
		{
			sum += num[i];
			pre[i] = max(sum,pre[i - 1]);
			if(sum < 0)sum = 0;
		}
		
		sum = 0;
		for(i = n;i >= 0;i--)
		{
			sum += num[i];
			suf[i] = max(sum,suf[i + 1]);
			if(sum < 0)sum = 0;
		}
		
		int ans = -0x3f3f3f3f;
		for(i = 1;i <= n;i++)
		{
			ans = max(ans,pre[i - 1] + suf[i + 1]);
		}
		
		cout << ans << endl;
	}
	return 0;
}
