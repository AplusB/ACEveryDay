#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <climits>
#include <ctime>
#define LL long long
using namespace std;
const int N = 15;

LL b_mod(LL a, LL b, LL c)
{
    a %= c;
    b %= c;
    long long ret = 0;
    long long tmp = a;

    while(b)
    {
        if(b & 1)
        {
            ret += tmp;
            if(ret > c) ret -= c;
        }
        tmp <<= 1;
        if(tmp > c) tmp -= c;
        b >>= 1;
    }
    return ret;
}

bool check(LL a, LL n, LL u, LL t)
{
    LL ret = 1,temp = a % n;
    while(u)
    {
        if(u & 1) ret = b_mod(ret,temp,n);

        temp = b_mod(temp ,temp, n);
        u >>= 1;
    }
    LL last = ret;
    for(int i = 1; i <= t; i++)
    {
        ret = b_mod(ret,ret,n);
        if(ret == 1 && last != 1 && last != n - 1) return true; // 二次探测定理
        // 若y = x^2 ≡ 1(mod n)
        // 但是 x != 1 且 x != n-1
        last = ret;

    }
    if(ret != 1) return true;
    else
        return false;
}

bool miller_Rabin(LL n)
{
    if(n <= 2)
    {
        if(n == 2) return true;
        return false;
    }
    if(n % 2 == 0) return false; //n为非2的合数，直接返回

    LL t = 0;
    LL u = n - 1; //先找到最小的a^u，再逐步扩大到a^(n-1)
    while(u % 2 == 0) u /= 2,t++;

    int s = 10;
    srand(time(NULL));
    for(int i = 1; i <= 8; i++) //s为测试次数
    {
        LL a = rand()%(n-1) + 1; // 随机获取一个2~n-1的数a
        if(check(a,n,u,t)) return false;
    }
    return true;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        LL n;
        scanf("%lld",&n);
        if(miller_Rabin(n))
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
