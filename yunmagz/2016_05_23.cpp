//lightoj 1068 - Investigation
#include<bits/stdc++.h>  
using namespace std;  
#define inf 0x7fffffff  
#define ll long long  
int num[20],k;  
int dp[20][100][100];  
int dfs(int len,int y1,int y2,int f)  
{  
    if(len==0) return y1==0&&y2==0;  
    if(!f&&dp[len][y1][y2]!=-1)  
        return dp[len][y1][y2];  
    int ans=0;  
    int l=f?num[len]:9;  
    for(int i=0;i<=l;i++)  
    {  
        int x1=(y1*10+i)%k;  
        int x2=(y2+i)%k;  
        ans+=dfs(len-1,x1,x2,f&&i==l);  
    }  
    if(!f)  
        dp[len][y1][y2]=ans;  
    return ans;  
}  
int solve(int x)  
{  
    int i=1;  
    while(x)  
    {  
        num[i++]=x%10;  
        x=x/10;  
    }  
    return dfs(i-1,0,0,1);  
}  
int main()  
{  
    int a,b;  
    int t;  
    scanf("%d",&t);  
    for(int cas=1;cas<=t;cas++)  
    {  
        scanf("%d %d %d",&a,&b,&k);  
        printf("Case %d: ",cas);  
        if(k>90)  
            printf("0\n");  
        else  
        {  
            memset(dp,-1,sizeof(dp));  
            printf("%d\n",solve(b)-solve(a-1));  
        }  
    }  
    return 0;  
}  
