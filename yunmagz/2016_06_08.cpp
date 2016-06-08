//lightoj 1140 - How Many Zeroes?
#include<bits/stdc++.h>  
using namespace std;  
#define ll long long  
#define mod 1000000007  
#define inf 0x3f3f3f3f  
ll dp[20][20];  
int num[20];  
ll dfs(int site,int d,int flag,int f)  
{  
    if(site==0) return !flag?(ll)1:(ll)d;  
    if(!f&&flag&&dp[site][d]!=-1) return dp[site][d];  
    int len=f?num[site]:9;  
    ll ans=0;  
    for(int i=0; i<=len; i++)  
    {  
        if(i==0)  
        {  
            if(flag)  
                ans+=dfs(site-1,d+1,flag,f&&i==len);  
            else  
                ans+=dfs(site-1,d,0,f&&i==len);  
        }  
        else  
            ans+=dfs(site-1,d,1,f&&i==len);  
    }  
    if(!f&&flag) dp[site][d]=ans;  
    return ans;  
 
}  
ll solve(ll x)  
{  
    if(x<0) return 0;  
    int i=0;  
    while(x)  
    {  
        num[++i]=x%10;  
        x/=10;  
    }  
    return dfs(i,0,0,1);  
}  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    memset(dp,-1,sizeof(dp));  
    for(int cas=1; cas<=t; cas++)  
    {  
        ll a,b;  
        scanf("%lld %lld",&a,&b);  
        printf("Case %d: %lld\n",cas,solve(b)-solve(a-1));  
    }  
    return 0;  
}
