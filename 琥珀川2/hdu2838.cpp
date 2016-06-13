#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int n;
int tree[100000];

void add(int pos,int x)
{
	while(pos<=n)
	{
		tree[pos]+=x;
		pos=pos+(pos&-pos);
	}
}

int sum(int i)
{
	int s=0;
	while(i>0)
	{
		s+=tree[i];
		i=i-(i&-i);
	}
	return s;
}

int main()
{
	while(cin>>n&&n)//判断0时用",n"会超时
	{
		memset(tree,0,sizeof(tree));

		int ans=0;
		int num;

		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num);
			add(num,1);
			ans+=(i-sum(num));
		}

		printf("%d\n",ans);
	}
	return 0;
}
