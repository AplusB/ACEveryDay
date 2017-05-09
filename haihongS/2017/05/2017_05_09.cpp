#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <ctime>
#include <iostream>

using namespace std;
typedef long long ll;

const int maxn = 5e5 + 9;
const ll inf = 1e15;

struct II
{
	double x, y, z;
	char c[10];
}m[100];

double cal(II a, II b, II c);
double dis(II a, II b);

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%s %lf %lf %lf", m[i].c, &m[i].x, &m[i].y, &m[i].z);
		}
		double ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				for (int k = j + 1; k < n; k++)
				{
					if ((m[i].c[0] == m[j].c[0] && m[j].c[0] == m[k].c[0])
						|| (m[i].c[0] != m[j].c[0] && m[i].c[0] != m[k].c[0] && m[j].c[0] != m[k].c[0]))
					{
						double area = cal(m[i], m[j], m[k]);
						ans = max(ans, area);
					}
				}
			}
		}
		printf("%.5lf\n", ans);
	}
	return 0;
}

double cal(II a, II b, II c)
{
	double d1 = dis(a, b);
	double d2 = dis(a, c);
	double d3 = dis(b, c);

	double p = (d1 + d2 + d3) / 2.0;
	return sqrt(p*(p - d1)*(p - d2)*(p - d3));
}

double dis(II a, II b)
{
	double ans = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)
		+ (a.z - b.z)*(a.z - b.z);
	return sqrt(ans);
}
