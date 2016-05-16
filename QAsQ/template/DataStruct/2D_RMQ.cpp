/*
* 二维RMQ，预处理复杂度 n*m*log*(n)*log(m)
* 数组下标从 1 开始
*/

const int maxn=112345;
const int max_log=20;
int val[maxn][maxn];
int dp[maxn][maxn][max_log][max_log];//最大值
int mm[maxn]; //二进制位数减一
void initRMQ(int n,int m)
{
    mm[0] = -1;
    for(int i = 1; i <= 305; i++)
        mm[i] = ((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[i][j][0][0] = val[i][j];
    for(int ii = 0; ii <= mm[n]; ii++)
        for(int jj = 0; jj <= mm[m]; jj++)
            if(ii+jj)
                for(int i = 1; i + (1<<ii) - 1 <= n; i++)
                for(int j = 1; j + (1<<jj) - 1 <= m; j++)
                {
                    if(ii)

dp[i][j][ii][jj]
= max(dp[i][j][ii-1][jj]
,dp[i+(1<<(ii-1))][j][ii-1][jj]);

                        else

dp[i][j][ii][jj]
= max(dp[i][j][ii][jj-1]
,dp[i][j+(1<<(jj-1))][ii][jj-1]);

                }
}
//查询矩形内的最大值(x1<=x2,y1<=y2)
int rmq(int x1,int y1,int x2,int y2)
{
    int k1 = mm[x2-x1+1];
    int k2 = mm[y2-y1+1];
    x2 = x2 - (1<<k1) + 1;
    y2 = y2 - (1<<k2) + 1;
    return max(max(dp[x1][y1][k1][k2],
                dp[x1][y2][k1][k2])
               ,max(dp[x2][y1][k1][k2]
                ,dp[x2][y2][k1][k2]));
}
