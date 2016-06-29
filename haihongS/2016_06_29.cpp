#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int maxn=2e5+9;
typedef long long ll;

char num[maxn];
int go[maxn];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		scanf("%s",num);
		for(int i=0;i<n;i++)
			scanf("%d",&go[i]);
		int now=0;
		int cnt=0,flag=0;
		while(0<=now && now<n)
		{
			cnt++;
			if(cnt>maxn) break;
			if(num[now]=='<')
				now-=go[now];
			else if(num[now]=='>')
				now+=go[now];
		}
		if(now<0 || now>=n) 
			flag=1;
		if(flag==1)
			printf("FINITE\n");
		else
			printf("INFINITE\n");
	}
	return 0;
}

