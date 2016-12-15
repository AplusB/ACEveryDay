#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=1000+9;
const int inf=2e9+9;

ll pre[50];

int main()
{

    ll x=1;
    for(int i=0;i<5;i++)
    {
        x+=1;
        x*=x;
        x-=1;
        pre[i+1]=x;
    }
    char num[1000];
    while(~scanf("%s",num))
    {
        int len=strlen(num);
        if(len>10)
        {
            printf("TAT\n");continue;
        }
        ll tmp=0;
        for(int i=0;i<len;i++)
        {
            tmp=tmp*10+num[i]-'0';
        }
        if(tmp==0)
        {
            printf("TAT\n");continue;
        }
        if(tmp>pre[5])
        {
            printf("TAT\n");continue;
        }
        for(int i=1;i<=5;i++)
        {
            if(tmp<=pre[i])
            {
                printf("%d\n",i);break;
            }
        }
    }
    return 0;
}
