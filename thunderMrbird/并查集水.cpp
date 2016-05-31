#include<iostream>
#include <stdio.h>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#include <string.h>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
#define eps 1e-6
struct node
{
       double x,y;
}a[1005];
double dis(node x,node y)
{
        return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}
int father[1005];
vector<int> vt;
int x,n;
void init()
{
        for(int i=0;i<=n;i++)
                father[i]=i;
        vt.clear();
}
int found(int p)
{
	if(p==father[p])
		return p;
	return father[p]=found(father[p]);
}
void mix(int p,int q)
{
	int x,y;
	x=found(p);
	y=found(q);
	if(x!=y)
		father[y]=x;
}
char s[10];
int main()
{
        scanf("%d %d",&n,&x);
        init();
        for(int i=1;i<=n;i++)
        {
                scanf("%lf %lf",&a[i].x,&a[i].y);
        }
        while(scanf("%s",s)!=EOF)
        {
        int p,q;
        if(s[0]=='O')
        {
                scanf("%d",&p);
                for(int i=0;i<vt.size();i++)
                {
                        if(dis(a[p],a[vt[i]])<=x)
                        {
                                mix(p,vt[i]);
                        }
                }
                vt.push_back(p);
        }
        else if(s[0]=='S')
        {
                scanf("%d %d",&p,&q);
                if(found(p)==found(q))
                        printf("SUCCESS\n");
                else
                        printf("FAIL\n");
        }
        }
        return 0;
}
