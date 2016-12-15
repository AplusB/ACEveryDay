#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<map>
#include<queue>
#include<vector>
using namespace std;

const int maxn=2e4+10;
typedef long long ll;

int n;

struct II
{
    int x,dir,v;
}num[maxn];

int cmp(const II &a,const II&b);

int main()
{
    int t;
    scanf("%d",&t);
    int cass=1;
    while(t--)
    {
        scanf("%d",&n);
        memset(num,0,sizeof(num));

        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int x,y,z,d;
            scanf("%d%d%d%d",&x,&y,&z,&d);
            int t1=x+z,t2=y-z;
            if(t2>t1) continue;
            num[cnt].x=t2,num[cnt].dir=d,num[cnt].v=1;cnt++;
            num[cnt].x=t1+1,num[cnt].dir=d,num[cnt].v=-1;cnt++;
        }
        sort(num,num+cnt,cmp);

        printf("Case #%d:\n",cass++);

        int ans=0,tmp=0;
        int a1=0,a2=0;
        for(int i=0;i<cnt;i++)
        {
            if(num[i].dir==-1) a1+=num[i].v;
            else a2+=num[i].v;
            tmp=max(tmp,a2);
            ans=max(ans,tmp+a1);
        }


        printf("%d\n",ans);
    }
    return 0;
}

int cmp(const II &a,const II&b)
{
    if(a.x==b.x) return a.v<b.v;
    return a.x<b.x;
}
