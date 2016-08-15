//hdu5839 Special Tetrahedron
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <functional>
#define RI(N) scanf("%d",&(N))
#define RII(N,M) scanf("%d %d",&(N),&(M))
#define RIII(N,M,K) scanf("%d %d %d",&(N),&(M),&(K))
#define mem(a) memset((a),0,sizeof(a))
using namespace std;
const int inf=1e9;
const int inf1=-1*1e9;
double EPS=1e-10;
typedef long long LL;
struct P
{
    LL x;
    LL y;
    LL z;
    P operator -(P p)
    {
        P p1;
        p1.x=x-p.x;
        p1.y=y-p.y;
        p1.z=z-p.z;
        return p1;
    }

};

bool judge1(LL x1,LL y1,LL z1,LL x2,LL y2,LL z2,LL x3,LL y3,LL z3)
{
    LL t=x1*y2*z3+y1*z2*x3+z1*x2*y3;
    LL t2=z1*x3*y2+x2*y1*z3+x1*z2*y3;
    if(t-t2==0) return false;
    return true;
}
bool judge(P p1,P p2)
{
    if((p1.x*p2.y==p1.y*p2.x)&&(p1.x*p2.z==p1.z*p2.x)&&(p1.y*p2.z==p2.y*p1.z)) return false;
    return true;
}

LL edge(P p1,P p2)
{
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z);
}

bool judge3(P p1,P p2,P p3,P p4)
{
    LL t=edge(p1,p2);
    LL t1=edge(p1,p3);
    LL t2=edge(p1,p4);
    LL t3=edge(p2,p3);
    LL t4=edge(p2,p4);
    LL t5=edge(p3,p4);
    if((t==t1)&&(t1==t2))
    {
        if((t3==t4&&t3==t)||(t4==t5&&t4==t)||(t3==t5&&t5==t)) return true;
    }
    else if(t==t1)
    {
        if(t5==t4&&t5==t)
            return true;
    }
    else if(t1==t2)
    {
        if(t4==t3&&t1==t4)return true;
    }
    else if(t==t2)
    {
        if(t3==t5&&t3==t)  return true;
    }
    return false;
}


int main()
{
    int T,cas=1;
    RI(T);
    while(T--)
    {
        int n,len=0;
        P p[205];
        RI(n);
        for(int i=0; i<n; i++)
            scanf("%I64d %I64d %I64d",&p[i].x,&p[i].y,&p[i].z);
        int ans=0;
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                for(int k=j+1; k<n; k++)
                {
                    P p1=p[i]-p[k];
                    P p2=p[i]-p[j];
                    LL t1=edge(p[i],p[j]);
                    LL t2=edge(p[i],p[k]);
                    LL t3=edge(p[j],p[k]);
                    bool mark=true;
                    if(t1!=t2&&t1!=t3&&t3!=t2) mark=false;
                    if(judge(p1,p2)&&mark)
                    {
                        for(int l=k+1; l<n; l++)
                        {
                            P p5=p[i]-p[l];
                            P p3=p[j]-p[l];
                            P p4=p[k]-p[l];
                            if(judge1(p3.x,p3.y,p3.z,p4.x,p4.y,p4.z,p5.x,p5.y,p5.z))
                            {
                                if(judge3(p[l],p[j],p[k],p[i]))  ans++;
                            }
                        }
                    }
                }
        printf("Case #%d: %d\n",cas++,ans);

    }



    return 0;
}
