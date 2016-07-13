#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int maxn = 5234;
LL arr[maxn];
LL sum[maxn];

LL dp[maxn][maxn];
LL ma[maxn];


int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    arr[0] = 0;
    for(int i=1;i<=n;i++){
        sum[i] = sum[i-1] + arr[i];
    }
    memset(dp,0,sizeof(dp));
    memset(ma,0,sizeof(ma));
    for(int i=m;i<=n;i++){
        for(int j=1;j<=k;j++){
            ma[j] = max(ma[j],dp[i-m][j]);
        }
        for(int j=1;j<=k;j++){
            dp[i][j] = sum[i]-sum[i-m] + ma[j-1];
        }
    }
    LL ret = ma[k];
    for(int i=n-m;i<=n;i++){
        ret = max(dp[i][k],ret);
    }
    cout<<ret<<endl;
    return 0;
}
