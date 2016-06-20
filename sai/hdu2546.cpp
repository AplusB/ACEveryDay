#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int p[1005];
int dp[1005];

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int n;
	while(cin>>n,n)
	{
		memset(p,0,sizeof(p));

		int sum;
		for(int i=0;i<n;i++)
		{
			cin>>p[i];
		}
		cin>>sum;

		if(sum<5)
		{
			cout<<sum<<endl;
			continue;
		}

		sort(p,p+n);

		int maxp=p[n-1];

		memset(dp,0,sizeof(dp));

		//一个一个放进去
		for(int i=0;i<n-1;i++)
		{
			//注意顺序
			for(int j=sum-5;j>=p[i];j--)//每次都是从最后一个放起
			{
				if(dp[j]<dp[j-p[i]]+p[i])
				{
					dp[j]=dp[j-p[i]]+p[i];
				}
			}
		}
		cout<<sum-maxp-dp[sum-5]<<endl;
	}
	return 0;
}
