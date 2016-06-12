#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
const int ha = 13331;
const int N = 600;
typedef unsigned long long uLL;
int b[N][N], a[N][N], f[N][N];
uLL Hash1[N][N], Hash2[N][N], sum[N];
int n, m;
void change()
{
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++)
        b[m - j + 1][i] = a[i][j];
    swap(n, m);
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++)
        a[i][j] = b[i][j];
}

bool check(int x, int y, int len)
{
    uLL r,c;
    r = Hash1[x][y] - Hash1[x][y - len] * sum[len];
    c = Hash2[x][y] - Hash2[x - len][y] * sum[len];
    return r == c;
}

int solve()
{
    memset(Hash1, 0, sizeof(Hash1));
    memset(Hash2, 0, sizeof(Hash2));
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++)
    {
        Hash1[i][j] = Hash1[i][j - 1] * ha + a[i][j];
        Hash2[i][j] = Hash2[i - 1][j] * ha + a[i][j];
    }

    sum[0] = 1;
    for (int i = 1; i <= 500; i ++)
        sum[i] = sum[i - 1] * ha;

    int ans = 0;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++)
    {
        int L = 1, R = min(i, j);
        while (L < R)
        {
            int mid = (L + R + 1) >> 1;
            if (check(i, j, mid))
                L = mid;
            else
                R = mid - 1;
        }
        f[i][j] = min(f[i - 1][j - 1] + 2, L);
        ans = max(ans, f[i][j]);
    }
    return ans;
}

int main()
{
    int T;
    cin >> T;
    while (T --)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            char s[N];
            scanf("%s", s);
            for (int j = 0; j < m; j++)
                a[i + 1][j + 1] = s[j];
        }
        int ans = 0;
        for (int i = 0; i < 4; i ++)
        {
            ans = max(ans, solve());
            change();
        }
        cout << ans * (ans + 1) / 2 << endl;
    }
    return 0;
}
