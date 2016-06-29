#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 20;
int n, a[N];

bool judge(int x, int y, int z)
{
    if(x + y > z && x + z > y && y + z > x)
        return true;
    return false;
}

double calc(int x, int y, int z)
{
    double p = (x + y + z) / 2.0;
    return sqrt(p * (p-x) * (p-y) * (p-z));
}

int main()
{
    while(scanf("%d",&n) != EOF && n != 0)
    {
        for(int i = 0; i < n; i++)  cin >> a[i];
        sort(a, a + n);
        double ans = 0.0;
        for(int i = n - 1; i >= 2; )
        {
             int x = a[i], y = a[i-1], z = a[i-2];
             if(judge(a[i], a[i-1], a[i-2]))
             {
                 ans += calc(a[i], a[i-1], a[i-2]);
                 i -= 3;
             }
             else i--;
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}
