#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#define endl '\n'

using namespace std;

const int MAXN = 5e6 + 5;

struct node{
	int index,id;
	long long val;
}num[MAXN];
long long bit[MAXN];
int n;

bool cmp1(node a,node b)
{
	return a.val < b.val;
}

bool cmp2(node a,node b)
{
	return a.index < b.index;
}

long long sum(int x)
{
	long long s = 0;
	while(x > 0)
	{
		s += bit[x];
		x -= x & -x;
	}
	return s;
}

void add(long long x,int val)
{
	while(x <= n)
	{
		bit[x] += val;
		x += x & -x;
	}
}

int main()
{
	while(scanf("%d",&n) == 1 && n)
	{
		int i;
		for(i = 0;i < n;i++)
		{
			scanf("%lld",&num[i].val);
			num[i].index = i;
		}
		sort(num,num + n,cmp1);
		
		int cur = 0;
		for(i = 0;i < n;i++)
		{
			if(i == 0 || num[i].val != num[i - 1].val)num[i].id = ++cur;
			else num[i].id = cur;
		}
		
		sort(num,num + n,cmp2);
		memset(bit,0,sizeof(bit));
		
		long long ans = 0;
 		for(i = 0;i < n;i++)
		{
			ans += i - sum(num[i].id);
			add(num[i].id,1);
		}
		
		cout << ans << endl;
	}
	return 0;
}
