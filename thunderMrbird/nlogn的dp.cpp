#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;
int a[500005];
int dp[500005];
int main()
{
        int n, x, y, tt = 0;
        while (scanf("%d", &n) != EOF)
        {
                int ans=1;
                memset(dp, 0, sizeof(dp));
                for (int i = 1; i <= n; i++)
                {
                        scanf("%d %d", &x, &y);
                        a[x] = y;
                }
                dp[1] = a[1];
                for (int i = 2; i <= n; i++)
                {
                        int l = 0, mid, r = ans;
                        while (l <= r)
                        {
                                mid = (l + r) >> 1;
                                if (dp[mid] < a[i])
                                        l = mid + 1;
                                else
                                        r = mid - 1;
                        }
                        dp[l] = a[i];
                        if (l > ans)
                                ans++;
                }
                printf("Case %d:\n",++tt);
                if(ans==1)
                printf("My king, at most %d road can be built.\n\n",ans);
                else
                printf("My king, at most %d roads can be built.\n\n",ans);       
        }
        return 0;
}
