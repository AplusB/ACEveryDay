#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define LL __int64
using namespace std;
const int N = 2*1e4+10;
const int MOD = 1e9+7;
int nums[N],tmp[N];
int sumcnt[N],lf[N],rt[N];
int main(void)
{
    int n,loc,cur,cnt = 0;
    while(scanf("%d",&n) != -1)
    {
        cnt = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d",&nums[i]);
        for(int j = 1; j <= n; j++)
        {
            memset(sumcnt,0,sizeof(sumcnt));
            memset(lf,0,sizeof(lf));
            memset(rt,0,sizeof(rt));
            cur = nums[j];
            for(int i = 1; i <= n; i++)
                tmp[i] = nums[i];
            for(int i = 1; i <= n; i++)
            {
                if(tmp[i] > cur) tmp[i] = 1;
                else if(tmp[i] == cur)
                {
                    tmp[i] = 0;
                    loc = i;
                }
                else tmp[i] = -1;
            }
            lf[n] = 1;
            rt[n] = 1;
            for(int i = loc - 1; i >= 1; i--)
            {
                sumcnt[i] = sumcnt[i+1]+tmp[i];
                lf[sumcnt[i] + n]++;
            }
            for(int i = loc + 1; i <= n; i++)
            {
                sumcnt[i] = sumcnt[i-1]+tmp[i];
                rt[sumcnt[i] + n]++;
            }
            int ans = 0;
            for(int i = 0; i <= 2*n-1; i++)
            {
                ans += lf[i]*rt[2*n-i];
            }
            if(cnt == 0)
            {
                printf("%d",ans);
                cnt = 1;
            }
            else
                printf(" %d",ans);
        }
        printf("\n");
    }

    return 0;
}
