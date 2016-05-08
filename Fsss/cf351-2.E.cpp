#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<bitset>
#include<math.h>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N=1000010;
const int MAX=151;
const int mod=100000000;
const int MOD1=100000007;
const int MOD2=100000009;
const double EPS=0.00000001;
typedef long long ll;
const ll MOD=1000000000;
const ll INF=1000000000010;
typedef double db;
typedef long double ldb;
typedef unsigned long long ull;
ll hea,top,t[N];
ldb dx[N],dy[N],dp[2][N],sum[N],sump[N],sumq[N];
int cala(ldb x,ldb y,ldb x1,ldb y1,ldb x2,ldb y2) {
    return (y2-y1)*(x1-x)>=(y1-y)*(x2-x1);
}
void add(ldb x,ldb y) {
    if (top-hea<1) { top++;dx[top]=x;dy[top]=y;return ; }
    while (top-hea>0&&cala(x,y,dx[top],dy[top],dx[top-1],dy[top-1])) top--;
    top++;dx[top]=x;dy[top]=y;
}
int main()
{
    int i,j,n,k,now,pre;
    scanf("%d%d", &n, &k);
    for (i=1;i<=n;i++) scanf("%I64d", &t[i]);
    t[0]=0ll;sum[0]=sump[0]=sumq[0]=0.0;
    for (i=1;i<=n;i++) {
        sum[i]=sum[i-1]+1.0*t[i];
        sumq[i]=sumq[i-1]+1.0/t[i];
        sump[i]=sump[i-1]+sum[i]*1.0/t[i];
    }
    now=pre=0;
    for (i=0;i<=n;i++) dp[now][i]=sump[i];
    for (i=2;i<=k;i++) {
        pre=now;now^=1;hea=1;top=0;
        for (j=i;j<=n;j++) {
            add(sum[j-1],sum[j-1]*sumq[j-1]-sump[j-1]+dp[pre][j-1]);
            while (top-hea>0&&sumq[j]*(dx[hea]-dx[hea+1])<=dy[hea]-dy[hea+1]) hea++;
            dp[now][j]=sump[j]-dx[hea]*sumq[j]+dy[hea];
        }
    }
    printf("%.15f\n", (db)dp[now][n]);
    return 0;
}
