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
const int maxn=1e5+200;
const double eps=1e-9;
const ll inf=1e12;

int a[maxn],go[maxn],ans[maxn],last[maxn*10];

struct II
{
	int l,r,id;
}qq[maxn];

struct XX
{
	int v,loca;
};

vector<XX> aha[maxn];

int update(int pos,int v); 
int query(int pos);
int lowbit(int x);
int cmp(II x,II y);
int gcd(int x,int y);

int main()
{
	int n,q;
	while(~scanf("%d%d",&n,&q))
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=q;i++)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			qq[i].l=l,qq[i].r=r,qq[i].id=i;
		}
		for(int i=0;i<maxn;i++)
			aha[i].clear();

		sort(qq+1,qq+1+q,cmp);

		for(int i=1;i<=n;i++)
		{
			XX now;
			now.v=a[i],now.loca=i;
			aha[i].push_back(now);
			int len=aha[i-1].size();
			for(int j=0;j<len;j++)
			{
				XX nx=aha[i-1][j];
				int tmp=gcd(nx.v,a[i]);
				if(tmp!=now.v)
				{
					now.v=tmp,now.loca=nx.loca;
					aha[i].push_back(now);
				}
			}
		}
		memset(go,0,sizeof(go));
		memset(last,0,sizeof(last));
		int pos=1;
		for(int i=1;i<=q;i++)
		{
			while(pos<=qq[i].r)
			{
				int len=aha[pos].size();
				for(int j=0;j<len;j++)
				{
					XX nx=aha[pos][j];
					if(last[nx.v]==0)
					{
						update(nx.loca,1);
						last[nx.v]=nx.loca;
					}
					else if(last[nx.v]<=nx.loca)
					{
						update(last[nx.v],-1);
						last[nx.v]=nx.loca;
						update(nx.loca,1);
					}
				}
				pos++;
			}
			ans[qq[i].id]=query(qq[i].r)-query(qq[i].l-1);
		}
		for(int i=1;i<=q;i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}


int gcd(int x,int y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}

int cmp(II x,II y)
{
	if(x.r==y.r) return x.l<y.l;
	return x.r<y.r;
}

int query(int pos)
{
	int ans=0;
	while(pos>0)
	{
		ans+=go[pos];
		pos-=lowbit(pos);
	}
	return ans;
}

int update(int pos,int v)
{
	while(pos<maxn)
	{
		go[pos]+=v;
		pos+=lowbit(pos);
	}
	return 0;
}

int lowbit(int x)
{
	return x&(-x);
}
