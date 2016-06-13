#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#define endl '\n'

using namespace std;

const int MAXN = 1e5 + 5;

int n,m;
int a[MAXN],b[MAXN];
int ra[MAXN],rb[MAXN];
int va[MAXN * 10],vb[MAXN * 10];

int judge(int x,int y)
{
	return floor(sqrt((double)abs(x - y)));
}

int main()
{
	while(scanf("%d %d",&n,&m) == 2)
	{
		memset(va,0,sizeof(va));
		memset(vb,0,sizeof(vb));
		
		int i;
		for(i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);
		}
		
		int ca = 0,cb = 0;
		for(i = 0;i < n;i++)
		{
			if(va[a[i]] == 0)
			{
				ra[ca++] = a[i];
			}
			va[a[i]]++;
		}
		
		for(i = 0;i < m;i++)
		{
			scanf("%d",&b[i]);
		}
		
		for(i = 0;i < m;i++)
		{
			if(vb[b[i]] == 0)
			{
				rb[cb++] = b[i];
			}
			vb[b[i]]++;
		}
		
		long long ans = 0;
		int j;
		for(i = 0;i < ca;i++)
		{
			for(j = 0;j < cb;j++)
			{
				ans += judge(ra[i],rb[j]) * va[ra[i]] * vb[rb[j]];
			}
		} 
		
		cout << ans << endl;
	}
	return 0;
	
}
