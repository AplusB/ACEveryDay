//x^k % m

LL powerMod(LL x, LL k, LL m)
{
    LL res = 1;
    while(x %= m, k)
    {
        if(k&1) res *= x, res %= m;
        x *= x, k >>=1;
    }
    return res;
}
