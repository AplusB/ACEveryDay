#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define endl '\n'

using namespace std;

const int MAXN = 1e5 + 5;
const int MOD = 1000000007;

struct node
{
	int val,id,i;
}num[MAXN];

long long st[MAXN];
int n,cur;

bool cmp1(node a,node b)
{
	return a.val < b.val;
}

bool cmp2(node a,node b)
{
	return a.i < b.i;
}

long long sum(int i)
{
	long long s = 0;
	while(i > 0)
	{
		s = (s + st[i]) % MOD;
		i -= i & -i;
	}
	return s;
}

void add(int i,int x)
{
	while(i <= cur)
	{
 		st[i] = (st[i] + x)% MOD;
 		i += i & -i;
	}
}

int main()
{
	while(scanf("%d",&n) == 1)
	{
		int i;
		for(i = 0;i < n;i++)
		{
			scanf("%d",&num[i].val);
			num[i].i = i;
		}
		
		sort(num,num + n,cmp1);
		
		for(i = 0;i < n;i++)
		{
			if(i == 0 || num[i].val != num[i - 1].val)num[i].id = ++cur;
			else num[i].id = cur;
		}
		
		memset(st,0,sizeof(st));
		sort(num,num + n,cmp2);
		
		long long ans = 0;
		for(i = 0;i < n;i++)
		{
			long long res = sum(num[i].id) % MOD;
			ans = (ans + res + 1) % MOD;
			add(num[i].id + 1,res + 1);
		}
		
		cout << ans % MOD << endl;
	}
	return 0;
}
