#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX = 1000 + 3;
const int INF = 0x3f3f3f3f;

struct Node {
    int x, y, h;
}s[MAX];
int dp[MAX][2] = {0};
int n, xx, yy, hmax;

bool cmp(Node a, Node b)
{
    return a.h < b.h;
}

void left(int n)
{
    int k = n - 1;
    while (k > 0 && s[n].h - s[k].h <= hmax) {
        if (s[n].x >= s[k].x && s[n].x <= s[k].y) {
            dp[n][0] = s[n].h - s[k].h 
            + min(s[n].x - s[k].x + dp[k][0], s[k].y - s[n].x + dp[k][1]);
            return;
        }
        else --k;
    }
    if (s[n].h - s[k].h > hmax) {
        dp[n][0] = INF; 
    }
    else {
        dp[n][0] = s[n].h;
    }       
}

void right(int n)
{
    int k = n - 1;
    while (k > 0 && s[n].h - s[k].h <= hmax) {
        if (s[n].y >= s[k].x && s[n].y <= s[k].y) {
            dp[n][1] = s[n].h - s[k].h 
            + min(s[n].y - s[k].x + dp[k][0], s[k].y - s[n].y + dp[k][1]);
            return;
        }
        else --k;
    }
    if (s[n].h - s[k].h > hmax) {
        dp[n][1] = INF; 
    }
    else {
        dp[n][1] = s[n].h;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d", &n, &xx, &yy, &hmax);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d%d", &s[i].x, &s[i].y, &s[i].h);
        }
        s[0] = (Node){-20000,20000,0};
        s[n+1] = (Node){xx,xx,yy};
        sort(s, s + 2 + n, cmp);
        memset(dp, 0, sizeof(dp));
  
        for (int i = 1; i <= n + 1; ++i) {
            left(i);
            right(i);
        }
        printf("%d\n",min(dp[n+1][0], dp[n+1][1]));
    }
    
    return 0;
}