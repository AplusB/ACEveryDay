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
#define lowbit(x) ((x)&(-x))
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define MP(a, b) make_pair(a, b)
const int INF = 0x3f3f3f3f;
const int maxn = 10000 + 7;
const double eps = 1e-8;
const int MOD = 1000000009;
const double PI = acos(-1.0);
int n, mod;
const int d = 16;

struct Matrix
{
    LL a[100][100];
    Matrix()
    {
        memset(a, 0, sizeof(a));
    }
    void init()
    {
        for (int i = 0; i < d; i++) a[i][i] = 1;
    }
    Matrix operator * (const Matrix &B)const
    {
        Matrix C;
        for(int i = 0; i < d; i++)
            for(int j = 0; j < d; j++)
                for(int k = 0; k < d; k++)
                    C.a[i][j] = (C.a[i][j] + a[i][k] * B.a[k][j]) % mod;
        return C;
    }
    Matrix operator ^ (const int &t)const
    {
        Matrix res, A = (*this);
        res.init();
        int p = t;
        while (p)
        {
            if (p & 1) res = res * A;
            A = A * A;
            p >>= 1;
        }
        return res;
    }
    void print()
    {
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
                printf("%-3d", a[i][j]);
            printf("\n");
        }
    }
}mat;

void dfs(int step, int now, int pre)
{
    if (step > 4) return ;
    if (step == 4)
    {
        mat.a[pre][now]++;
        return ;
    }
    dfs(step + 2, (now << 2) | 3, (pre << 2) | 3);
    dfs(step + 1, (now << 1) | 1, pre << 1);
    dfs(step + 1, now << 1, (pre << 1) | 1);
}

int main()
{
    dfs(0, 0, 0);
    while (scanf("%d%d", &n, &mod) && n)
    {
        Matrix res = mat ^ n;
        printf("%lld\n", res.a[15][15]);
    }
    return 0;
}
