#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long LL;
 
const LL maxn = 105;
LL a[maxn][maxn], dp[maxn*2][maxn][maxn];
LL t,n,m,bu,ans;
 
int main()
{
    LL i,j,k,l1,l2;
    cin>>t;
    while(t--){
        ans=0;
        memset(dp,0,sizeof(dp));
        cin>>n>>m;LL step=n+m-2;
 
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                cin>>a[i][j];
                ans+=a[i][j];
            }
        }
        if(n==1||m==1){
            cout<<ans<<endl;
            continue;
        }
 
        dp[0][1][1]=a[1][1];
        for(i=1;i<=step;i++){
            for(LL x1=1;x1<=n;x1++){
                for(LL x2=1;x2<=n;x2++){
                    LL y1,y2;
                    y1=i+2-x1;
                    y2=i+2-x2;
                    LL w;
                    if(x1==x2)w=a[x1][y1];
                    else w=a[x1][y1]+a[x2][y2];
 
                    dp[i][x1][x2]=max(max(dp[i-1][x1][x2],dp[i-1][x1][x2-1]),
                                      max(dp[i-1][x1-1][x2],dp[i-1][x1-1][x2-1]))+w;
 
                }
            }
        }
        cout<<dp[step][n][n]<<endl;
    }
    return 0;
}
 
/*
1 1 1 1 1 1
 
 
*/
 
/**************************************************************
    Problem: 1875
    User: ccut001
    Language: C++
    Result: Accepted
    Time:156 ms
    Memory:19500 kb
****************************************************************/
