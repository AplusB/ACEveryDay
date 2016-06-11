#include <bits/stdc++.h>
#define endl '\n'
#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)

using namespace std;

int num[20],val[5],is_prime[105];

void prime()
{
	memset(is_prime,0,sizeof(is_prime));
	
	is_prime[0] = is_prime[1] = 1;
	int i;
	for(i = 2;i <= 100;i++)
	{
		if(is_prime[i])continue;
		int j;
		for(j = i + i;j <= 100;j += i)is_prime[j] = 1;
	}
	
	int cur = 0;
	for(i = 1;i <= 100;i++)
	{
		if(is_prime[i])continue;
		num[cur++]  = i;
		//cout << num[cur - 1] << endl;
	}
} 

int main()
{
	val[0] = 4;
	val[1] = 9;
	val[2] = 25;
	val[3] = 49;
	
	char str[15];
	int i,cur = 0;
	for(i = 0;i < 4;i++)
	{
		printf("%d\n",val[i]);
		fflush(stdout);
		scanf("%s",str);
		
		if(strcmp(str,"yes") == 0)
		{
			cur = 1;
			break;
		}
	}
	
	prime();
	for(i = 0;i < 16;i++)
	{
		printf("%d\n",num[i]);
		fflush(stdout);
		scanf("%s",str);
		if(strcmp(str,"yes") == 0)
		{
			cur++;
		}
	}
	
	if(cur < 2)
	{
		printf("prime\n");
	}
	else
	{
		printf("composite\n");
	}
	fflush(stdout);
	return 0;
}
