#include <bits/stdc++.h>
using namespace std;
double a[10][10];
double flow[10][10];
int main()
{
    int n, t;
    cin >> n >> t;
    for(int i = 0; i < t; i++) {
        a[1][1] += 1;
        memset(flow, 0, sizeof(flow));
        flow[1][1] = a[1][1] - 1;
        a[1][1] = 1;
        for(int level = 2; level <= n; level++) {
            for(int j = 1; j <= level; j++) {
                a[level][j] += flow[level - 1][j] * 0.5;
                if(j)
                    a[level][j] += flow[level - 1][j - 1] * 0.5;
                if(a[level][j] - 1 > -1e-8) {
                    flow[level][j] = a[level][j] - 1;
                    a[level][j] = 1;
                }
            }
        }
    }
    int ret = 0;
    for(int level = 1; level <= n; level++) {
        for(int i = 1; i <= level; i++) {
            if(a[level][i] - 1 > -1e-8) {
                ret++;
            }
        }
    }
    cout << ret ;

    return 0;
}
