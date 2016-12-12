#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=50;
const ll inf=2e10+9;

char n1[maxn],n2[maxn];
map<char,ll> aha;
ll x1,x2;

ll deal(ll bi,char x[]);

int main()
{
    ll tag,radix;
    while(~scanf("%s%s%lld%lld",n1,n2,&tag,&radix))
    {
        if(tag==2)
            swap(n1,n2);
        aha.clear();
        for(char i='0';i<='9';i++)
            aha[i]=i-'0';
        for(char i='a';i<='z';i++)
            aha[i]=i-'a'+10;
        x1=deal(radix,n1);
        char rec='1';
        int len2=strlen(n2);
        for(int i=0;i<len2;i++)
        {
            if('0'<=n2[i] && n2[i]<='9')
                rec=max(rec,n2[i]);
            else
            {
                if('0'<=rec && rec<='9')
                    rec=n2[i];
                else rec=max(rec,n2[i]);
            }
        }
        int flag=0;
        ll lt=aha[rec]+1,rt=inf,mid,ans=inf;
        while(lt<=rt)
        {
            mid=lt+(rt-lt)/2;
            ll now=deal(mid,n2);
            //printf("*%I64d %I64d\n",mid,now);
            if(now<0 || now>x1)
            {
                rt=mid-1;
            }
            else if(now==x1)
            {
                rt=mid-1;
                ans=min(ans,mid);
                flag=1;
            }
            else lt=mid+1;
        }
        if(flag==0) printf("Impossible\n");
        else printf("%lld\n",ans);

    }

    return 0;
}

ll deal(ll bi,char x[])
{
    int len=strlen(x);
    ll ans=0,now=1;
    for(int i=len-1;i>=0;i--)
    {
        ans+=now*aha[x[i]];
        now*=bi;
    }
    return ans;
}
