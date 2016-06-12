#include <bits/stdc++.h>
#define LL long long
#define PI acos(-1.0)
using namespace std;


void solve()
{
    int n,l = 0;
    scanf("%d",&n);
    int mark = -1;
    int a;
    for(int i = 0; ; i++)
    {
        if( ((n>>i)&1) == 1)
        {
            l++;
            if(((n>>(i+1))& 1) == 0)
            {
                a = i;
                mark = 1;
            }

        }
        if(mark == 1) break;
    }

    n ^= (1<<(a+1));
    n ^= (1<<a);
    n >>= a;
    n <<= a;
    for(int i = 1; i < l; i++)
    {
        n |= (1<<(i-1));
    }
    printf("%d\n",n);
}

int main(void)
{
    int t,cnt = 0;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d: ",++cnt);
        solve();
    }
    return 0;
}
