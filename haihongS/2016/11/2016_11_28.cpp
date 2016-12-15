#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;
typedef long long ll;
const int maxn=5e5+9;

struct II
{
    int id;
    ll x,y;
}num[maxn],m[10];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        ll x0,y0;
        scanf("%lld%lld",&x0,&y0);
        ll qqq=x0;x0=y0;y0=qqq;
        y0*=-1LL;
        for(int i=0;i<n;i++)
        {
            char op[10];
            scanf("%s",op);
            scanf("%lld%lld",&num[i].x,&num[i].y);
            ll tmp=num[i].x;num[i].x=num[i].y;num[i].y=tmp;
            num[i].y*=-1LL;
            if(op[0]=='B') num[i].id=0;
            else if(op[0]=='R') num[i].id=1;
            else if(op[0]=='Q') num[i].id=2;
        }
        memset(m,-1,sizeof(m));
        for(int i=0;i<n;i++)
        {
            if(num[i].y==y0)
            {
                if(num[i].x<x0)
                {
                    if(m[0].id==-1 || num[i].x>m[0].x)
                    {
                        m[0].id=num[i].id;
                        m[0].x=num[i].x,m[0].y=num[i].y;
                    }
                }
                else if(num[i].x>x0)
                {
                    if(m[4].id==-1 || num[i].x<m[4].x)
                    {
                        m[4].id=num[i].id;
                        m[4].x=num[i].x,m[4].y=num[i].y;
                    }
                }
            }
            else if(num[i].x==x0)
            {
                if(num[i].y<y0)
                {
                    if(m[6].id==-1 || num[i].y>m[6].y)
                    {
                        m[6].id=num[i].id;
                        m[6].x=num[i].x,m[6].y=num[i].y;
                    }
                }
                else if(num[i].y>y0)
                {
                    if(m[2].id==-1 || num[i].y<m[2].y)
                    {
                        m[2].id=num[i].id;
                        m[2].x=num[i].x,m[2].y=num[i].y;
                    }
                }
            }
            else if(x0+y0==num[i].x+num[i].y)
            {
                if(num[i].x<x0)
                {
                    if(m[1].id==-1 || num[i].x>m[1].x)
                    {
                        m[1].id=num[i].id;
                        m[1].x=num[i].x,m[1].y=num[i].y;
                    }
                }
                else
                {
                    if(m[5].id==-1 || num[i].x<m[5].x)
                    {
                        m[5].id=num[i].id;
                        m[5].x=num[i].x,m[5].y=num[i].y;
                    }
                }
            }
            else if(y0-x0==num[i].y-num[i].x)
            {
                if(num[i].x<x0)
                {
                    if(m[7].id==-1 || num[i].x>m[7].x)
                    {
                        m[7].id=num[i].id;
                        m[7].x=num[i].x,m[7].y=num[i].y;
                    }
                }
                else
                {
                    if(m[3].id==-1 || num[i].x<m[3].x)
                    {
                        m[3].id=num[i].id;
                        m[3].x=num[i].x,m[3].y=num[i].y;
                    }
                }
            }
        }
        int flag=0;
        for(int i=0;i<8;i++)
        {
            if(m[i].id==-1) continue;
            if(m[i].y==y0)
            {
                if(m[i].id==1 || m[i].id==2)
                {
                    flag=1;break;
                }
            }
            else if(m[i].x==x0)
            {
                if(m[i].id==1 || m[i].id==2)
                {
                    flag=1;break;
                }
            }
            else
            {
                if(m[i].id==2 || m[i].id==0)
                {
                    flag=1;break;
                }
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

