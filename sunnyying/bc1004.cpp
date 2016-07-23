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
#define INF 0x3f3f3f3f3f
#define endl '\n'
#define mod 1000000007
#define ll long long
#define eps 1e-6
using namespace std;
int prime[200100],flag[200100],sum;
void init()
{
    memset(prime,0,sizeof(prime));
    for(int i=2;i*i<=32000;i++)
    {
        if(prime[i]) continue;
        for(int j=i*i;j<=32000;j+=i) prime[j]=1;
    }
    sum=0;
    for(int i=2;i<=32000;i++)
    {
        if(!prime[i]) flag[sum++]=i;
    }
}
int a[50000];
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,d,ans=0;
        scanf("%d%d",&n,&d);
        int xx=d,mark=d;
        for(int i=0;i<sum;i++)
        {
            if(xx==1) break;
            if(flag[i]>d||(ll)d*flag[i]>=n) break;
            while(xx%flag[i]==0)
            {
                mark=min(flag[i],mark);
                xx/=flag[i];
                break;
            }
        }
        for(int i=0;i<sum;i++)
        {
            if(flag[i]>mark||(ll)d*flag[i]>=n) break;
            ans++;
        }
        int res=0;
        cout<<ans<<endl;
    }
    return 0;
}
