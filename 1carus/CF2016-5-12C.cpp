#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#define endl '\n'
#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)

using namespace std;

const int MAXN = 100005;
const double eps = 1e-8;
struct node{
	double x,y;
}p,q,s,num[MAXN];

struct distan{
	double val;
	int index;
}f1[2],f2[2];

int target[MAXN]; 
int n;

double dist(double x1,double y1,double x2,double y2)
{
	double t1 = (x1 - x2) * (x1 - x2);
	double t2 = (y1 - y2) * (y1 - y2);
	
	return sqrt(t1 + t2);
}

int main()
{
	while(scanf("%lf %lf %lf %lf %lf %lf",&p.x,&p.y,&q.x,&q.y,&s.x,&s.y) == 6)
	{
		memset(target,0,sizeof(target));
		
		scanf("%d",&n);
		int i;
		for(i= 0;i < n;i++)
		{
			scanf("%lf %lf",&num[i].x,&num[i].y);
		}
		
		f1[0].val = f1[0].val = -0x7fffffff * 1.0;
		f2[0].val = f2[0].val = -0x7fffffff * 1.0;
		
		int index1,index2;
		double ans = 0;
		for(i = 0;i < n;i++)
		{
			double t3 = dist(num[i].x,num[i].y,s.x,s.y);
			double t1 = t3 - dist(num[i].x,num[i].y,p.x,p.y);
			double t2 = t3 - dist(num[i].x,num[i].y,q.x,q.y);
			
			ans += 2 * t3;
			if(t1 > f1[0].val)
			{
				f1[1].val = f1[0].val;
				f1[1].index = f1[0].index;
				f1[0].val = t1;
				f1[0].index = i;
			}
			else if(t1 > f1[1].val)
			{
				f1[1].val = t1;
				f1[1].index = i;
			}
			
			if(t2 > f2[0].val)
			{
				f2[1].val = f2[0].val;
				f2[1].index = f2[0].index;
				f2[0].val = t2;
				f2[0].index = i;
			} 
			else if(t2 > f2[1].val)
			{
				f2[1].val = t2;
				f2[1].index = i;
			}
		}
		
		if(n == 1)
		{
			printf("%.12lf\n",ans - max(f1[0].val,f2[0].val));
			continue;
		}
		
		if(f1[0].index == f2[0].index)
		{
			ans = ans - max(max(max(f1[0].val + f2[1].val,f1[1].val + f2[0].val),f1[0].val),f2[0].val);
		}
		else ans = ans -max(max((f1[0].val + f2[0].val),f1[0].val),f2[0].val);
		
		printf("%.12lf\n",ans);
	}
	return 0;
}
