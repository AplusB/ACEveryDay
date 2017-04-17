#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<ctime>
#include<iostream>
using namespace std;



int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			sum += x;
		}
		printf("%d\n", sum);
	}
	return 0;
}
