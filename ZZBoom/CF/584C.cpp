#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-5;
const double pi=acos(-1.0);
const int mod=1e8+7;
const LL INF=0x3f3f3f3f;

const int N=1e5+10;

char s1[N],s2[N],ans[N];
bool status[N];

char kill(char a,char b)
{
    for(int i='a';i<='z';i++)
    {
        if(i!=a&&i!=b)
            return i;
    }
}

int main()
{
    int n,t,sum;
    scanf("%d%d",&n,&t);
    scanf("%s%s",s1,s2);
    sum=0;
    memset(status,0,sizeof(status));
    for(int i=0;i<n;i++)
    {
        if(s1[i]!=s2[i])
            sum++;
        else
            status[i]=1;
    }
    if(sum==t)
    {
        for(int i=0;i<n;i++)
        {
            if(status[i])
                ans[i]=s1[i];
            else
                ans[i]=kill(s1[i],s2[i]);
        }
    }
    else if(sum<t){     //补齐t-sum;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(status[i])
            {
                if(cnt<(t-sum))
                {
                    ans[i]=kill(s1[i],s2[i]);
                    cnt++;
                }
                else
                    ans[i]=s1[i];
            }
            else
                ans[i]=kill(s1[i],s2[i]);
        }
    }
    else{                       //不同的多了t-sum
        int cnt1=0,cnt2=0;      //把两个串都补齐，可能补不齐，所以最后还要判断。
        for(int i=0;i<n;i++)
        {
            if(status[i])
                ans[i]=s1[i];
            else
            {
                if(cnt1<(sum-t))
                {
                    ans[i]=s1[i];
                    cnt1++;
                }
                else if(cnt2<(sum-t))
                {
                    ans[i]=s2[i];
                    cnt2++;
                }
                else
                    ans[i]=kill(s1[i],s2[i]);
            }
        }
    }
    int sum1=0,sum2=0;
    for(int i=0;i<n;i++)
    {
        if(s1[i]!=ans[i])
            sum1++;
        if(s2[i]!=ans[i])
            sum2++;
    }
    if(sum1!=t||sum2!=t)
    {
        puts("-1");
        return 0;
    }
    ans[n]='\0';
    printf("%s",ans);
    return 0;
}
