#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;

struct II
{
	int id,v;
};

ll num[maxn];
ll lt[maxn],rt[maxn];
stack<II> aha;

int main()
{
	int n;
	while(scanf("%d",&n) && n)
	{
		while(!aha.empty())
			aha.pop();
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&num[i]);
		}
		for(int i=0;i<n;i++)
		{
			if(aha.empty()) lt[i]=0;
			else
			{
				while(!aha.empty())
				{
					II tp=aha.top();
					if(tp.v>=num[i]) aha.pop();
					else
					{
						lt[i]=tp.id+1;break;
					}
				}
				if(aha.empty())
					lt[i]=0;
			}
			II tmp;
			tmp.id=i,tmp.v=num[i];
			aha.push(tmp);
		}
		while(!aha.empty()) aha.pop();
		for(int i=n-1;i>=0;i--)
		{
			if(aha.empty()) rt[i]=n;
			else
			{
				while(!aha.empty())
				{
					II tp=aha.top();
					if(tp.v>=num[i]) aha.pop();
					else
					{
						rt[i]=tp.id;break;
					}
				}
				if(aha.empty()) rt[i]=n;
			}
			II tmp;
			tmp.id=i,tmp.v=num[i];
			aha.push(tmp);
		}
		/*
		for(int i=0;i<n;i++)
			printf("**%d %lld %lld\n",i,lt[i],rt[i]);
		*/
		ll ans=0;
		for(int i=0;i<n;i++)
		{
			ll tmp=(rt[i]-lt[i])*num[i];
			ans=max(ans,tmp);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
