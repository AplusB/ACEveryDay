#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=2e4+9;
const double eps=1e-9;
const double inf=1e99;

struct point
{
	double x,y;
}n1[maxn],n2[maxn];


double RC(point p[],int n,point q[],int m);
double dis(point A,point B);
double dist(point a,point b,point c);
double cross(point a,point b,point c);
double mul(point a,point b,point c);
double seg_dis(point a,point b,point c,point d);
void clockwise(point x[],int len);

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m) && n+m)
	{
		for(int i=0;i<n;i++)
			scanf("%lf%lf",&n1[i].x,&n1[i].y);
		for(int i=0;i<m;i++)
			scanf("%lf%lf",&n2[i].x,&n2[i].y);
		clockwise(n1,n);
		clockwise(n2,m);
		printf("%.5f\n",min(RC(n1,n,n2,m),RC(n2,m,n1,n)));
	}
	return 0;
}

void clockwise(point x[],int len)
{
	for(int i=0;i<len-2;i++)
	{
		double tmp=cross(x[i],x[i+1],x[i+2]);
		if(tmp>eps) return ;
		else if(tmp<-eps)
		{
			reverse(x,x+len);
			return ;
		}
	}
}

double RC(point p[],int n,point q[],int m)
{
	p[n]=p[0],q[m]=q[0];
	int ymin,ymax;
	ymin=ymax=0;
	for(int i=0;i<n;i++)
	{
		if(p[i].y<p[ymin].y)
			ymin=i;
	}
	for(int i=0;i<m;i++)
	{
		if(q[i].y>q[ymax].y)
			ymax=i;
	}
	double ans=inf;
	for(int i=0;i<n;i++)
	{
		double tmp;
		//while((tmp=cross(p[ymin],q[ymax+1],p[ymin+1])-cross(p[ymin],q[ymax],p[ymin+1]))>eps)
		while(tmp=cross(p[ymin+1],q[ymax+1],p[ymin])-cross(p[ymin+1],q[ymax],p[ymin])>eps)
			ymax=(ymax+1)%m;
		if(tmp<-eps) ans=min(ans,dist(p[ymin],p[ymin+1],q[ymax]));
		else ans=min(ans,seg_dis(p[ymin],p[ymin+1],q[ymax],q[ymax+1]));
		ymin=(ymin+1)%n;
	}
	return ans;
}

double seg_dis(point a,point b,point c,point d)
{
	double ans=dist(a,b,c);
	ans=min(ans,dist(a,b,d));
	ans=min(ans,dist(c,d,a));
	ans=min(ans,dist(c,d,b));
	return ans;
}

// segment a-b   point c
double dist(point a,point b,point c)
{
	if(dis(a,b)<eps) return dis(a,c);
	if(mul(a,b,c)<-eps) return dis(a,c);
	if(mul(b,a,c)<-eps) return dis(b,c);
	return fabs(cross(a,b,c)/dis(a,b));
}

double mul(point a,point b,point c)
{
	double x1=b.x-a.x,y1=b.y-a.y;
	double x2=c.x-a.x,y2=c.y-a.y;
	return x1*x2+y1*y2;
}

double cross(point a,point b,point c)
{
	double x1=b.x-a.x,y1=b.y-a.y;
	double x2=c.x-a.x,y2=c.y-a.y;
	return x1*y2-x2*y1;
}


double dis(point A,point B)
{
	double dx=A.x-B.x,dy=A.y-B.y;
	return sqrt(dx*dx+dy*dy);
}
