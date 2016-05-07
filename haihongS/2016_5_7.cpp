/* ***********************************************
Author        :shootPlane
Created Time  :2016年05月07日 星期六 14时02分20秒
File Name     :1201.cpp
Blog          :http://haihongblog.com
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn=1e5+9;
const int inf=1e9+9;

struct II
{
	int a,b,c;
}num[maxn];

int sum[maxn];

int lowbit(int x);
int getsum(int x);
int update(int x,int v);

int cmp(const II &x,const II &y);


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&num[i].a,&num[i].b,&num[i].c);
			num[i].a+=2,num[i].b+=2;
		}
		sort(num,num+n,cmp);
		memset(sum,0,sizeof(sum));
		int ans=0;
		for(int i=0;i<n;i++)
		{
			int tmp=getsum(num[i].b)-getsum(num[i].a-1);
			tmp=num[i].c-tmp;
			for(int j=num[i].b;tmp>0;j--)
			{
				int t1=getsum(j)-getsum(j-1);
				if(t1==1)
					continue;
				tmp--;
				update(j,1);
				ans++;
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}

int update(int x,int v)
{
	while(x<maxn)
	{
		sum[x]+=v;
		x+=lowbit(x);
	}
	return 0;
}

int getsum(int x)
{
	int tmp=0;
	while(x>0)
	{
		tmp+=sum[x];
		x-=lowbit(x);
	}
	return tmp;
}

int lowbit(int x)
{
	return x&(-x);
}

int cmp(const II &x,const II &y)
{
	if(x.b==y.b) return x.a<y.b;
	return x.b<y.b;
}
