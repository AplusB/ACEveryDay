/*************************************************************************
 > File Name: 18-c.cpp
 > Author: Baiyan
 > 题意：
 > Created Time: 2016年05月18日 星期三 15时20分57秒
 **********************************************************************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>

using namespace std;

const int N =  500005;
// 前向星的模拟链表；
// 只添加节点，不删除，每个机器人都标记一个学习head 和 删除head
// 和一个学习数量和一个删除数量；
struct Node
{
	int val;
	int pre;
}edge[N<<1];
int lhead[N]={0},dhead[N]={0};
int cnt=1;

void add(int val,int &pre)
{
	edge[cnt].val = val;
	edge[cnt].pre = pre;
	pre = cnt++;
}

int num=1;

int main()
{
	int n,m;
	scanf("%d %d", &n,&m);
	while(n--)
	{
		char s[100];
		scanf("%s",s);
		int i;
		scanf("%d", &i);
		if(s[0]=='l')
		{
			int x;
			scanf("%d",&x);
			add(x,lhead[i]);
			dhead[i] = 0;
		}
		else if(s[0]=='r' && s[1]=='o')
		{
			int j = lhead[i];
			int x = edge[j].val;
			add(x,dhead[i]);
			lhead[i] = edge[lhead[i]].pre;
		}
		else if(s[0]=='r' && s[1]=='e')
		{
			int j = dhead[i];
			int x = edge[j].val;
			add(x,lhead[i]);
			dhead[i] = edge[j].pre;
		}
		else if(s[0]=='c' && s[1]=='l')
		{
			num++;
			lhead[num] = lhead[i];
			dhead[num] = dhead[i];
		}
		else
		{
			if(!lhead[i])
				printf("basic\n");
			else
				printf("%d\n",edge[lhead[i]].val);
		}
	}
	return 0;
}
