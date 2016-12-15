#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=2e6+9;
const int inf=2e9+9;

int isprime[maxn];
int use[1000],own[maxn];

int pre();

int main()
{
	pre();
	int n,k;
	while(~scanf("%d%d",&n,&k))
	{
		map<int,int> aha;
		aha.clear();
		memset(use,0,sizeof(use));
		memset(own,0,sizeof(own));
		int cnt=0;

		int num=k;
		for(int i=2;i*i<=k;i++)
		{
			if(num<=1) break;
			if(isprime[i]==-1) continue;
			if(num%i!=0) continue;
			use[cnt++]=i;
			while(num%i==0)
			{
				num/=i;
				aha[i]+=1;
			}
		}
		if(isprime[num]==1)
		{
			use[cnt++]=num;
			aha[num]+=1;
		}
/*		
		for(int i=0;i<cnt;i++)
		{
			printf("%d %d %d\n",i,use[i],aha[use[i]]);
		}
*/
		map<int,int> act;
		act.clear();

		for(int i=0;i<n;i++)
		{
			int c;
			scanf("%d",&c);
			if(own[c]==1) continue;
			own[c]=1;
			for(int j=0;j<cnt;j++)
			{
				int tmp=0;
				while(c%use[j]==0)
				{
					c/=use[j];
					tmp+=1;
				}
				act[use[j]]=max(act[use[j]],tmp);
			}
		}
		int ans=1;
		for(int i=0;i<cnt;i++)
		{
			if(aha[use[i]]>act[use[i]])
			{
				ans=-1;
				break;
			}
		}
		if(ans==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}


int pre()
{
	memset(isprime,0,sizeof(isprime));
	isprime[1]=-1;
	for(int i=2;i<maxn;i++)
	{
		if(isprime[i]==-1)
			continue;
		int flag=1;
		for(int j=2;j*j<=i;j++)
		{
			if(i%j==0) 
			{
				flag=-1;break;
			}
		}
		if(flag==-1) continue;
		isprime[i]=1;
		for(int j=2*i;j<maxn;j+=i)
		{
			isprime[j]=-1;
		}
	}
	return 0;
}
