#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;
bool isPrime[MAXN + 1];     //是否素数
int d[MAXN + 1];            //最大的质因子
int mul[MAXN + 1];          //所有质因子的积
int a[MAXN + 1];            //答案数组，用来记忆化
void Init()
{
    for(int i = 1;i <= MAXN;++i)
    {
        mul[i] = 1;
        isPrime[i] = true;
    }
    for(int i = 2; i <= MAXN; ++i)
    {
        if(isPrime[i] == false)
            continue;
        d[i] = mul[i] = i;
        for(int j = i + i; j <= MAXN; j += i)
        {
            isPrime[j] = false;
            d[j] = i;
            mul[j] *= i;
        }
    }
}
int Slove(int m, int n) //1-m中有多少个与n互质
{
    int arr[10];
    arr[0] = 0;
    while(n > 1)
    {
        if(d[n] != arr[arr[0]])
        {
            arr[ arr[0] + 1 ] = d[n];
            ++arr[0];
        }
        n /= d[n];
    }
    int ret = m;
    int t = 1 << arr[0];
    for(int i = 1; i < t; ++i)
    {
        int tmp = 1;
        int cnt = 0;
        for(int j = 1; j <= arr[0]; ++j)
        {
            if(i & (1 << (j - 1)))
            {
                ++cnt;
                tmp *= arr[j];
            }
        }
        if(cnt & 1)
            ret -= m / tmp;
        else
            ret += m / tmp;
    }
    return ret;
}
int main()
{
    Init();
    int T, _case = 1;
    scanf("%d", &T);
    while(T--)
    {
        memset(a, -1, sizeof(a));
        int n, m;
        scanf("%d%d", &n, &m);
        printf("Case %d: ", _case++);
        if(n > m)
            swap(n, m);
        if(m == 0)
        {
            puts("0");
            continue;
        }
        if(n == 0)
        {
            puts("1");
            continue;
        }
        long long ans = 2;
        for(int i = 1; i <= n; ++i)
        {
            if(a[ mul[i] ] == -1)
                a[ mul[i] ] = Slove(m, i);
            ans += a[ mul[i] ];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
