#include<iostream>
#include<cstdio>
using namespace std;
long long f[36];

int main()
{
    int n;
    f[1] = 2;
    for(int i = 2; i <= 35; i++)
        f[i] = 3 * f[i-1] + 2;
    while(scanf("%d", &n) != EOF)
    {
        printf("%I64d\n", f[n]);
    }
    return 0;
}
