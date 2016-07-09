//hdoj 1024
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
#define INF 0x3f3f3f3f
#define PI acos(-1.0)

const int N=1e6+7;

int a[N];
int pre[N];
int now[N];

int Max_duan(int m,int n)
{
    int i,j,max_sum;
    memset(pre,0,sizeof(pre));
    memset(now,0,sizeof(now));
    now[1]=a[1];
    for(i=1;i<=m;i++){
        max_sum=INT_MIN;
        for(j=i;j<=n;j++){
            now[j]=max(pre[j-1],now[j-1])+a[j];
            pre[j-1]=max_sum;
            if(max_sum<now[j])
                max_sum=now[j];
        }
        pre[j-1]=max_sum;
    }
    return max_sum;
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&m,&n))
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        printf("%d\n",Max_duan(m,n));
    }
    return 0;
}
