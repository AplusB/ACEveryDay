#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=2e9+9;
double eps=1e-6;
double pi=acos(-1.0);

struct II
{
	int x,y,z;
}a[maxn];

ll g1[500],g2[500];

void deal(string aha,int pos);

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	int cas=1;
	while(t--)
	{
		memset(a,0,sizeof(a));
		int h,s;
		scanf("%d%d",&h,&s);
		for(int i=0;i<s;i++)
		{
			string aha;
			cin>>aha;
			deal(aha,i);
		}
		printf("Case #%d: ",cas++);
		double ans=0;
		for(int i=0;i<s;i++)
		{
			int x=a[i].x,y=a[i].y,z=a[i].z;
			memset(g1,0,sizeof(g1));
			for(int j=1;j<=y;j++)
				g1[j]=1;
			for(int j=1;j<x;j++)
			{
				memset(g2,0,sizeof(g2));
				for(int k=0;k<=x*y;k++)
				{
					if(g1[k]==0) continue;
					for(int mm=1;mm<=y;mm++)
						g2[k+mm]+=g1[k];
				}
				for(int k=0;k<=x*y;k++)
					g1[k]=g2[k];
			}
			int sum=0,s1=0;
			for(int j=0;j<=x*y;j++)
			{
				sum+=g1[j];
				if(j>=h-z) s1+=g1[j];
			}
			if(sum!=0)
			ans=max(ans,1.0*s1/sum);
		}
		ans=min(ans,1.00000000);
		printf("%.6lf\n",ans);
	}
	return 0;
}

void deal(string aha,int pos)
{
	int len=aha.length();
	int flag=0;
	int x,y,z;
	x=y=z=0;
	for(int i=0;i<len;i++)
	{
		if(aha[i]=='d')
		{
			flag=1;continue;
		}
		if(aha[i]=='+')
		{
			flag=2;continue;
		}
		if(aha[i]=='-')
		{
			flag=3;continue;
		}
		if('0'<=aha[i] && aha[i]<='9')
		{
			if(flag==0)
				x=10*x+aha[i]-'0';
			else if(flag==1)
				y=10*y+aha[i]-'0';
			else if(flag>=2)
				z=10*z+aha[i]-'0';
		}
	}
	if(flag==3) z=-z;
	a[pos].x=x,a[pos].y=y,a[pos].z=z;
}
