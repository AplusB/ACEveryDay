//hdoj 5479

#include<cstdio>
#include<string.h>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

#define N 1010

char ss[N];
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		scanf("%s",ss);
		int len;
		len=strlen(ss);
		int sum=0;
		int p=0;
		
		for(int i=0;i<len;i++)
		{
			if(ss[i]=='(')
				++p;
			else
			{
				if(p)
				{
					sum++;
					--p;
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}

