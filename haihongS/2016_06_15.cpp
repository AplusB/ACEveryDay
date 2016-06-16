#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=50+9;
const ll inf=1e8+2;

int Extgcd(int a,int b,int & x,int & y);

int main()
{
    int n,p,q;
    while(~scanf("%d%d%d",&n,&p,&q))
    {
        char aha[200];
        scanf("%s",aha);
        int x,y;
        int gg=Extgcd(p,q,x,y);
        if(n%gg!=0)
        {
            printf("-1\n");continue;
        }
        x*=n/gg,y*=n/gg;
        int tmp=q/gg;
        x=(x%tmp+tmp)%tmp;
        y=n-p*x;y/=q;
        if(y<0)
        {
            printf("-1\n");continue;
        }
        int loca=0;
        printf("%d\n",x+y);
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<p;j++)
                printf("%c",aha[loca++]);
            printf("\n");
        }
        for(int i=0;i<y;i++)
        {
            for(int j=0;j<q;j++) printf("%c",aha[loca++]);
            printf("\n");
        }

    }
    return 0;
}

int Extgcd(int a,int b,int & x,int & y)
{
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    else
    {
        int ans=Extgcd(b,a%b,x,y);
        int t=x;
        x=y;
        y=t-(a/b)*y;
        return ans;
    }
}
