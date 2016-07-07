//poj1065

#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;


struct asd{
	int ll;
	int ww;
	int flag;
};
asd q[5050];
bool cmp(asd z,asd x)
{
	if(z.ll<x.ll)
		return 1;
	else if(z.ll==x.ll)
	{
		if(z.ww<x.ww)
			return 1;
		else 
			return 0;
	} 
	return 0;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&q[i].ll,&q[i].ww);
			q[i].flag=0;
		}
		sort(q,q+n,cmp);
		int k=0;
		int ans=0;
		for(int i=0;i<n;i++)
		{
			k=i;
			if(q[i].flag)
				continue;
			for(int j=i+1;j<n;j++)
			{
				if(q[k].ll<=q[j].ll&&q[k].ww<=q[j].ww&&!q[j].flag)
				{
					k=j;
					q[j].flag=1;
				}
			}
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}


