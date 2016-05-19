#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#define endl '\n'
#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)

using namespace std;

const int MAXN = 1e6 + 5;

long long num[MAXN];
int n;
int b[MAXN];

int main()
{
	while(scanf("%d",&n) == 1)
	{
		int i;
		for(i = 0;i < n;i++)
		{
			scanf("%d",&num[i]);
		}
		
		int cur = 0;
		int index = 0;
		int mmax = 0;
		for(i = 0;i < n;i++)
		{
			if(num[i])
			{
				b[cur] = i;
				if(i - b[cur - 1] + 1 > mmax)
				{
					index = i;
					mmax = i - b[cur - 1];
				}
				cur++;
			} 
		}
		
		if(cur == 0)
		{
			cout << 0 << endl;
			continue;
		}
		
		if(n - 1 - b[cur - 1] + b[0] > mmax)index = i;
		
		long long temp = 0;
		int tn = n;
		long long ans = 0;
		
		while(tn--)
		{
			if(temp != 0)ans++;
			temp += num[index];
			index++;
			if(index == n)index = 0;
		}
		
		cout << ans << endl;
	}
	return 0;
}
