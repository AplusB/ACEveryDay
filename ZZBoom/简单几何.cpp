//hdoj  5563
/*
 笑死我了，居然一遍就过了。 
 题意：给你5个点，让你判断能否组成一个五角星； 
 思路： 
 利用对称性，应该有很多种方法。弱打的很麻烦。但是那个两点式公式去判断另外一个点是否在一条直线上的那个判断，还是蛮喜欢的 
 double dd=(double)(xx[i]-onex)/(twox-onex)-(double)(yy[i]-oney)/(twoy-oney); 
 然后根据题目要求，去使用dd
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAX 110
#define ll __int64
#define mod 9973
#define N 1010

double x[10];
double y[10];

double xx[10];
double yy[10];
bool vis[10];

int solve()
{
	double onex,oney;
	double twox,twoy;
	double k,b;
	for(int i=1;i<=5;i++)
	{
		if(i==1)
		{
			onex=(xx[2]+xx[5])*0.5;
			oney=(yy[2]+yy[5])*0.5;
		
			twox=(xx[3]+xx[4])*0.5;
			twoy=(yy[3]+yy[4])*0.5;
		}
		else if(i==2)
		{
			onex=(xx[1]+xx[3])*0.5;
			oney=(yy[1]+yy[3])*0.5;
		
			twox=(xx[5]+xx[4])*0.5;
			twoy=(yy[5]+yy[4])*0.5;
		}
		else if(i==3)
		{
			onex=(xx[2]+xx[4])*0.5;
			oney=(yy[2]+yy[4])*0.5;
		
			twox=(xx[5]+xx[1])*0.5;
			twoy=(yy[5]+yy[1])*0.5;
		}
		else if(i==4)
		{
			onex=(xx[3]+xx[5])*0.5;
			oney=(yy[3]+yy[5])*0.5;
		
			twox=(xx[1]+xx[2])*0.5;
			twoy=(yy[1]+yy[2])*0.5;	
		} 
		else if(i==5)
		{
			onex=(xx[2]+xx[3])*0.5;
			oney=(yy[2]+yy[3])*0.5;
		
			twox=(xx[1]+xx[4])*0.5;
			twoy=(yy[1]+yy[4])*0.5;
		}
		double dd=(double)(xx[i]-onex)/(twox-onex)-(double)(yy[i]-oney)/(twoy-oney);
		if(dd<0)
			dd=-dd;
		if(dd>0.00001)
		{
			return 0;
		}
	}
	return 1;
}


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=5;i++)
		{
			scanf("%lf%lf",&x[i],&y[i]);
		}
		/*
		xx[1]=x[1];yy[1]=y[1];
		printf("%lf %lf\n",xx[1],yy[1]);
		xx[2]=x[2];yy[2]=y[2];
		printf("%lf %lf\n",xx[2],yy[2]);
		xx[3]=x[4];yy[3]=y[4];
		printf("%lf %lf\n",xx[3],yy[3]);
		xx[4]=x[5];yy[4]=y[5];
		printf("%lf %lf\n",xx[4],yy[4]);
		xx[5]=x[3];yy[5]=y[3];
		printf("%lf %lf\n",xx[5],yy[5]);
		int ans=solve();
		printf("%d\n",ans);
		*/
		
		int flag=0;
		for(int i=1;i<=5;i++)
		{
			xx[1]=x[i];
			yy[1]=y[i];
			
			for(int j=1;j<=5;j++)
			{
				if(i!=j)
				{
					xx[2]=x[j];
					yy[2]=y[j];
					for(int p=1;p<=5;p++)
					{
						if(p!=i&&p!=j)
						{
							xx[3]=x[p];
							yy[3]=y[p];
							for(int q=1;q<=5;q++)
							{
								if(q!=i&&q!=j&&q!=p)
								{
									xx[4]=x[q];
									yy[4]=y[q];
									for(int k=1;k<=5;k++)
									{
										if(i!=k&&j!=k&&p!=k&&q!=k)
										{
											xx[5]=x[k];
											yy[5]=y[k];
											flag=solve();
										}
										if(flag) break;
									}
								} 
								if(flag) break;
							}
						}
						if(flag) break; 
					}
				}
				if(flag) break;
			}
			if(flag) break;
		}
		if(flag) 
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAX 110
#define ll __int64
#define mod 9973
#define N 1010

