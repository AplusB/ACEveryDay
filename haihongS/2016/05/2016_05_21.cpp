#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn=2e3+9;
const int inf=1e9+9;
const double eps=1e-9;

int n,m,k;
double p1,p2,p3,p4;
double b[maxn],a[maxn];
double dp[2][maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        scanf("%lf%lf%lf%lf",&p1,&p2,&p3,&p4);
        if(fabs(p4)<eps)
        {
            printf("0.00000\n");continue;
        }
        a[0]=1,a[1]=p2/(1-p1);
        for(int i=2;i<maxn;i++)
            a[i]=a[i-1]*p2/(1-p1);
        b[0]=p4/(1-p1);
        memset(dp,0,sizeof(dp));
        double ta=p2/(1-p1),tb=p3/(1-p1),tc=p4/(1-p1);
        dp[0][1]=tc/(1-ta);
        double *last=dp[0],*now=dp[1];
        for(int i=2;i<=n;i++)
        {
            for(int j=2;j<=k;j++)
                b[j-1]=tb*last[j-1]+tc;
            for(int j=k+1;j<=i;j++)
                b[j-1]=tb*last[j-1];

            double tmp=0;
            for(int j=0;j<i;j++)
                tmp+=b[j]*a[i-1-j];
            now[i]=tmp/(1-a[i]);
            now[1]=ta*now[i]+tc;

            for(int j=2;j<i;j++)
                now[j]=ta*now[j-1]+b[j-1];
            swap(now,last);    
        }
        printf("%.5lf\n",last[m]);
    }
    return 0;
}
