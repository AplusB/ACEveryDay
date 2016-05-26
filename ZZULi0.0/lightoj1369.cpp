#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#define LL long long
using namespace std;
const int N = 1e5+5;

LL nums[N];

void solve()
{
    int n,q;
    scanf("%d %d",&n,&q);
    LL sum = 0;

    for(int i = 0; i < n; i++)
    {
        scanf("%lld",&nums[i]);
        sum += nums[i]*(n-1-i*2);
    }

    while(q--)
    {
        int cmd;
        scanf("%d",&cmd);
        if(cmd == 1)
            printf("%lld\n",sum);
        else
        {
            int a;
            LL b;
            scanf("%d %lld",&a,&b);
            sum -= nums[a]*(n-1-a*2);
            nums[a] = b;
            sum += nums[a]*(n-1-a*2);
        }
    }
}

int main(void)
{

    int t,cnt = 0;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n",++cnt);
        solve();
    }
    return 0;
}
