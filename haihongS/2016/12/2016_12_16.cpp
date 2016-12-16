#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e3+60;
const double inf=1e9;
const double eps=1e-12;


int a[maxn],n,m,ok[30],ans[maxn],bi,cnt;
queue<int> aha[30];

void deal(int all);
void update();
void getHour(int v);
void getMin(int v);

int main()
{
	int k,q;
	while(~scanf("%d%d%d%d",&n,&m,&k,&q))
	{
		for(int i=0;i<30;i++)
		{
			if(!aha[i].empty()) aha[i].pop();
			ok[i]=0;
		}
		memset(ans,-1,sizeof(ans));
		bi=0;
		cnt=0;
		for(int i=1;i<=k;i++)
		{
			scanf("%d",&a[i]);
		}
		deal(k);
		for(int i=1;i<=n;i++)
		{
			while(!aha[i].empty() && ok[i]<540)
			{
				int tp=aha[i].front();
				aha[i].pop();
				ans[tp]=ok[i]+a[tp];
				ok[i]=ans[tp];
			}
		}
		while(q--)
		{
			int v;
			scanf("%d",&v);
			v=ans[v];
			if(v==-1)
			{
				printf("Sorry\n");continue;
			}
			getHour(v);
			printf(":");
			getMin(v);
			printf("\n");
		}
	}
	return 0;
}

void getMin(int v)
{
	v=v%60;
	if(v<10) printf("0");
	printf("%d",v);
}

void getHour(int v)
{
	v=v/60;
	v+=8;
	if(v<10) printf("0");
	printf("%d",v);
}

void deal(int all)
{
	int fir=1,win=1;
	while(fir<=all && fir<=n*m)
	{
		aha[win].push(fir);
		fir++;
		win++;
		cnt++;
		if(win>n) win=1;
	}
	if(fir>all) return ;
	while(fir<=all)
	{
		if(cnt==n*m) update();
		if(bi==1) return ;
		int pos=-1;
		for(int j=1;j<=n;j++)
		{
			if(aha[j].size()<m)
			{
				if(pos==-1) pos=j;
				else
				{
					if(aha[j].size()<aha[pos].size())
						pos=j;
				}
			}
		}
		if(pos!=-1)
		{
			aha[pos].push(fir);
			fir++;
			cnt++;
		}
	}
}

void update()
{
	int pos=1;
	for(int i=2;i<=n;i++)
	{
		int t1=ok[pos];
		t1+=a[aha[pos].front()];
		int t2=ok[i];
		t2+=a[aha[i].front()];
		if(t2<t1)
			pos=i;
	}
	int id=aha[pos].front();
	aha[pos].pop();
	ans[id]=ok[pos]+a[id];
	ok[pos]=ans[id];
	if(ok[pos]>=540) bi=1;
	cnt--;
}




