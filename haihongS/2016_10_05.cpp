#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<iostream>
using namespace std;

typedef long long ll;
const double pi=acos(-1.0),eps=1e-6;


const int maxn=2e5+9;
const ll mod=20160519;
const ll phi=26880696;

struct mat
{
    ll m[2][2];
};

mat bi=
{
    1LL,1LL,
    1LL,0LL
};

mat I
{
    1LL,0LL,
    0LL,1LL
};

mat mul(mat a,mat b,ll m);
mat quick_pow(mat a,ll b,ll mm);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        mat pp=quick_pow(bi,n,phi);
        ll v=pp.m[0][1];
        mat go=quick_pow(bi,v,mod);
        printf("%lld\n",go.m[0][1]%mod);
    }
    return 0;
}

mat quick_pow(mat a,ll b,ll mm)
{
    mat ans=I;
    while(b>0)
    {
        if(b&1)
            ans=mul(ans,a,mm);
        a=mul(a,a,mm);
        b>>=1;
    }
    return ans;
}

mat mul(mat a,mat b,ll mm)
{
    mat c;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            c.m[i][j]=0;
            for(int k=0;k<2;k++)
            {
                c.m[i][j]+=a.m[i][k]*b.m[k][j]%mm;
                c.m[i][j]%=mm;
            }
        }
    }
    return c;
}

