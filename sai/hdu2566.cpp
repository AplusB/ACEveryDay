//不是必须由n个硬币组合而成
#include<iostream>
using namespace std;

int main()
{
	int n,sum;
	int cnt;

	int t;
	cin>>t;
	while(t--)
	{
		cnt=0;
		cin>>n>>sum;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				if(n-i-j>=0&&n+j+4*i==sum)
					cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

法2：
#include<stdio.h>
int main()
{
	int t,n,m,i,j,k,s;
	scanf("%d",&t);
	while(t--)
	{
		s=0;
		scanf("%d%d",&n,&m);

		*******注意这里的枚举范围***********

		for(i=0;i<=m;i++)
			for(j=0;j<=m/2;j++)
				for(k=0;k<=m/5;k++)
					if(i+2*j+5*k==m&&i+j+k==n)
						s++;

		printf("%d\n",s);
	}
	return 0;
}

