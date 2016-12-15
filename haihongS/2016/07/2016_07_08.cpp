#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;
typedef long long ll;
const int maxn=2e5+9;

int prime[150];
int cnt;
int pre();

int main()
{
	cnt=0;
	pre();
	int flag=1;
	for(int i=0;i<15;i++)
	{
		printf("%d\n",prime[i]);
		fflush(stdout);
		string tmp;
		cin>>tmp;
		if(tmp=="yes")
		{
			if(flag==1)
				flag=prime[i];
			else
			{
				flag=-1;
				break;
			}
		}
	}
	if(flag==-1)
		printf("composite\n");
	else if(flag==1)
		printf("prime\n");
	else
	{
		int tmp=flag;
		for(int i=0;i<5;i++)
		{
			tmp*=flag;
			if(tmp>100)
				break;
			printf("%d\n",tmp);
			fflush(stdout);
			string jj;
			cin>>jj;
			if(jj=="yes")
			{
				flag=-1;
				break;
			}
		}
		if(flag==-1)
			printf("composite\n");
		else
			printf("prime\n");
	}

	return 0;
}

int pre()
{
	for(int i=2;i<150;i++)
	{
		int flag=1;
		for(int j=2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
			prime[cnt++]=i;
	}
	return 0;
}
