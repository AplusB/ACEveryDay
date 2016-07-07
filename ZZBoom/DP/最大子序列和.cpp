//HDOJ 1003
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define LL long long
#define INF 0x3f3f3f3f
const double pi = acos(-1.0);

const int mod =9973;

const int N = 1e5+10;

int a[N];

int main()
{
	int qq=1;
	int T,n;
	cin>>T;
	while(T--)
	{
		if(qq>1)
			printf("\n");
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int Max,tep;
		int pt,end,be;
		be=end=pt=0;
		Max=tep=a[0];
		for(int i=1;i<n;i++)
		{
			if(tep>=0)
			{
				tep+=a[i];
			}
			else
			{
				tep=a[i];
				pt=i;
			}
			if(Max<tep)
			{
				Max=tep;
				be=pt;
				end=i;
			}
		}
		printf("Case %d:\n",qq++);
		printf("%d %d %d\n",Max,be+1,end+1);
	}
	return 0;
}



