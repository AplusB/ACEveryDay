const int max_log=20;
int A[maxn];
int d[maxn][max_log];

// 区间最小值的查询
void RMQ_init(){
    for(int i = 1; i<=n; i++) d[i][0]=A[i];
    for(int j = 1; (1<<j) <= n;j++)
        for(int i = 1;i+j-1<=n; i++)
            d[i][j] = min(d[i][j-1]
                          ,d[i + (1<<j)-1][j-1]);
}
int RMQ(int L,int R){
    int k = 0;
    whie(1<<(k+1)) k++;
    return min(d[L][k] , d[R-(1<<k)+1][k]);
}


