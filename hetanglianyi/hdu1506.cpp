#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
const int N = 100010;
int fl[N], fr[N];
int h[N];
int n ;
int main()
{
	while(scanf("%d", &n) != EOF && n)
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &h[i]);
			fl[i] = fr[i] = 1;
		}
		for(int i = 2; i <= n; i++)
		{
			int last = i-1;
			while(h[i] <= h[last] && last >= 1)
			{
				fl[i] += fl[last];
				last = last - fl[last];
			}
		}
		for(int i = n - 1; i >= 1; i--)
		{
			int last = i + 1;
			while(h[i] <= h[last] && last <= n)
			{
				fr[i] += fr[last];
				last = last + fr[last];
			}
		}
		long long re = 0;
		for(int i = 1; i <= n; i++)
		{
			if(re < 1LL * h[i] * (fl[i] + fr[i] - 1)) re = 1LL * h[i] * (fl[i] + fr[i] - 1);
		}
		cout << re << endl;
	}
	return 0;
}
