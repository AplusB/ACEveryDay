#include<bits/stdc++.h>
using namespace std;

const int maxn = 45;
int a[maxn],b[maxn];
#define LL long long 
const LL INFF = 0x3f3f3f3f3f3f3f3fll;

int N;
struct Martix{
    LL arr[maxn][maxn];
    void init(){
        memset(arr,0x3f,sizeof(arr));
    }
    void to(){
        this->init();
        for(int i = 0 ; i < N;i++){
            arr[i][i] = 0;
        }
    }
};

Martix operator * (const Martix & a,const Martix & b){
    Martix ret;
    ret.init();
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            for(int k = 0 ; k < N; k++){
                ret.arr[i][j] = min(ret.arr[i][j],a.arr[i][k] + b.arr[k][j]);
            }
        }
    }
    return ret;
}


LL dp[maxn][maxn][maxn];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i < n;i++) scanf("%d",&a[i]); 
    for(int i = 0;i < n;i++) scanf("%d",&b[i]);
    memset(dp,0x3f,sizeof(dp));
    N = n + 1;
    for(int i = 0 ; i < N;i++){
        dp[i][i][0] = 0;
    }
    for(int k = 1;k <= n;k++){
        for(int i = 0;i <N;i++){
            for(int j = 0 ; j < N;j++){
                if(j-1>=0)dp[i][j][k] = min(dp[i][j][k],dp[i][j-1][k-1] + a[k-1]);
                if(j+1<N) dp[i][j][k] = min(dp[i][j][k],dp[i][j+1][k-1] + b[k-1]);
            }
        }
    }
    Martix x;
    x.init();
    for(int i = 0 ; i < N;i++){
        for(int j = 0 ;j < N;j++){
            x.arr[i][j] = dp[i][j][n];
        }
    }
    Martix ret;
    ret.to();
    while(m){
        if(m & 1) ret = ret * x;
        x = x * x;
        m >>= 1;
    }
    printf("%I64d\n",ret.arr[0][0]);
    return 0;
}

