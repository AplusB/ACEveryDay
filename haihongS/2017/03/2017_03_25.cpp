#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <functional>

using namespace std;
typedef long long ll;
const int maxn = 3e4 + 9;
const double eps = 1e-5;
const double inf = 1e9 + 9;

int n;
double a[maxn], c[maxn];


int main()
{
	//std::ios::sync_with_stdio(false);
	
	while (~scanf("%d", &n))
	{
		scanf("%lf %lf", &a[0], &a[n + 1]);
		for (int i = 1; i <= n; i++)
			scanf("%lf", &c[i]);
		double sum = 0;
		for (int i = n; i >= 1; i--)
		{
			sum += c[i] * (n-i+1);
		}
		
		double ans = a[n + 1] + 1.0*a[0]*n- 2.0*sum;
		ans /= n + 1;
		printf("%.2lf\n", ans);
	}
	return 0;

}
