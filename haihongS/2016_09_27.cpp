#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=2e5+90;
const ll inf=2e13+9;
const double eps=1e-9;

char a[maxn];

int main()
{
	int n,t;
	while(~scanf("%d%d",&n,&t))
	{
		scanf("%s",a);
		int pp;
		for(int i=0;i<n;i++)
		{
			if(a[i]=='.')
			{
				pp=i;break;
			}
		}
		int fir=pp;
		for(int i=pp+1;i<n;i++)
		{
			if(a[i]>='5')
			{
				fir=i;break;
			}
		}
		if(fir==pp)
		{
			printf("%s\n",a);
			continue;
		}
		int flag=0;
		while(pp<fir && t>0)
		{
			int now=a[fir]-'0';
			if(flag==1)
				now++,flag=0;
			if(now<5)
			{
				a[fir]=(char)('0'+now);
				fir--;
			}
			else
			{
				flag=1;
				a[fir]='*';
				t--;
				fir--;
			}
		}
		if(flag==1)
		{
			while(flag && fir>=0)
			{
				if(a[fir]=='.')
				{
					fir--;continue;
				}
				int now=a[fir]-'0';
				now++;
				flag=now/10;
				a[fir]='0'+now%10;
				fir--;
			}
		}
		int back=pp;
		for(int i=pp+1;i<n;i++)
		{
			if(a[i]=='*')
			{
				back=i-1;break;
			}
		}
		if(a[back]=='.') back--;
		if(flag==1) printf("1");
		for(int i=0;i<=back;i++)
			printf("%c",a[i]);
		printf("\n");
	}
	return 0;
}
