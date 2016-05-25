#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int t, n, m;
int a[1000010];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int sum = 0, l = 1, re = 0x7f7f7f7f;
        for (int i = 1; i <= n;i++)
        {
            sum += a[i];
            if(sum >= m)
            {
                while (sum >= m)
                {
                    sum -= a[l];
                    l++;
                }
                re = min (re, i - l + 1 + 1);
            }
        }
        if (re != 0x7f7f7f7f)
            printf("%d\n" ,re);
        else printf("0\n");
    }

    return 0;
}
