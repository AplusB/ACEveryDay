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
const int maxn = 1e3 + 10;
const double eps = 1e-8;
const double PI = acos(-1.0);
typedef pair<int, int> pii;

int n, m;
int d;

struct Matrix
{
    LL a[100][100];
    Matrix()
    {
        memset(a, 0, sizeof(a));
    }
    inline void init()
    {
        for (int i = 0; i < d; i++) a[i][i] = 1;
    }
    inline Matrix operator + (const Matrix &B)const
    {
        Matrix C;
        for (int i = 0; i < d; i++)
            for (int j = 0; j < d; j++)
                C.a[i][j] = (a[i][j] + B.a[i][j]) % 2015;
        return C;
    }
    inline Matrix operator * (const Matrix &B)const
    {
        Matrix C;
        for(int i = 0; i < d; i++)
            for(int j = 0; j < d; j++)
                for(int k = 0; k < d; k++)
                    C.a[i][j] = (C.a[i][j] + a[i][k] * B.a[k][j]) % 2015;
        return C;
    }
    inline Matrix operator ^ (const int &t)const
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
                printf("%d%c", a[i][j], (j == d - 1) ? '\n' : ' ');
        }
    }
};

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        Matrix mat;
        d = n + 2;
        for (int i = 1; i <= n; i++)
        {
            int k, u;
            scanf("%d", &k);
            while (k--)
            {
                scanf("%d", &u);
                mat.a[i][u] = 1;
            }
        }
        for (int i = 0; i <= n; i++)
            mat.a[0][i] = 1;
        mat = mat ^ m;
        int num = 0;
        for (int i = 0; i <= n; i++)
            num = (num + mat.a[0][i]) % 2015;
        printf("%d\n", num);
    }
    return 0;
}
