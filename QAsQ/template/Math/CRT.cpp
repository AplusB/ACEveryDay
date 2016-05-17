//CRT gcd(a[i], b[i])==1)
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
//cal x= a_i(mod n_i)
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

//(gcd(a[i], b[i]!=1)
LL Mod;

bool merge(LL a1, LL n1, LL a2, LL n2, LL& a3, LL& n3)
{
    LL d = gcd(n1,n2);
    LL c = a2-a1;
    if(c%d) return false;
    c = (c%n2+n2)%n2;
    c /= d;n1 /= d;n2 /= d;
    c *= inv(n1, n2),c %= n2;
    c *= n1*d,c += a1;
    n3 = n1*n2*d;
    a3 = (c%n3+n3)%n3;
    return true;
}
//cal x=ai(mod ni),
LL China_Reminder2(int len, LL* a, LL* n)
{
    LL a1 = a[0], n1 = n[0];
    LL a2, n2;
    for(int i = 1; i < len; i++)
    {
        LL aa, nn;
        a2 = a[i], n2 = n[i];
        if(!merge(a1, n1, a2, n2, aa, nn)) return -1;
        a1 = aa;
        n1 = nn;
    }
    Mod = n1;
    return (a1%n1+n1)%n1;
}
