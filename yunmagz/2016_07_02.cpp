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
