#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
const int N = 400;
int a[N][N], b[N];
int lnk[N];
int n, m, num;
int find(int x)
{
    for(int i = 1; i <= m; i++)
    {
        if(a[x][i] && !b[i])
        {
            b[i] = 1;
            if(lnk[i] == -1 || find(lnk[i]))
            {
                lnk[i] = x;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        memset(a, 0, sizeof(a));
        memset(lnk, -1, sizeof(lnk));
        int re = 0;
        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            for(int j = 0; j < x; j++)
            {
                int y;
                cin >> y;
                a[i][y] = 1;
            }
        }

        for(int i = 0; i < n; i++)
        {
            memset(b, 0, sizeof(b));
            re += find(i);
        }

        if(re == n) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
