//lightoj 1079 - Just another Robbery
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define N 100010
#define mod 1000000007
int v[110];
double p[110],dp[10010];
int main()
{
    int n,t,cas=1;
    double P;
    cin>>t;
    while(t--){
        cin>>P>>n;
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>v[i]>>p[i];
            sum+=v[i];
        }
        memset(dp,0,sizeof dp);
        dp[0]=1.0;
        for(int i=0;i<n;i++)
            for(int j=sum;j>=v[i];j--)
                dp[j]=max(dp[j],dp[j-v[i]]*(1-p[i]));
        for(int i=sum;i>=0;i--)
            if(P>=1-dp[i]){
                printf("Case %d: %d\n",cas++,i);
                break;
            }
    }
    return 0;
}
//lightoj 1095 - Arrange the Numbers
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define N 100010
#define mod 1000000007
LL c[1010][1010],jc[1010];
void init(){
    c[0][0]=1;
    jc[0]=1;
    for(int i=1;i<=1000;i++){
        c[i][0]=c[i][i]=1;
        jc[i]=jc[i-1]*i%mod;
        for(int j=1;j<i;j++){
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    }
}
int main()
{
    init();
    int n,t,cas=1,m,k;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        LL ans=0;
        for(int i=0;i<=m-k;i++){
            if(i&1) ans=((ans-c[m-k][i]*jc[n-k-i]%mod)%mod+mod)%mod;
            else ans=(ans+c[m-k][i]*jc[n-k-i]%mod)%mod;
        }
        ans=(ans*c[m][k])%mod;
        printf("Case %d: %lld\n",cas++,ans);
    }
    return 0;
}
