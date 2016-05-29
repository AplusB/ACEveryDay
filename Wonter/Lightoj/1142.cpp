#include <bits/stdc++.h>
using namespace std;
struct mt
{
    int x[35][35];
    mt()
    {
        memset(x, 0, sizeof(x));
    }
};
int n;
mt units;
mt Mul(mt a, mt b)
{
    mt ret;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            for(int k = 0; k < n; ++k)
                ret.x[i][j] = (ret.x[i][j] + a.x[i][k] * b.x[k][j]) % 10;
    return ret;
}
mt Add(mt a, mt b)
{
    mt ret;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            ret.x[i][j] = (a.x[i][j] + b.x[i][j]) % 10;
    return ret;
}
mt FastPow(mt a, int b)
{
    mt ret;
    for(int i = 0; i < n; ++i)
        ret.x[i][i] = 1;
    while(b)
    {
        if(b & 1)
            ret = Mul(ret, a);
        a = Mul(a, a);
        b /= 2;
    }
    return ret;
}
mt Slove(mt a, int k)
{
    if(k == 0)
        return units;
    if(k == 1)
        return a;
    mt res = Slove(a, k / 2);
    if(k & 1)
        return Add(Add(res, Mul(res, FastPow(a, k / 2))), FastPow(a, k));
    else
        return Add(res, Mul(res, FastPow(a, k / 2)));
}
int main()
{
    int T, _case = 1;
    scanf("%d", &T);
    while(T--)
    {
        mt arr;
        int k;
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; ++i)
        {
            units.x[i][i] = 1;
            for(int j = 0; j < n; ++j)
            {
                scanf("%d", &arr.x[i][j]);
                arr.x[i][j] %= 10;
            }
        }
        printf("Case %d:\n", _case++);
        mt ans = Slove(arr, k);
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
                printf("%d", ans.x[i][j]);
            printf("\n");
        }
    }
    return 0;
}
