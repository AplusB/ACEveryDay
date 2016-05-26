#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
int n;
double p;
double logg[400010], sum[400010];
int main()
{
	for (int i = 1; i <= 4 * 100000; i++)
		logg[i] = log(i);
	sum[0] = 0;
	for (int i = 1; i <= 4 * 100000; i++)
		sum[i] = sum[i-1] + logg[i];

	int t= 0;
	while (scanf("%d%lf", &n, &p) != EOF)
	{
		double re = 0.0000;
		for (int i = 0; i < n; i++)
		{
			double x = (n+1) * log(p) + i * log(1-p) + log(n-i);
			x += sum[n+i] - sum[i] - sum[n];
			re += exp(x);
			//cout <<i <<' '<< exp(x)<< endl;
		}

		p = 1 - p;
		for (int i = 0; i < n; i++)
		{
			double x = (n+1) * log(p) + i * log(1-p) + log(n-i);
			x += sum[n+i] - sum[i] - sum[n];
			re += exp(x);
		}
		printf ("Case %d: %.6f\n", ++t, re);
	}

	return 0;
}
