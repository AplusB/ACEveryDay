//poj  1270

//DFS写多了感觉好有啊，就是排序过程中可能会有多种情况。
//我们考虑一下怎么排好一个位置，这个位置可能有多个东西可以占，那么这些东西对于这个位置都是等价的，
//那么我们可以采用深搜下+回溯来解决。
//其实还是蛮简单的

#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

char ans[30];
char ss[30];
char s[100];
int ma[30][30];
int pre[30];
int gg[200];
int num;

void tuopu(int u)
{
	if(u==num)
	{
	    ans[u]='\0';
		printf("%s\n",ans);
		return;
	}
	for(int i=0;i<num;i++)
	{
		if(pre[i]==0)
		{
			ans[u]=ss[i];
			pre[i]--;
			for(int j=0;j<num;j++)
			{
				if(ma[i][j])
				{
					pre[j]--;
				}
			}
			tuopu(u+1);
			//回溯;
			pre[i]++;
			for(int j=0;j<num;j++)
			{
				if(ma[i][j])
				{
					pre[j]++;
				}
			}
		}
	}
}


int main()
{
	while(gets(s))
	{
		int L=strlen(s);
		num=0;
		for(int i=0;i<L;i++)
		{
			if(s[i]>='a'&&s[i]<='z')
			{
				ss[num++]=s[i];
			}
		}
		ss[num]='\0';
		sort(ss,ss+num);

		for(int i=0;i<num;i++)
		{
			gg[ss[i]]=i;
		}

		char s1[110];
		gets(s1);
		int LL=strlen(s1);
		int j1,j2,flag;
		flag=0;
		memset(pre,0,sizeof(pre));
		memset(ma,0,sizeof(ma));

		for(int i=0;i<LL;i++)
		{
			if(s1[i]<'a'||s1[i]>'z')
				continue;
			if(!flag)
			{
				j1=s1[i];
				flag=1;
			}
			else
			{
				j2=s1[i];
				ma[gg[j1]][gg[j2]]=1;
				pre[gg[j2]]++;
				flag=0;
			}
		}
		tuopu(0);
		puts("");
	}
	return 0;
}

/*
a b f g
a b b f
v w x y z
v y x v z v w v
*/
