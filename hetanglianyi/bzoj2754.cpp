#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#define maxn 400010
long r[maxn], x[maxn], sa[maxn];
long wa[maxn], wb[maxn], ws[maxn], wv[maxn], rank[maxn], height[maxn];
bool v[maxn];
int name_l[2][maxn], sub_l[maxn];
int name_p[2][maxn], sub_p[maxn];
int name_c[maxn], sub_c[maxn], stack[maxn];
bool marked[maxn];
int n, m, N, top;

bool cmp (long *r, long a, long b, long l)
{
    return ((r[a] == r[b]) && (r[a + l] == r[b + l]));
}


void calcsa(long *r, long *sa, long n, long m)
{
    long i, j, p, *x = wa, *y = wb, *t;

    for (i = 0; i < m; i++) ws[i] = 0;
    for (i = 0; i < n; i++) ws[x[i] = r[i]]++;
    for (i = 1; i < m; i++) ws[i] += ws[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--ws[x[i]]] = i;

    for (j = 1, p = 1; p < n; j *= 2, m = p)
    {
        for (p = 0, i = n - j; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++) if (sa[i] - j >= 0) y[p++] = sa[i] - j;

        for (i = 0; i < n; i++) wv[i] = x[y[i]];
        for (i = 0; i < m; i++) ws[i] = 0;
        for (i = 0; i < n; i++) ws[wv[i]]++;
        for (i = 1; i < m; i++) ws[i] += ws[i - 1];
        for (i = n - 1; i >= 0;i--) sa[--ws[wv[i]]] = y[i];

        t = x; x = y; y = t;
        p = 1; x[sa[0]] = 0;
        for (i = 1; i < n ; i++)
        {
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
        }
    }
 }
void calcheight(long *r, long *sa, long n)
{
    long i, j, p;
    for (i = 1; i <= n; i++)
        rank[sa[i]] = i;
    p = 0;
    for (i = 0; i < n; i++)
    {
        j = sa[rank[i] - 1];
        while (r[i + p] == r[j + p])
            p++;
        height[rank[i]] = p;
        if (p > 0) p--;
    }
    return;
}


inline int find(int x)
{
    if (x < name_p[1][0]) return 0;
    int L = 1, R = n - 1;
    while (L < R + 1)
    {
        int Mid = L + R >> 1;
        if (x < name_p[1][Mid] &&
            x > name_p[1][Mid - 1])
            return Mid;
        if (x > name_p[1][Mid]) L = Mid + 1;
        else R = Mid - 1;
    }
    return -1;
}

int main()
{

    scanf("%d%d", &n, &m);
    N = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &name_l[0][i]);
        for (int j = 0; j < name_l[0][i]; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            r[N++] = tmp + 1;
        }
        r[name_p[0][i] = (N++)] = 0;

        scanf("%d", &name_l[1][i]);
        for (int j = 0; j < name_l[1][i]; ++j)
        {
            int tmp;
            scanf("%d", &tmp);
            r[N++] = tmp + 1;
        }
        r[name_p[1][i] = (N++)] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &sub_l[i]);
        for (int j = 0; j < sub_l[i]; j++)
         {
            int tmp;
            scanf("%d", &tmp);
            r[N++] = tmp + 1;
        }
        r[sub_p[i] = (N++)] = 0;
    }
    calcsa(r, sa, N--, 10010);
    calcheight(r, sa, N);
    for (int i = 0; i < m; i++)
    {
        int pos = rank[sub_p[i] - sub_l[i]];
        top = 0;
        for (int j = pos; j; j--)
        {
            if (height[j] < sub_l[i]) break;
            int tmp = find(sa[j - 1]);
            if (tmp + 1)
            {
                if (!marked[tmp]) ++name_c[stack[top++] = tmp], ++sub_c[i];
                marked[tmp] = 1;
            }
        }
        for (int j = pos + 1; j < N + 1; j++)
        {
            if (height[j] < sub_l[i]) break;
            int tmp = find(sa[j]);
            if (tmp + 1)
            {
                if (!marked[tmp]) ++name_c[stack[top++] = tmp], ++sub_c[i];
                marked[tmp] = 1;
            }
        }
        for (int j = 0; j < top; j++)
            marked[stack[j]] = 0;
    }
    for (int i = 0; i < m; i++)
        printf("%d\n", sub_c[i]);
    for (int i = 0; i < n; i++)
        printf("%d ", name_c[i]);
    printf("\n");
    return 0;
}
