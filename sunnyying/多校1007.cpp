#include <cstdio>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <math.h>
#include <stdlib.h>
#define endl '\n'
#define eps 1e-8
#define ll long long
#define mod 1000000007
using namespace std;
int k,dig[30],p[10];
long long dp[11000][30];
map<string,int>A;
int judge(string s,int x)
{
    int xx=s.length();
    for(int i=xx-1;i>=max(xx-k+1,0);i--)
        if(s[i]-'0'==x) return 1;
    return 0;
}
long long dfs(int x,string pre,int mark,int flag)
{
    if(x==-1) return 1;
    if(!mark&&dp[A[pre]][x]!=-1) return dp[A[pre]][x];
    int mx=mark?dig[x]:9;
    long long ans=0;
    for(int i=0;i<=mx;i++)
    {
        if(judge(pre,i)) continue;
        string ss;
        if(pre.length()==k-1) for(int j=1;j<pre.length();j++) ss+=pre[j];
        else ss+=pre;
        if(!flag||(flag&&i!=0)) ss+=(i+'0');
        ans+=dfs(x-1,ss,mark&&i==mx,flag&&i==0);
    }
    if(!mark) dp[A[pre]][x]=ans;
    return ans;
}
long long solve(long long x)
{
    memset(dp,-1,sizeof(dp));
    int sum=0;
    while(x)
    {
        dig[sum++]=x%10;
        x/=10;
    }
    return dfs(sum-1,"",1,1);
}
int main()
{
    int sum=1;
    string ss;
    for(int i4=0;i4<=9;i4++)
    {
        ss="";
       char c=i4+'0';ss+=c;
        A[ss]=sum++;
    }
    for(int i3=0;i3<=9;i3++)
    for(int i4=0;i4<=9;i4++)
    {

        ss="";
       char c=i3+'0';ss+=c;
        c=i4+'0';ss+=c;
        A[ss]=sum++;
    }
    for(int i2=0;i2<=9;i2++)
    for(int i3=0;i3<=9;i3++)
    for(int i4=0;i4<=9;i4++)
    {

        ss="";
       char c=i2+'0';ss+=c;
        c=i3+'0';ss+=c;
        c=i4+'0';ss+=c;
        A[ss]=sum++;
    }
    for(int i1=0;i1<=9;i1++)
    for(int i2=0;i2<=9;i2++)
    for(int i3=0;i3<=9;i3++)
    for(int i4=0;i4<=9;i4++)
    {

        ss="";
       char c=i1+'0';ss+=c;
        c=i2+'0';ss+=c;
        c=i3+'0';ss+=c;
        c=i4+'0';ss+=c;
        A[ss]=sum++;
    }
    long long l,r;
    while(~scanf("%lld%lld%d",&l,&r,&k))
    {
        cout<<solve(r)-solve(l-1)<<endl;
    }
    return 0;
}
