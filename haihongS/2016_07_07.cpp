#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

char num[109][1009];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
		{
			scanf("%s",num[i]);	
		}
		int cnt=0,ans=0;
		for(int i=0;i<26;i++)
		{
			for(int j=i+1;j<26;j++)
			{
				char n1='a'+i,n2='a'+j;
				cnt=0;
				for(int k=0;k<n;k++)
				{
					int flag=1;
					for(int p=0;p<strlen(num[k]);p++)
					{
						if(num[k][p]!=n1 && num[k][p]!=n2)
						{
							flag=-1;break;
						}
					}
					if(flag==1)
						cnt+=strlen(num[k]);
				}
				ans=max(ans,cnt);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
