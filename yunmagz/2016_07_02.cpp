//lightoj1105 - Fi Binary Number
#include<bits/stdc++.h>
using namespace std;
int f[100010];
int main(){
    f[0]=1;
    f[1]=2;
    for(int i=2;i<=44;i++)
        f[i]=f[i-1]+f[i-2];
    int t,cas=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        printf("Case %d: ",cas++);
        int j=44;
        while(f[j]>n) j--;
        while(j>=0){
            if(n>=f[j]){
                n-=f[j];
                cout<<"1";
            }
            else cout<<"0";
            j--;
        }
        puts("");
    }
    return 0;
}
//lightoj1134 - Be Efficient
#include<bits/stdc++.h>
using namespace std;
#define LL long long
int dp[100010];
int main(){
    int t,cas=1,x;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        memset(dp,0,sizeof dp);
        int sum=0;
        LL ans=0;
        dp[0]=1;
        for(int i=0;i<n;i++){
            cin>>x;
            sum+=x;
            sum%=m;
            ans+=dp[sum];
            dp[sum]++;
        }
        printf("Case %d: %lld\n",cas++,ans);
    }
    return 0;
}
//lightoj1170 - Counting Perfect BST
#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int mod=1e8+7;
const double eps=1e-9;
LL dp[100010];
int cnt=0,m[100010],p[100010];
int main(){
    memset(m,0,sizeof m);
    for(LL i=2;i<=100000;i++){
        if(!m[i]){
            p[cnt++]=i;
            for(LL j=i*i;j<=100000;j*=i) m[j]=1;
        }
    }
    dp[0]=1;
    for(int i=1; i<5000; i++)
        for(int j=0; j<i; j++)
            dp[i]=(dp[i]+dp[j]*dp[i-1-j])%mod;
    dp[0]=0;
    int t,cas=1,x;
    cin>>t;
    while(t--){
        LL a,b;
        cin>>a>>b;
        LL ans=0,x,y;
        for(int i=2;i<34;i++){
            x=(int)floor(pow(a-1,1.0/i)+eps);
            y=(int)floor(pow(b,1.0/i)+eps);
            ans+=(upper_bound(p,p+cnt,y)-p)-(upper_bound(p,p+cnt,x)-p);
        }
        printf("Case %d: %lld\n",cas++,dp[ans]);
    }
    return 0;
}
