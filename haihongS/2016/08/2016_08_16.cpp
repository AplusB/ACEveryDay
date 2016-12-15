#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn=30+9;
const int inf=2e9+9;

struct II
{
	II *next[3];
	int cnt,flag;
	II()
	{
		flag=cnt=0;
		next[0]=next[1]=NULL;
	}
};
II *root=new II();

int ins(int x);
int del(int x);
int query(int x);

int main()
{
	int q;
	scanf("%d",&q);
	ins(0);
	while(q--)
	{
		char op[5];
		scanf("%s",op);
		int x;
		scanf("%d",&x);
		if(op[0]=='+')
			ins(x);
		else if(op[0]=='-')
			del(x);
		else
			printf("%d\n",query(x));

	}
	return 0;
}

int query(int x)
{
	int ans=0;
	II *now=root;
	for(int i=30;i>=0;i--)
	{
		if(x&(1<<i))
		{
			if(now->next[0]==NULL)
				now=now->next[1];
			else
			{
				if(now->next[0]->flag)
					now=now->next[0],ans|=1<<i;
				else
					now=now->next[1];
			}
		}
		else
		{
			if(now->next[1]==NULL)
				now=now->next[0];
			else
			{
				if(now->next[1]->flag)
					now=now->next[1],ans|=1<<i;
				else
					now=now->next[0];
			}
		}
	}
	return ans;
}

int del(int x)
{
	II *now=root;
	for(int i=30;i>=0;i--)
	{
		if(x&(1<<i))
			now=now->next[1];
		else
			now=now->next[0];
		(now->flag)--;
	}
	(now->cnt)--;
	return 0;
}

int ins(int x)
{
	II *now;
	now=root;
	for(int i=30;i>=0;i--)
	{
		if(x&(1<<i))
		{
			if(now->next[1]==NULL)
				now->next[1]=new II();
			now=now->next[1];
		}
		else
		{
			if(now->next[0]==NULL)
				now->next[0]=new II();
			now=now->next[0];
		}
		(now->flag)+=1;
	}
	(now->cnt)+=1;
	return 0;
}
