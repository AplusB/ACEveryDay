#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int id[305];
bool jug[1000005];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&id[i]);

		int find=0;

		int i;
		for(i=n;;i++)
		{
			find=1;
			memset(jug,0,sizeof(bool)*i);
			for(int j=1;j<=n;j++)
			{
				if(jug[id[j]%i]==true)
				{
					find=0;
					break;
				}
				jug[id[j]%i]=1;
			}
			if(find==1)
				break;
		}
		printf("%d\n",i);
	}
	return 0;
}
