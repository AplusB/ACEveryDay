#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int maxn=2e5+9;
typedef long long ll;

char num[maxn];
int flag[maxn];
char out[maxn];

int main()
{
	int n,k;
	while(~scanf("%d%d",&n,&k))
	{
		scanf("%s",num);
		int sum=0;
		for(int i=0;i<n;i++)
		{
			flag[i]=0;
			flag[i]=max(num[i]-'a','z'-num[i]);
			sum+=flag[i];
		}
		if(sum<k)
		{
			printf("-1\n");continue;
		}
		memset(out,0,sizeof(out));
		sum=k;
		for(int i=0;i<n;i++)
		{
			if(num[i]-'a'==flag[i])
			{
				if(sum==0)
				{
					out[i]=num[i];continue;
				}
				if(sum<flag[i])
				{
					out[i]=(char)(num[i]-'a'-sum+'a');
					sum=0;
				}
				else
				{
					sum-=flag[i];
					out[i]='a';
				}
			}
			else if('z'-num[i]==flag[i])
			{
				if(sum==0)
				{
					out[i]=num[i];continue;
				}
				if(sum<flag[i])
				{
					out[i]=(char)(num[i]-'a'+sum+'a');
					sum=0;
				}
				else
				{
					sum-=flag[i];
					out[i]='z';
				}
			}
		}
		printf("%s\n",out);

	}
	return 0;
}