double x[10];
double y[10];

double xx[10];
double yy[10];
bool vis[10];

int solve()
{
	double onex,oney;
	double twox,twoy;
	double k,b;
	for(int i=1;i<=5;i++)
	{
		if(i==1)
		{
			onex=(xx[2]+xx[5])*0.5;
			oney=(yy[2]+yy[5])*0.5;
		
			twox=(xx[3]+xx[4])*0.5;
			twoy=(yy[3]+yy[4])*0.5;
		}
		else if(i==2)
		{
			onex=(xx[1]+xx[3])*0.5;
			oney=(yy[1]+yy[3])*0.5;
		
			twox=(xx[5]+xx[4])*0.5;
			twoy=(yy[5]+yy[4])*0.5;
		}
		else if(i==3)
		{
			onex=(xx[2]+xx[4])*0.5;
			oney=(yy[2]+yy[4])*0.5;
		
			twox=(xx[5]+xx[1])*0.5;
			twoy=(yy[5]+yy[1])*0.5;
		}
		else if(i==4)
		{
			onex=(xx[3]+xx[5])*0.5;
			oney=(yy[3]+yy[5])*0.5;
		
			twox=(xx[1]+xx[2])*0.5;
			twoy=(yy[1]+yy[2])*0.5;	
		} 
		else if(i==5)
		{
			onex=(xx[2]+xx[3])*0.5;
			oney=(yy[2]+yy[3])*0.5;
		
			twox=(xx[1]+xx[4])*0.5;
			twoy=(yy[1]+yy[4])*0.5;
		}
		double dd=(double)(xx[i]-onex)/(twox-onex)-(double)(yy[i]-oney)/(twoy-oney);
		if(dd<0)
			dd=-dd;
		if(dd>0.00001)
		{
			return 0;
		}
	}
	return 1;
}


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=5;i++)
		{
			scanf("%lf%lf",&x[i],&y[i]);
		}
		/*
		xx[1]=x[1];yy[1]=y[1];
		printf("%lf %lf\n",xx[1],yy[1]);
		xx[2]=x[2];yy[2]=y[2];
		printf("%lf %lf\n",xx[2],yy[2]);
		xx[3]=x[4];yy[3]=y[4];
		printf("%lf %lf\n",xx[3],yy[3]);
		xx[4]=x[5];yy[4]=y[5];
		printf("%lf %lf\n",xx[4],yy[4]);
		xx[5]=x[3];yy[5]=y[3];
		printf("%lf %lf\n",xx[5],yy[5]);
		int ans=solve();
		printf("%d\n",ans);
		*/
		
		int flag=0;
		for(int i=1;i<=5;i++)
		{
			xx[1]=x[i];
			yy[1]=y[i];
			
			for(int j=1;j<=5;j++)
			{
				if(i!=j)
				{
					xx[2]=x[j];
					yy[2]=y[j];
					for(int p=1;p<=5;p++)
					{
						if(p!=i&&p!=j)
						{
							xx[3]=x[p];
							yy[3]=y[p];
							for(int q=1;q<=5;q++)
							{
								if(q!=i&&q!=j&&q!=p)
								{
									xx[4]=x[q];
									yy[4]=y[q];
									for(int k=1;k<=5;k++)
									{
										if(i!=k&&j!=k&&p!=k&&q!=k)
										{
											xx[5]=x[k];
											yy[5]=y[k];
											flag=solve();
										}
										if(flag) break;
									}
								} 
								if(flag) break;
							}
						}
						if(flag) break; 
					}
				}
				if(flag) break;
			}
			if(flag) break;
		}
		if(flag) 
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
