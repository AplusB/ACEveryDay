#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;
typedef long long ll;

int a[50];
ll dp[50][50][50];

ll deal(ll x);
ll dfs(int pos,int last,int len,bool zero,bool limit);

int main()
{
    int t;
    scanf("%d",&t);
    int cas=1;
    memset(dp,-1,sizeof(dp));
    while(t--)
    {
        ll lt,rt;
        scanf("%lld%lld",&lt,&rt);

        printf("Case #%d: ",cas++);
        printf("%lld\n",deal(rt)-deal(lt-1));
    }
    return 0;
}

ll deal(ll x)
{
    int pos=0;
    a[0]=0;
    while(x)
    {
        a[pos++]=x%10;
        x/=10;
    }
    ll ans=dfs(pos-1,0,1,true,true);
    return ans;
}

ll dfs(int pos,int last,int len,bool zero,bool limit)
{
    if(pos==-1)
    {
        if((last+len)%2==0) return 0;
        else return 1;
    }
    if(!zero && !limit && dp[pos][last][len]!=-1)
        return dp[pos][last][len];

    int up;
    if(limit) up=a[pos];
    else up=9;

    ll ans=0;
    if(zero)
    {
        for(int i=0;i<=up;i++)
        {
            ans+=dfs(pos-1,i,1,zero && i==0,limit && i==a[pos]);
        }
    }
    else if((last+len)%2==0)
    {
        for(int i=0;i<=up;i++)
        {
            if((last+i)%2==0)
            {
                ans+=dfs(pos-1,i,len+1,zero && i==0,limit && i==a[pos]);
            }
        }
    }
    else
    {
        for(int i=0;i<=up;i++)
        {
            if((last+i)%2==0)
                ans+=dfs(pos-1,i,len+1,zero && i==0,limit && i==a[pos]);
            else
                ans+=dfs(pos-1,i,1,zero && i==0,limit && i==a[pos]);
        }
    }
    if(!limit && !zero) dp[pos][last][len]=ans;
    return ans;
}





