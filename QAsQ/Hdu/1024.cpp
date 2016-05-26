#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long
const LL INFF = 0x3f3f3f3f3f3f3f3fll;

const int maxn = 1123456;

LL dp[maxn],arr[maxn];
LL ma[maxn];

int main(){
    int n,m;
    while(~scanf("%d %d",&m,&n)){
        for(int i=1;i<=n;i++){
            scanf("%I64d",&arr[i]);
        }
        for(int i=0;i<=m;i++){
            dp[i] = ma[i] = -INFF;
        }
        ma[0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                dp[j] = max(ma[j-1],dp[j])+arr[i];
                ma[j] = max(dp[j],ma[j]);
            }
        }
        printf("%I64d\n",ma[m]);
    }
    return 0;
}
