#include<cstdio>
#include<cstring>
#define mem(a) memset(a,0,sizeof(a))
#define MAXN 2000007
#define maxn 1030302
#define lf(a) a*a*a
int hash[MAXN + 5], next[maxn + 5];
int sum[maxn + 5], index;
void insert(int num)//插入一个数num
{
	int numm = num>0 ? num : -num;
	int h = (numm%MAXN + numm / MAXN) % MAXN;
	sum[index] = num;
	next[index] = hash[h];
	hash[h] = index++;
}
int is_find(int num)
{
	int number = 0;
	int numm = num>0 ? num : -num;
	int h = (numm%MAXN + numm / MAXN) % MAXN;
	int u = hash[h];
	while (u) {               
		if (sum[u] == num)number++;
		u = next[u];
	}
	return number;
}
int main()
{
	int a[5];
	while (~scanf("%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4]))
	{
		mem(sum); index = 1;
		mem(hash); mem(next);
		int i, j, k, count = 0;
		for (i = -50; i <= 50; i++)if (i != 0)
			for (j = -50; j <= 50; j++)if (j != 0)
				for (k = -50; k <= 50; k++)if (k != 0)
					insert(a[0] * lf(i) + a[1] * lf(j) + a[2] * lf(k));

		for (i = -50; i <= 50; i++)if (i != 0)
			for (j = -50; j <= 50; j++)if (j != 0)
				count += is_find((-a[3])*lf(i) - a[4] * lf(j));
		printf("%d\n", count);
	}
	return 0;
}
