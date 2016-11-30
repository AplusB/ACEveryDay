#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=9e4+60;
const int inf=2e9+9;

struct II
{
	int u,v,w;
}num[maxn];
int fa[maxn];

int cmp(II x,II y);
int findit(int x);
void uu(int x,int y);

int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=0;i<m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			num[i].u=u,num[i].v=v,num[i].w=w;
		}
		sort(num,num+m,cmp);

		//Kruskal
		memset(fa,-1,sizeof(fa));
		int cnt=0,ans=0;
		for(int i=0;i<m;i++)
		{
			int u=num[i].u,v=num[i].v;
			int fu=findit(u),fv=findit(v);
			if(fu==fv) continue;
			cnt++;
			ans=max(ans,num[i].w);
			uu(u,v);
		}
		printf("%d %d\n",cnt,ans);

	}
	return 0;
}

void uu(int x,int y)
{
	int fx=findit(x),fy=findit(y);
	if(fx==fy) return ;
	if(abs(fa[fx])>abs(fa[fy]))
	{
		fa[fx]+=fa[fy];
		fa[fy]=fx;
	}
	else
	{
		fa[fy]+=fa[fx];
		fa[fx]=fy;
	}
}

int findit(int x)
{
	if(fa[x]<0) return x;
	return fa[x]=findit(fa[x]);
}

int cmp(II x,II y)
{
	return x.w<y.w;
}
