#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e3+9;
const int inf=2e9+9;
double eps=1e-6;
double pi=acos(-1.0);


map<string,int> aha;
map<int,string> rev;
set<int> dj[maxn];
vector<pair<string,int> >ans;
int fa[maxn],head[maxn],sum[maxn];

void init();
void uu(int x,int y,int w);
int cmp(pair<string,int> a,pair<string,int> b);

int main()
{
	int n,k;
	while(~scanf("%d%d",&n,&k))
	{
		init();
		int tot=1;
		for(int i=0;i<n;i++)
		{
			string a,b;
			int v;
			cin>>a>>b>>v;
			if(aha[a]==0)
			{
				aha[a]=tot++;
				rev[tot-1]=a;
			}
			if(aha[b]==0)
			{
				aha[b]=tot++;
				rev[tot-1]=b;
			}
			head[aha[a]]+=v;
			head[aha[b]]+=v;
			uu(aha[a],aha[b],v);
		}
		for(int i=1;i<tot;i++)
		{
			if(dj[i].size()<=2 || sum[i]<=k) continue;
			int now=i;
			set<int>::iterator it;
			for(it=dj[i].begin();it!=dj[i].end();it++)
			{
				if(head[*it]>head[now])
					now=*it;
			}
			ans.push_back(make_pair(rev[now],dj[i].size()));
		}
		sort(ans.begin(),ans.end(),cmp);
		int len=ans.size();
		printf("%d\n",len);
		for(int i=0;i<len;i++)
		{
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
		}
	}
	return 0;
}

int cmp(pair<string,int> a,pair<string,int> b)
{
	return a.first<b.first;
}

void uu(int x,int y,int w)
{
	x=fa[x],y=fa[y];
	if(x==y)
	{
		sum[x]+=w;
		return ;
	}
	if(x>y) swap(x,y);
	int len=dj[y].size();
	set<int>::iterator it;
	for(it=dj[y].begin();it!=dj[y].end();it++)
	{
		dj[x].insert(*it);
		fa[*it]=x;
	}
	sum[x]+=sum[y]+w;
	dj[y].clear();
}

void init()
{
	aha.clear();
	rev.clear();
	ans.clear();
	for(int i=1;i<maxn;i++)
	{
		dj[i].clear();
		dj[i].insert(i);
		fa[i]=i;
		head[i]=0;
		sum[i]=0;
	}
}
