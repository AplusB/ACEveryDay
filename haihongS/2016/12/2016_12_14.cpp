#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e3+60;
const double inf=1e9;
const double eps=1e-12;

struct II
{
	int c,m,e,id,inn;
	double ave;
}num[maxn];

struct bi
{
	int  mm,pri;
	char ff;
};

int rc[maxn],rm[maxn],re[maxn],ra[maxn];

map<int,int>aha;

int cmpBI(bi x,bi y);
int cmpc(II x,II y);
int cmpm(II x,II y);
int cmpe(II x,II y);
int cmpa(II x,II y);
int cmp(II x,II y);

int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		aha.clear();
		int pos=1;
		for(int i=1;i<=n;i++)
		{
			int id;
			scanf("%d",&id);
			aha[id]=pos++;
			int v=aha[id];
			num[v].id=id;
			scanf("%d%d%d",&num[v].c,&num[v].m,&num[v].e);
			num[v].ave=1.0*(num[v].c+num[v].m+num[v].e)/3;
			num[v].inn=i;
		}
		sort(num+1,num+1+n,cmpc);
		int last=-1;
		for(int i=1;i<=n;i++)
		{
			int v=aha[num[i].id];
			if(last!=-1 && last==num[i].c)
			{
				int go=aha[num[i-1].id];
				rc[v]=rc[go];
			}
			else
			{
				last=num[i].c;
				rc[v]=i;
			}
		}
		last=-1;
		sort(num+1,num+1+n,cmpm);
		for(int i=1;i<=n;i++)
		{
			int v=aha[num[i].id];
			if(last!=-1 && last==num[i].m)
			{
				int go=aha[num[i-1].id];
				rm[v]=rm[go];
			}
			else
			{
				last=num[i].m;
				rm[v]=i;
			}
		}
		sort(num+1,num+1+n,cmpe);
		last=-1;
		for(int i=1;i<=n;i++)
		{
			int v=aha[num[i].id];
			if(last!=-1 && last==num[i].e)
			{
				int go=aha[num[i-1].id];
				re[v]=re[go];
			}
			else
			{
				last=num[i].e;
				re[v]=i;
			}
		}
		sort(num+1,num+1+n,cmpa);
		double ok=-1;
		for(int i=1;i<=n;i++)
		{
			int v=aha[num[i].id];
			if(ok!=-1 && ok==num[i].ave)
			{
				int go=aha[num[i-1].id];
				ra[v]=ra[go];
			}
			else
			{
				ok=num[i].ave;
				ra[v]=i;
			}
		}
		sort(num+1,num+1+n,cmp);


		while(m--)
		{
			int id;
			scanf("%d",&id);
			if(aha[id]==0)
			{
				printf("N/A\n");continue;
			}

			int v=aha[id];

			bi now[10];
			for(int i=0;i<4;i++)
				now[i].pri=i;
			now[0].mm=ra[v];
			now[0].ff='A';
			now[1].mm=rc[v];
			now[1].ff='C';
			now[2].mm=rm[v];
			now[2].ff='M';
			now[3].mm=re[v];
			now[3].ff='E';
			sort(now,now+4,cmpBI);
			printf("%d %c\n",now[0].mm,now[0].ff);
		}
	}
	return 0;
}

int cmpBI(bi x,bi y)
{
	if(x.mm==y.mm)
	{
		return x.pri<y.pri;
	}
	return x.mm<y.mm;
}

int cmp(II x,II y)
{
	return x.inn<y.inn;
}

int cmpa(II x,II y)
{
	return x.ave>y.ave;
}

int cmpe(II x,II y)
{
	return x.e>y.e;
}

int cmpm(II x,II y)
{
	return x.m>y.m;
}

int cmpc(II x,II y)
{
	return x.c>y.c;
}
