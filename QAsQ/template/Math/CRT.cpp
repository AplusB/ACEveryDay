//中国剩余定理（互质版 （gcd(a[i], b[i])==1））
#include <cstdio>
#define LL long long
LL a[15], b[15];

LL Extend_Euclid(LL a, LL b, LL&x, LL& y)
{
    if(b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    LL d = Extend_Euclid(b, a%b, x, y);
    LL t = x;
    x = y;
    y = t - a/b*y;
    return d;
}
//求解模线性方程组x=ai(mod ni)
LL China_Reminder(int len, LL* a, LL* n)
{
    int i;
    LL N = 1;
    LL result = 0;
    for(i = 0; i < len; i++)
        N = N*n[i];
    for(i = 0; i < len; i++)
    {
        LL m = N/n[i];
        LL x, y;
        Extend_Euclid(m, n[i], x, y);
        x = (x%n[i]+n[i])%n[i];
        result = (result + m*a[i]*x%N)%N;
    }
    return result;
}

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; i++)
            scanf("%I64d %I64d", &a[i], &b[i]);
        printf("%I64d\n",China_Reminder(n, b, a));
    }
    return 0;
}
//中国剩余定理（不互质版（gcd(a[i], b[i]有可能不为1））
//不互质版可以过互质版的题，但对于互质的题，不互质版时间效率稍逊。
#include <cstdio>
#define LL long long
long long Mod;

long long gcd(long long a, long long b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}

//a在模n乘法下的逆元，没有则返回-1
long long inv(long long a, long long n)
{
    long long x, y;
    long long t = exgcd(a, n, x, y);
    if(t != 1) return -1;
    return (x%n+n)%n;
}
//将两个方程合并为一个
bool merge(long long a1, long long n1, long long a2, long long n2, long long& a3, long long& n3)
{
    long long d = gcd(n1,n2);
    long long c = a2-a1;
    if(c%d) return false;
    c = (c%n2+n2)%n2;
    c /= d;
    n1 /= d;
    n2 /= d;
    c *= inv(n1, n2);
    c %= n2;
    c *= n1*d;
    c += a1;
    n3 = n1*n2*d;
    a3 = (c%n3+n3)%n3;
    return true;
}
///求模线性方程组x=ai(mod ni),ni可以不互质
long long China_Reminder2(int len, long long* a, long long* n)
{
    long long a1 = a[0], n1 = n[0];
    long long a2, n2;
    for(int i = 1; i < len; i++)
    {
        long long aa, nn;
        a2 = a[i], n2 = n[i];
        if(!merge(a1, n1, a2, n2, aa, nn)) return -1;
        a1 = aa;
        n1 = nn;
    }
    Mod = n1;
    return (a1%n1+n1)%n1;
}
long long a[1000], b[1000];
int main()
{
    int k;
    while(~scanf("%d", &k))
    {
        for(int i = 0; i < k; i++)
            scanf("%I64d %I64d",&a[i],&b[i]);
        printf("%I64d\n", China_Reminder2(k, b, a));
    }
    return 0;
}
