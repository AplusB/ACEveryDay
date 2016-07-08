//居然1A...

#include<iostream>
#include<cstdio>
#include<math.h>
#include<queue>
#include<map>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
#define PI acos(-1.0)

const int N=1e3+10;
//如果a能够被b整除，那么a/b应输出为整数格式，否则a/b输出为带两位小数的格式。

int a[N];

char s[N];
char shi[N];
char xu[N];

struct asd{
	int id;
	int yy;
	int mm;
	int dd;
	int hh;
	int ff;
	int ss;
	int d;
	int s;
};
asd q[N];

bool cmp(asd z,asd x)
{
	if(z.d<x.d)
		return 1;
	else if(z.d==x.d)
	{
		if(z.s<x.s)
			return 1;
	}
	return 0;
}
int main()
{
	int yy,mm,dd;
	int hh,ff,ss;
	int n;
	int num=0;
	while(scanf("%d",&n))
	{
		if(!n)
			break;
		scanf("%d/%d/%d %d:%d:%d",&yy,&mm,&dd,&hh,&ff,&ss);
		q[num].id=n;
		q[num].yy=yy;
		q[num].mm=mm;
		q[num].dd=dd;
		q[num].hh=hh;
		q[num].ff=ff;
		q[num].ss=ss;
		q[num].s=ss+ff*60+hh*3600;
		q[num].d=yy*365+mm*30+dd;
		num++;
	}
	sort(q,q+num,cmp);
	printf("The urgent schedule is No.%d: %d/%d/%d %d:%d:%d",q[0].id,q[0].yy,q[0].mm,q[0].dd,q[0].hh,q[0].ff,q[0].ss);

}
