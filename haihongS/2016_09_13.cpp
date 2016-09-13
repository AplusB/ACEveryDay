#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 9;

int num[maxn], x[4 * maxn];

int build(int node, int l, int r);
int query(int node, int l, int r, int L, int R, int v);

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &num[i]);
		build(0, 1, n);
		int m;
		scanf("%d", &m);
		while (m--)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			int ans = num[l];
			while (l < r)
			{
				int pos = query(0, 1, n, l + 1, r, ans);
				if (pos <= r)
				{
					ans %= num[pos];
				}
				l = pos;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}

int query(int node, int l, int r, int L, int R, int v)
{
	if (x[node]>v) return R + 1;
	if (L <= l && r <= R)
	{
		if (l == r) return r;
		int mid = l + (r - l) / 2;
		if (x[2 * node + 1] <= v)
			return query(2 * node + 1, l, mid, L, R, v);
		else
			return query(2 * node + 2, mid + 1, r, L, R, v);
	}
	int mid = l + (r - l) / 2;
	if (L <= mid)
	{
		int ans = query(2 * node + 1, l, mid, L, R, v);
		if (ans <= R) return ans;
	}
	if (R > mid)
	{
		int ans = query(2 * node + 2, mid + 1, r, L, R, v);
		if (ans <= R) return ans;
	}
	return R + 1;
}

int build(int node, int l, int r)
{
	if (l == r)
	{
		x[node] = num[l]; return 0;
	}
	int mid = l + (r - l) / 2;
	build(2 * node + 1, l, mid);
	build(2 * node + 2, mid + 1, r);
	x[node] = min(x[2 * node + 1], x[2 * node + 2]);
	return 0;
}
