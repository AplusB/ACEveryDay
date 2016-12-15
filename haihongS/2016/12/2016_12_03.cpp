#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 1e6 + 9;
const int inf = 1e9 + 9;

char num[maxn];
int f1[maxn],f2[maxn];
ll zhi[maxn];

int main()
{
	while (~scanf("%s", num))
	{
		memset(f1, 0, sizeof(f1));
		memset(f2, 0, sizeof(f2));
		int len = strlen(num);
		ll a, b;
		scanf("%lld%lld", &a, &b);
		zhi[0] = 1;
		for (int i = 1; i < maxn; i++)
			zhi[i] = (zhi[i - 1] * 10) % b;


		ll v = 0;
		for (int i = 0; i < len; i++)
		{
			v *= 10;
			v += 1LL*(num[i] - '0');
			v %= a;
			if(v==0) f1[i] += 1;
		}
		

		v = 0;
		int cnt = 0;
		for (int i = len - 1; i >= 0; i--)
		{
			v = v + 1LL*(num[i] - '0')*zhi[cnt++] % b;
			v %= b;
			if (num[i] != '0' && v == 0)
				f2[i] += 1;
		}

		int ok = -1;
		for (int i = 0; i < len-1; i++)
		{
			if (f1[i]>0 && f2[i+1]>0)
			{
				ok = i; break;
			}
		}
		if (ok == -1) printf("NO\n");
		else
		{
			printf("YES\n");
			for (int i = 0; i <= ok; i++)
				printf("%c", num[i]);
			printf("\n");
			for (int i = ok + 1; i < len; i++)
				printf("%c", num[i]);
			printf("\n");
		}

	}
	return 0;
}
