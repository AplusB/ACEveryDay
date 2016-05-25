/**************************************************************
    Problem: 1867
    User: hetanglianyi
    Language: C++
    Result: Accepted
    Time:8 ms
    Memory:1304 kb
****************************************************************/
 
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n, m;
bool a[60][60];
long long f[60][60];
long long gcd(long long a, long long b)
{
    if (b == 0) return a;
    return (gcd(b, a % b));
}
int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        char c;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cin >> c;
                if (c == '*') a[i][j] = 1;
                    else a[i][j] = 0;
            }
        }
        for (int i = 1; i <= n + 1; i++)
            a[n + 1][i] = 1;
        memset(f, sizeof(f), 0);
        f[1][1] = 1LL << (n);
        for (int i = 1; i <= n + 1; i++)
        {
            for (int j = 1; j <= i; j++)
            {
               // cout << i<<' ' << j<<' '<<f[i][j] <<endl;
                if (a[i][j])
                {
                    f[i + 1][j] += f[i][j] / 2;
                    f[i + 1][j + 1] += f[i][j] / 2;
                }
                else
                {
                    f[i + 2][j + 1] += f[i][j];
                }
            }
        }
        long long fenmu = 1LL << (n);
        if (f[n + 1][m + 1] == 0) cout << 0<<endl;
        else{
            long long tmp = gcd(fenmu, f[n + 1][m + 1]);
            cout << f[n + 1][m + 1] / tmp << '/' << fenmu / tmp ;
        }
  
    }
    return 0;
}
