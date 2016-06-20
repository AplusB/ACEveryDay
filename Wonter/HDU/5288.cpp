#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

vector<int> factor[10050];
int pos[10050];
int a[100500];
int l[100050], r[100050];
void Init()
{
    for(int i = 1; i <= 10000; ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            if(i % j == 0)
            {
                int a = j;
                int b = i / j;
                if(a == b)
                    factor[i].push_back(a);
                else if(a < b)
                {
                    factor[i].push_back(a);
                    factor[i].push_back(b);
                }
                else
                    break;
            }
        }
    }
}
int main()
{
    Init();
    int n;
    while(scanf("%d", &n) != EOF)
    {
        memset(pos, 0, sizeof(pos));
        memset(l, 0, sizeof(l));
        for(int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        for(int i = 1; i <= n; ++i)
        {
            for(int ele:factor[a[i]])
                l[i] = max(l[i], pos[ele]);
            pos[ a[i] ] = i;
        }
        int t = *max_element(a + 1, a + 1 + n);
        for(int i = 1;i <= t;++i)
            pos[i] = n + 1;
        for(int i = 1;i <= n;++i)
            r[i] = n + 1;
        for(int i = n; i >= 1; --i)
        {
            for(int ele:factor[a[i]])
                r[i] = min(r[i], pos[ele]);
            pos[ a[i] ] = i;
        }
        int ans = 0;
        for(int i = 1;i <= n;++i)
            ans = (ans + static_cast<__int64>((r[i] - i)) * (i - l[i]) % 1000000007) % 1000000007;
        printf("%d\n", ans);
    }
    return 0;
}
