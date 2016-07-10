//poj 1661
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
const int N=1e4+10;

int dp[N*4][4];

struct asd{
    int x1,x2;
    int h;
};
asd q[1010];
int n,tp;
bool cmp(asd z,asd x)
{
    if(z.h<x.h)
        return 1;
    return 0;
}

void left_t(int i)
{
    int k=i-1;
    while(k>0&&(q[i].h-q[k].h)<=tp){
        if(q[i].x1>=q[k].x1&&q[i].x1<=q[k].x2){
            dp[i][0]=(q[i].h-q[k].h)+min(q[i].x1-q[k].x1+dp[k][0],q[k].x2-q[i].x1+dp[k][1]);
        return;
        }
        else
            --k;
    }
    if((q[i].h-q[k].h)>tp)
        dp[i][0]=INF;
    else
        dp[i][0]=q[i].h;
}
void right_t(int i)
{
    int k=i-1;
    while(k>0&&(q[i].h-q[k].h)<=tp){
        if(q[i].x2<=q[k].x2&&q[i].x2>=q[k].x1){
            dp[i][1]=(q[i].h-q[k].h)+min(q[i].x2-q[k].x1+dp[k][0],q[k].x2-q[i].x2+dp[k][1]);
            return;
        }
        else
            --k;
    }
    if((q[i].h-q[k].h)>tp)
        dp[i][1]=INF;
    else
        dp[i][1]=q[i].h;
}

int smallest()
{
    int i,j;
    for(int i=1;i<=n+1;i++){
        left_t(i);
        right_t(i);
    }
    return min(dp[n+1][0],dp[n+1][1]);
}

int main()
{
    int T,k;
    int x0,y0,i,j;
    cin>>T;
    while(T--){
        cin>>n>>x0>>y0>>tp;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&q[i].x1,&q[i].x2,&q[i].h);
        }
        q[0].h=0;
        q[0].x1=-20000;
        q[0].x2=20000;
        q[n+1].h=y0;
        q[n+1].x1=x0;
        q[n+1].x2=x0;
        sort(q,q+n+2,cmp);
        printf("%d\n",smallest());
    }
    return 0;
}
