#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=3e2+9;
const ll mod=1e9+7;
const int inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

double v[maxn][maxn];

struct II
{
	int x,y,z,I;
}a[maxn];

double dis(II m1,II m2);

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		memset(v,0,sizeof(v));
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].z,&a[i].I);
			a[i].x+=100,a[i].y+=100;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=200;j++)
			{
				for(int k=0;k<=200;k++)
				{
					II tmp;
					tmp.x=j,tmp.y=k,tmp.z=0;
					double R=dis(tmp,a[i]);
					double cc;
					cc=1.0*a[i].z;
					cc=cc/R;
					cc=fabs(cc);
					double now=0;
					now=1.0*a[i].I/(R*R)*cc;
					v[j][k]+=now;
				}
			}
		}
		double ans=0;
		for(int i=0;i<=200;i++)
			for(int j=0;j<=200;j++)
				ans=max(ans,v[i][j]);
		printf("%.2lf\n",ans);
	}
	return 0;
}

double dis(II m1,II m2)
{
	double ans=(m1.x-m2.x)*(m1.x-m2.x);
	ans+=(m1.y-m2.y)*(m1.y-m2.y);
	ans+=(m1.z-m2.z)*(m1.z-m2.z);
	return sqrt(ans);
}
