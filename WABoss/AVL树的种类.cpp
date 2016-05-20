#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 2222
#define MAXD 16
long long d[MAXN][MAXD];
int main(){
    int n;
    scanf("%d",&n);
    d[1][1]=1; d[2][2]=2; d[3][2]=1;
    for(int i=4; i<=n; ++i){
        for(int j=1; j<MAXD; ++j){
            for(int k=0; k<i; ++k){
                d[i][j]+=(d[k][j-1]*d[i-1-k][j-1])%1000000007;
                d[i][j]%=1000000007;
                if(j>=2){
                    d[i][j]+=(d[k][j-1]*d[i-1-k][j-2])%1000000007;
                    d[i][j]%=1000000007;
                    d[i][j]+=(d[k][j-2]*d[i-1-k][j-1])%1000000007;
                    d[i][j]%=1000000007;
                }
            }
        }
    }
    long long res=0;
    for(int i=0; i<MAXD; ++i){
        res+=d[n][i];
        res%=1000000007;
    }
    printf("%lld\n",res);
    return 0;
}
