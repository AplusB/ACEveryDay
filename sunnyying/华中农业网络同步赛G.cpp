#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib> 
#define endl '\n'
 
using namespace std;
 
const int MAXN = 1000005;
 
long long a[MAXN],b[MAXN],c[MAXN * 10];
int n,cur,m;
 
int main()
{
    while(scanf("%d %d",&n,&m) == 2)
    {
        int i;
        for(i = 0;i < n;i++)
        {
            scanf("%lld",&a[i]);
        }
         
        cur = 0;
        int j;
        for(i = 0;i < n;i++)
        {
            scanf("%lld",&b[i]);
            for(j = 0;j < a[i];j++)
            {
                c[cur++] = ((j + 1) *(j + 1) - j * j) * b[i];
            }
        }
         
        sort(c,c + cur);
 
        long long ans = 0;
        for(i = 0;i < m;i++)
        {
            ans += c[i];
        }
         
        cout << ans << endl;
    }
    return 0;
}
