#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

#define maxn 400005

char str[maxn];
int len;
int next[maxn];
int ans[maxn];

void get_next()
{
	int i=0;
	int j=-1;
	next[0]=-1;
	while(i<len)
	{
		if(j==-1||str[i]==str[j])
		{
			i++;
			j++;
			next[i]=j;
		}
		else
		{
			j=next[j];
		}
	}
}

int main()
{
	while(scanf("%s",str)!=EOF)
	{
		len=strlen(str);
		get_next();

		ans[0]=len;

		int i=0;
		int x=len;

		while(next[x]>0)
		{
			ans[++i]=next[x];
			x=next[x];
		}

		for(x=i;x>=0;x--)
		{
			cout<<ans[x]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
