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
	
	double ans = 0;
	string mm;
	while (cin >> mm)
	{
		
		double n,x;
		scanf("%lf %lf", &n, &x);
		
		double tmp = 1.0*n*x;

		//tmp = 1.0*round(tmp * 10)/10;
		
		ans += tmp;
	}
	ans = 1.0*round(ans * 10) / 10;
	printf("%.1lf\n", ans);
	return 0;

}
