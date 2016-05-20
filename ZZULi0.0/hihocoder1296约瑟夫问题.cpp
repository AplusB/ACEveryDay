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
const int N = 1005;

int Josephus(int n,int k)
{
    int ret;
    if(n == 1) return 0;
    if(n < k)
    {
        ret = 0;
        for(int i = 2; i <= n; i++)
            ret = (ret+k)%i;
        return ret;
    }
    ret = Josephus(n - n/k,k);
    if(ret < n % k) ret = ret - n%k +n;
    else ret = ret - n%k + (ret - n % k)/(k - 1);

    return ret;
}
int main(void)
{
    int t,n,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        printf("%d\n",Josephus(n,k) );
    }
    return 0;
}
