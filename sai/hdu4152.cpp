#include<iostream>
#include<string.h>
using namespace std;

int goal[30];
int f[25][25];
int g[30];

int main()
{
	int n,m,ans1,ans2;

	while(cin>>n)
	{
		ans1=-1;
		for(int i=0;i<n;i++)
		{
			cin>>goal[i];
		}

		cin>>m;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>f[i][j];
			}
		}

		for(int i=1;i<(1<<m);i++)
		{
			memset(g,0,sizeof(g));
			int num=0;

			for(int j=0;j<m;j++)
			{
				if(i&(1<<j))
				{
					num++;
					for(int k=0;k<n;k++)
						g[k]+=f[j][k];
				}
			}

			int k1;

			for(k1=0;k1<n;k1++)
				if(g[k1]<goal[k1])break;

			if(k1>=n)
			{
				if(num>ans1)
				{
					ans1=num;
					ans2=i;
				}
				else if(num==ans1&&ans2>i)
				{
					ans1=num;
					ans2=i;
				}
			}
		}

		if(ans1==-1)
			cout<<0<<endl;
		else
		{
			cout<<ans1;
			for(int i=0;i<n;i++)
			{
				if(ans2&(1<<i))
				{
					cout<<" "<<i+1;
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
