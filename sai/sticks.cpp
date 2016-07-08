#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int stk[70];
int vis[70];
int n,len;

bool dfs(int id,int cur,int s)
{
	if(cur==0)
	{
		s-=len;
		if(s==0)
			return true;

		for(id=0;vis[id]==1;id++);
		vis[id]=1;

		if(dfs(id+1,len-stk[id],s))
			return true;
		vis[id]=0;
		s+=len;
	}
	else
	{
		for(int i=id;i<n;i++)
		{
			if(i>0&&stk[i]==stk[i-1]&&vis[i-1]==0)continue;

			if(stk[i]<=cur&&vis[i]==0)
			{
				cur-=stk[i];
				vis[i]=1;
				if(dfs(i,cur,s)==true)return true;
				cur+=stk[i];
				vis[i]=0;

				if(stk[i]==cur)
					break;
			}
		}
	}
	return false;
}

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int flag;
	while(cin>>n,n)
	{
		flag=0;
		int sum=0;
		memset(vis,0,sizeof(vis));

		for(int i=0;i<n;i++)
		{
			cin>>stk[i];
			sum+=stk[i];
		}

		sort(stk,stk+n,cmp);

		for(len=stk[0];len<=sum/2;len++)
		{
			if(sum%len==0)
			{
				if(dfs(0,len,sum)==true)
				{
					cout<<len<<endl;
					flag=1;
					break;
				}
			}

		}

		if(flag==0)
		{
			cout<<sum<<endl;
		}
	}
	return 0;
}
