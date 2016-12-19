#include <bits/stdc++.h>


using namespace std;
typedef long long ll;


const int maxn=2e6+9;

vector<ll> aha;

void change(ll x,ll base);

int main()
{
    ll n,b;
    while(~scanf("%lld %lld",&n,&b))
    {
        if(n==0)
        {
            printf("Yes\n0\n");continue;
        }
        aha.clear();
        change(n,b);
        int len=aha.size();
        if(aha[0]==0)
        {
            printf("No\n");
            for(int i=len-1;i>=0;i--)
            {
                if(i!=len-1) printf(" ");
                printf("%lld",aha[i]);
            }
            printf("\n");
            continue;
        }
        int flag=1;
        for(int i=0;i<len;i++)
        {
            if(aha[i]!=aha[len-i-1])
            {
                flag=0;break;
            }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
        for(int i=len-1;i>=0;i--)
        {
            if(i!=len-1) printf(" ");
            printf("%lld",aha[i]);
        }
        printf("\n");

    }
    return 0;
}

void change(ll x,ll base)
{
    while(x)
    {
        aha.push_back(x%base);
        x/=base;
    }
}
