#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
using namespace std;

map<long long,long long> f[45];
int n;
long long m;
long long gcd(long long a, long long b)
{
    if(b == 0)return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}

void prepare()
{
    f[1][1] =1;
    map<long long, long long>::iterator it;
    for(int i = 2; i <= 40;i++)
    {
        f[i] = f[i - 1];
        f[i][i]++;
        for(it = f[i - 1].begin(); it != f[i - 1].end(); it++)
        {
            f[i][lcm(it->first,i)] += it->second;
        }
    }
}
int main()
{
    prepare();
    int t, cas = 0;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d%I64d", &n, &m);
        long long re = 0;
        map<long long, long long>::iterator it;
        for(it = f[n].begin();it != f[n].end(); it++)
          if(it->first >= m) re += it->second;
        printf("Case #%d: %I64d\n", ++cas, re);
    }
    return 0;
}
