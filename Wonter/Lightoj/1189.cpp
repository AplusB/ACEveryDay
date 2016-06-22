#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL f[21];
vector<int> ans;
int main()
{
    f[0] = 1;
    for(int i = 1; i <= 20; ++i)
        f[i] = f[i - 1] * i;
    int T, _case = 1;
    scanf("%d", &T);
    while(T--)
    {
        ans.clear();
        LL n;
        scanf("%lld", &n);
        int i = 20;
        while(n > 0 && i >= 0)
        {
            if(n >= f[i])
            {
                n -= f[i];
                ans.push_back(i);
            }
            --i;
        }
        printf("Case %d: ", _case++);
        if(n == 0)
        {
            for(int i = ans.size() - 1;i >= 0;--i)
            {
                if(i == ans.size() - 1)
                    printf("%d!", ans[i]);
                else
                    printf("+%d!", ans[i]);
            }
            printf("\n");
        }
        else
            puts("impossible");
    }
    return 0;
}
