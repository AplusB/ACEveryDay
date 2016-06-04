#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define LL long long
#define Lowbit(x) ((x)&(-x))
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define MP(a, b) make_pair(a, b)
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const int maxn = 200010;
const double eps = 1e-8;
const double PI = acos(-1.0);
typedef pair<int, int> pii;

struct Trie
{
    int next[1010][4], fail[1010];
    bool end[1010];
    int root, L;
    int newnode()
    {
        for (int i = 0; i < 4; i++)
            next[L][i] = -1;
        end[L++] = false;
        return L - 1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char s[])
    {
        int len = strlen(s);
        int now = root;
        for (int i = 0; i < len; i++)
        {
            if (next[now][getch(s[i])] == -1)
                next[now][getch(s[i])] = newnode();
            now = next[now][getch(s[i])];
        }
        end[now] = true;
    }
    void build()
    {
        queue<int> Q;
        fail[root] = root;
        for (int i = 0; i < 4; i++)
            if (next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while (!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            if (end[fail[now]] == true)
                end[now] = true;
            for (int i = 0; i < 4; i++)
                if (next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
//    Matrix getMatrix()
//    {
//        Matrix res = Matrix(L+1);
//        for (int i = 0; i < L; i++)
//            for (int j = 0; j < 26; j++)
//                if (end[next[i][j]] == false)
//                    res.mat[i][next[i][j]]++;
//        for (int i = 0; i < L + 1; i++)
//            res.mat[i][L] = 1;
//        return res;
//    }
    int getch(char ch)
    {
        if (ch == 'A') return 0;
        if (ch == 'C') return 1;
        if (ch == 'G') return 2;
        if (ch == 'T') return 3;
    }

    int dp[1010][1010];
    int DP(char buf[])
    {
        int len = strlen(buf);
        memset(dp, INF, sizeof(dp));
        dp[0][root] = 0;
        for (int i = 0; i < len; i++)
            for (int j = 0; j < L; j++)
                if (dp[i][j] != INF)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int now = next[j][k];
                        if (end[now]) continue;
                        int temp;
                        if (getch(buf[i]) == k) temp = dp[i][j];
                        else temp = dp[i][j] + 1;
                        dp[i+1][now] = min(dp[i+1][now], temp);
                    }
                }
        int ans = INF;
        for (int i = 0; i < L; i++)
            ans = min(ans, dp[len][i]);
        if (ans == INF) return -1;
        return ans;
    }
};

char buf[1010];
Trie ac;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, ncase = 1;
    while (scanf("%d", &n) && n)
    {
        ac.init();
        for (int i = 0; i < n; i++)
        {
            scanf("%s", buf);
            ac.insert(buf);
        }
        ac.build();
        scanf("%s", buf);
        printf("Case %d: %d\n", ncase++, ac.DP(buf));
    }
    return 0;
}
