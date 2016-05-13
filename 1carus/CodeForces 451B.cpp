#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#define endl '\n'
#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)

using namespace std;

const int MAXN = 1e5 + 5;

int num[MAXN],tnum[MAXN],n;
int dp[MAXN];

int main()
{
	while(scanf("%d",&n) == 1)
	{
		int i;
		//index[0] = index[1] = 0;
		for(i = 1;i <= n;i++)
		{
			scanf("%d",&num[i]);
		}
		
		int flag = 0,l = 0,r = 0,cont = 0;
		for(i = 1;i <= n;i++)
		{
			if(num[i] >= num[i + 1] && i != n && flag == 0)
			{
				l = i;
				cont++;
				flag = 1;
				if(cont > 1)break;
			}
			
			if(num[i] <= num[i + 1] && flag == 1)
			{
				flag = 0;	
				r = i;
			}
		}
		
		if(r == 0 && l == 0)l = r = 1;
		if(r == 0)r = n;
		
		if(cont > 1)
		{
			cout << "no" << endl;
			continue;
		}
		
		flag = 1;
		if(l >= 1 && num[r] < num[l - 1])flag = 0;
		if(r <= n - 1 && num[l] > num[r + 1])flag = 0;
		
		if(flag == 0)
		{
			cout << "no" << endl;
		}
		else
		{
			cout << "yes" << endl;
			cout << l << " " << r << endl;
		}
	}
	return 0;
}
