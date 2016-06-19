#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int maxVal[100005][20];
int minVal[100005][20];
int a[100005], n;
int f[20];
void Init()
{
    f[0] = 1;
    for(int i = 1; i < 20; ++i)
        f[i] = f[i - 1] * 2;
    for(int i = 1; i <= n; ++i)
        maxVal[i][0] = minVal[i][0] = a[i];
    for(int j = 1; j < 20; ++j)
        for(int i = 1; i <= n; ++i)
        {
            if(i + f[j - 1] > n)
                continue;
            maxVal[i][j] = max(maxVal[i][j - 1],
                               maxVal[i + f[j - 1]][j - 1]);
            minVal[i][j] = min(minVal[i][j - 1],
                               minVal[i + f[j - 1]][j - 1]);
        }
}
int QueryMax(int l, int r)
{
    int k = log2(r - l + 1);
    return max(maxVal[l][k],
               maxVal[r - f[k] + 1][k]);
}
int QueryMin(int l, int r)
{
    int k = log2(r - l + 1);
    return min(minVal[l][k],
               minVal[r - f[k] + 1][k]);
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int k;
        __int64 ans = 0;
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        Init();
        for(int i = 1; i <= n; ++i)
        {
            int left, right;
            left = 1, right = i;
            while(left < right)
            {
                int mid = left + ((right - left) >> 1);
                if(QueryMax(mid, i) - QueryMin(mid, i) < k)
                    right = mid;
                else
                    left = mid + 1;
            }
            ans += i - left + 1;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
