#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX = 1000 + 3;
const int INF = 0x3f3f3f3f;

struct Mouse {
    int w, s, no;
}mouse[MAX];
int dp[MAX];
int pre[MAX];
int res[MAX];

bool cmp(Mouse a, Mouse b)
{
    if (a.w < b.w) return true;
    if (a.w == b.w && a.s > b.s) return true;
    return false;
}

int main()
{
    int ww, ss, n = 1, ans = -1, last;
    while (scanf("%d%d", &ww, &ss) != EOF) {
        mouse[n] = (Mouse) {ww, ss, n};
        dp[n] = 1;
        pre[n] = 0;
        ++n;
    }
    sort(mouse + 1, mouse + 1 + n, cmp);
    dp[1] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (mouse[i].w > mouse[j].w && mouse[i].s < mouse[j].s && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                pre[i] = j;
            }
            if (ans < dp[i]) {
                ans = dp[i];
                last = i;
            }
        }
    }
    
    int tmp = last, cnt = 0;
    while (tmp != 0) {
        res[cnt++] = tmp;
        tmp = pre[tmp];
    }    
    printf("%d\n", ans);
    for (int i = cnt - 1; i >= 0; --i) 
        printf("%d\n", mouse[res[i]].no);
    
    return 0;
}