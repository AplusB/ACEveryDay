//POJ 1050


#include<cstdio>
#include<queue>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
#define PI 3.1415926535898
#define INF 0X3f3f3f3f

#define N 110

int main()
{
    int n;
    scanf("%d",&n);
    int dp[N][N];
    int b[N][N];

    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            scanf("%d",&dp[i][j]);
        }
    }
    int Tmax=-INF;
    for(int k=1; k<=n; k++)
    {

        for(int i=k; i<=n; i++)
        {
            for(int j=1;j<=n;j++)
            {
                b[i][j]=dp[i][j];
                if(i>k)
                    b[i][j]+=b[i-1][j];
            }
            int temp=0;
            int mx=-INF;
            for(int j=1; j<=n; j++)
            {
                if(temp>0)
                    temp+=b[i][j];
                else
                    temp=b[i][j];
                if(mx<temp)
                    mx=temp;
            }
            Tmax=max(mx,Tmax);
        }
    }
    printf("%d\n",Tmax);
}
/*
4
0 -2 -7 0
 9 2 -6 2
-4 1 -4 1
-1 8 0 -2
*/
