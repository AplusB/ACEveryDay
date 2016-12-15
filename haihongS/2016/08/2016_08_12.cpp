#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn=2e3+9;
const int inf=2e9+9;

int num[2000];

int  main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&num[i]);
	sort(num,num+n);
	if(num[0]==1)
		printf("-1\n");
	else
		printf("1\n");
	
	return 0;
}
