#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define LL __int64
using namespace std;
const int N = 1e5+5;
int nums[20],used[20];


LL solveDB(LL x, int n)
{
    if(x == 0) return 0;
    if(x > (1LL<<n)-1 )
        return (1LL<<n) - ( (1LL<<(n+1)) - 1 - x - solveDB( (1LL<<(n+1)) -1 - x,n-1));
    else
        return solveDB(x,n-1);
}

void solve()
{
    LL L,R;
    scanf("%I64d %I64d",&L,&R);
    printf("%I64d\n",solveDB(R,60) - solveDB(L-1,60));
}


int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        solve();
    }
    return 0;
}
