#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 1e7;

typedef long long LL;

int main()
{
    LL n;
    int iCase = 0;
    while (scanf("%I64d",&n) != EOF)
    {
        LL cnt = 0;
        for (LL i = 1; i * i * i <= n; i++)
            cnt++;

		LL k;
        for (LL i = 1; i * i <= n; i++)
        {
			k = n / i / i;
			if (k >= i)
				cnt += (k - 1) * 3;
			else
				cnt += k * 3;
        }

        for (LL i = 1; i * i * i <= n; i++)
		{
			for (LL j = i + 1; j <= n; j++)
			{
				k = n / i / j;
				if (k > j)
					cnt += (k - j) * 6;
				else
					break;
			}
		}

		printf("Case %d: %I64d\n",++iCase,cnt);
    }



    return 0;
}
