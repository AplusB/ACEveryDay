//区间更新：---来自wonter巨（我大哥
/*
更新：
首先我们定义 delta[i] 表示从 i ~ n的数字都增加了delta[i]。
这样的话，对于每次更新区间[a, b]，我们只需要令 delta[a] += d，表示：从a到n每个数都增加了d。。
但我们其实只需要从a到b每个数都增加d，所以我再令delta[b + 1] -= d，将之前多增加的减掉，这样的话，就相当于从a到b都增加了d。
查询
我们定义a[i]表示原来数列的第i个数，那么对于每次查询[a, b]的和，就是sum(b) – sum(a – 1)，sum(x)表示数列1 – x的和。 
我们求1 ~ x时，delta[1]对他的贡献是x*delta[1]，因为delta[1]是表示从1到n都增加delta[1]。 
sum(x) ＝ a[1] + a[2] + … + a[x] + delta[1] * x + delta[2] * (x – 1) + delta[3] * (x – 2) + … + delta[x]
＝ segma(a[i]) + segma(delta[i] * (x – i + 1))（1 <= i <= x）＝ segma(a[i]) + segma(delta[i]) * (x + 1) – segma(delta[i] * i)
正文：
我们发现a[i]这个数组是不变的，所以我们不管他，直接开个数组不变就好了。
delta[i] 和 delta[i] * i这两个数组会变化，我们可以开两个数组。 c1表示delta[i]，c2表示delta[i] * i 所以上面的更新，根据c1和c2的定义，因为delta[a] += d, delta[b + 1] -= d，
所以我们只需要将 c1[a] += d, c1[b + 1] -= d，c2[a] += d * a, c2[b + 1] -= d * (b + 1)，就可以了。 查询的话，就只需要求前缀和就好了。 
*/
//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-5;
const double pi=acos(-1.0);
const int mod=1e8+7;
const LL INF=0x3f3f3f3f;

const int N=1e5+7;

LL num[N],c1[N],c2[N];
LL n,q;

void update(LL *x,LL i,LL p)
{
    while(i<=n)
    {
        x[i]+=p;
        i+=i&(-i);
    }
}

LL sum(LL *x,LL i)
{
    LL ans=0;
    while(i)
    {
        ans+=x[i];
        i-=i&(-i);
    }
    return ans;
}
LL query(LL x)
{
    LL ans=num[x]+(x+1)*sum(c1,x)-sum(c2,x);
    return ans;
}

int main()
{

    scanf("%lld%lld",&n,&q);
    num[0]=0;
    for(LL i=1;i<=n;i++)
    {
        LL x;
        scanf("%lld",&x);
        num[i]=num[i-1]+x;
    }
    while(q--)
    {
        char s[5];
        scanf("%s",s);
        LL a,b,c;
        if(strcmp(s,"Q")==0)
        {
            scanf("%lld%lld",&a,&b);
            printf("%lld\n",query(b)-query(a-1));
        }
        else
        {
            scanf("%lld%lld%lld",&a,&b,&c);

            update(c1,a,c);
            update(c1,b+1,-c);

            update(c2,a,c*a);
            update(c2,b+1,-(b+1)*c);
        }
    }

}

