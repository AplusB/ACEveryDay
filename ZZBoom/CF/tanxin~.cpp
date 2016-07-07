//CodeForces 424B 
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
#define ls 2*i
#define rs 2*i+1
#define up(i,x,y) for(i=x;i<=y;i++)
#define down(i,x,y) for(i=x;i>=y;i--)
#define mem(a,x) memset(a,x,sizeof(a))
#define w(a) while(a--)
#define LL long long
const double pi = acos(-1.0);
#define Len 200005
#define mod 19999997
const int INF = 0x3f3f3f3f;
#define exp 1e-6



//题意：n个城市，每个城市有坐标和人口，求以远点为圆心的最小的圆使得人口总数达到上限 

struct asd{
	double x,y;
	int num;
	double r;
};
asd q[1010];

bool cmp(asd z,asd x)
{
	return z.r<x.r;
}

int main()
{
	int n,sum;
	cin>>n>>sum;
	for(int i=0;i<n;i++)
	{
		scanf("%lf%lf%d",&q[i].x,&q[i].y,&q[i].num);
		q[i].r=sqrt(q[i].x*q[i].x+q[i].y*q[i].y);
	}
	sort(q,q+n,cmp);
	for(int i=0;i<n;i++)
	{
		sum+=q[i].num;
		if(sum>=1000000)
		{
			printf("%.7lf\n",q[i].r);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}






