#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn=2e6+9;
const int inf=1e9+9;

struct II
{
    ll n,m;
} num[maxn];


int cmp(const II &x,const II &y);

int main()
{
    ll x;
    while(cin>>x)
    {
        if(x==1)
        {
            printf("1\n1 1\n");
            continue;
        }
        int loca=0;
        ll len=x;
        for(ll i=1; i<=maxn*10; i++)
        {

            if(i>=len) break;
            ll tmp=i*(i+1);
            if((6*x)%tmp==0)
            {
                tmp=6*x/tmp;
                tmp=(tmp+i-1);
                if(tmp%3!=0) continue;
                tmp/=3;
                if(tmp<i) continue;
                num[loca].m=tmp;
                num[loca].n=i;
                len=min(len,tmp);
                loca++;
                if(tmp!=i)
                {
                    num[loca].n=tmp;
                    num[loca].m=i;
                    loca++;
                }
            }
        }
        sort(num,num+loca,cmp);
        printf("%d\n",loca);
        for(int i=0; i<loca; i++)
            printf("%I64d %I64d\n",num[i].n,num[i].m);
    }
    return 0;
}

int cmp(const II &x,const II &y)
{
    if(x.n==y.n) return x.m<y.m;
    return x.n<y.n;
}
