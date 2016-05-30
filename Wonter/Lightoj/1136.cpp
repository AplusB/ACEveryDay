#include <bits/stdc++.h>
using namespace std;

int Count(int n)
{
    int ret = 0;
    ret = n / 3 * 2;
    if(n % 3 == 2)
        ++ret;
    return ret;
}
int main()
{
    int T, _case = 1;
    scanf("%d", &T);
    while(T--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("Case %d: %d\n", _case++, Count(b) - Count(a - 1));
    }
    return 0;
}
