#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX = 5e6 + 3;
int a[MAX];

int main()
{
    int n;
    while (scanf("%d", &n) != EOF) {
        int x;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            ++a[x];
        }
        int ans = 0;
        for (int i = 0; i < MAX; ++i) {
            if (a[i] >= (n + 1) / 2)
                ans = i; 
        }
        printf("%d\n", ans);
    }
    
    return 0;
}