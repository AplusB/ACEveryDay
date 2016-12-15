#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=50+9;

int duru[maxn];
int num[maxn];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            scanf("%d",&duru[i]);
        sort(duru,duru+n);
        int loca=1,last=duru[0];
        num[0]=duru[0];
        for(int i=1;i<n;i++)
        {
            if(duru[i]==last) continue;
            num[loca++]=duru[i];
            last=duru[i];
        }
        int flag=0;
        for(int i=0;i<loca;i++)
        {
            if(i+2==loca) break;
            if(num[i]+1==num[i+1] &&num[i]+2==num[i+2])
            {flag=1;break;}
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}


