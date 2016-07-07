//hdoj 1718

#include<cstdio>
#include<string.h>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

int a[1010],b[1010];
int main()
{
	int n,i,j,cnt,ans,sign;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			if(a[i]==n)
			   sign=i;
			if(!a[i]||!b[i])
			   break;
		}
		ans=1;
		for(j=0;j<i;j++)
		{
			if(b[j]>b[sign])
			   ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}

