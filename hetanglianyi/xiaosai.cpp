#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[1010],f[1010][4010];
int mod = 10007;
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        memset(f, 0, sizeof(f));
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

        int re = 0;
        for(int i = 1; i <= n; i++)
        {
            re = (re + i) % 10007;
            for(int j = i - 1; j >= 1; j--)
            {
                int x = a[i] - a[j] + 2000;
                re = (re + f[j][x]) % 10007;
                f[i][x] = (f[i][x] + f[j][x] + 1) % 10007;
            }
        }
        cout << re << endl;
    }
    return 0;
}
