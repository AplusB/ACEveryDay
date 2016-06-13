#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int MAX = 17;
int dp[1<<MAX];
int a[MAX][MAX];
int comput(int j,int n)
{
    int time = 0;
    for(int i = 0;i<n;i++)
    {
        if((1<<i)&j)
            time++;
    }
    return time;
}
int main()
{
    int T;
    cin >> T;
    for(int Case = 1;Case <= T;Case++)
    {
        int n;
        cin >> n;
        for(int i = 1 ;i <= n;i++)
            for(int j = 1;j <= n;j++)
            scanf("%d",&a[i][j]);
        memset(dp,0,sizeof(dp));
        int m = (1<<n)-1;
        //cout << m<<endl;
        for(int i = 0;i<n;i++)
        {
            dp[1<<i] = a[1][i+1];
        }
        for(int i = 1;i<=n-1;i++)
        {
            for(int j = 1;j<=m;j++)
            {

                if(comput(j,n) == i)
                {
                    for(int k = 0;k<n;k++)
                    {
                        int temp = 1<<k;
                        if((temp | j) != j)
                        {
                            int temp2 = temp | j;
                            dp[temp2] = max(dp[temp2],dp[j] + a[i+1][k+1]);
                        }
                    }
                }
            }
        }
        printf("Case %d: %d\n",Case,dp[m]);
    }
    return 0;
}
