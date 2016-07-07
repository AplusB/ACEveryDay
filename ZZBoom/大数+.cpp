//poj  2562

#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

char s1[20];
char s2[20];
int a[20];
int b[20];
int dp[20];

int main() 
{
	while(~scanf("%s%s",s1,s2))
	{
		if(!strcmp(s1,"0")&&!strcmp(s2,"0"))
			break;
			
		int ans,len1,len2;
		
		len1=strlen(s1);
		len2=strlen(s2);
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		
		int num1,num2;
		num1=num2=0;
		for(int i=len1-1;i>=0;i--)
			a[num1++]=s1[i]-'0';
		for(int i=len2-1;i>=0;i--)
			b[num2++]=s2[i]-'0';
			
		ans=0;
		int x=max(num1,num2);
		for(int i=0;i<max(num1,num2);i++)
		{
			dp[i]+=a[i]+b[i];
			if(dp[i]>=10)
			{
				dp[i]%=10;
				ans++;
				dp[i+1]+=1;
			}
		}
		if(dp[x]>=10)
			ans++;
		if(!ans)
			printf("No carry operation.\n");
		else if(ans==1)
			printf("1 carry operation.\n");
		else
			printf("%d carry operations.\n",ans);
	}
	return 0;
}





