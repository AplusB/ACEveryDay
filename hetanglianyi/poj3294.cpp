#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#define N 2000010
int r[N] = {0}, x[N] = {0}, sa[N] = {0}, b[N] = {0};
int wa[N] = {0}, wb[N] = {0}, ws[N] = {0}, wv[N] = {0};
int rank[N] = {0}, height[N] = {0};
int n = 0, len = 0, z = 0;


bool cmp (int *r, int a, int b, int l)
{
    return ((r[a] == r[b]) && (r[a + l] == r[b + l]));
}
void calcsa(int *r, int *sa, int n, int m)
{
    int i, j, p, *x = wa, *y = wb, *t;

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

void calcheight(int *r, int *sa, int n)
{
    int i, j, p;
    for (i = 1; i <= n; i++)
    {
        rank[sa[i]] = i;
    }
    p = 0;
    for (i = 0; i < n; i++)
    {
        j = sa[rank[i] - 1];
        while (r[j + p] == r[i + p])
        {
            p++;
        }
        height[rank[i]] = p;
        if (p > 0) p--;
    }
}
void write(int re)
{
    int i, j, k, t, s, minn;
    for (i = 2; i <= len; i = j + 1)
    {
        while (height[i] < re && i <= len)
            i++;
        j = i;
        while (height[j] >= re)
            j++;
        if (j - i + 1 < ((n) / 2)) continue;
        s = 0; z++; minn = len;
        for (k = i - 1; k < j; k++)
        {
            if (((t = x[sa[k]]) != 0) &&(b[t] != z))
            {
                if (sa[k] < minn) minn= sa[k];
                b[t] = z;
                s++;
            }
        }
        if (s > ((n) / 2)) {
            for (k = minn; k < minn + re; k++)
                printf("%c", r[k] - 200);
            printf("\n");
        }
    }
}

bool check(int mid)
{
    int i, j, k, t, s;
    for (i = 2; i <= len; i = j + 1)
    {
        while (height[i] < mid && i <= len)
            i++;
        j = i;
        while (height[j] >= mid)
            j++;
        if (j - i + 1 < ((n) / 2)) continue;
        s = 0; z++;
        for (k = i - 1; k < j; k++)
        {
            if (((t = x[sa[k]]) != 0) &&(b[t] != z))
            {
                b[t] = z;
                s++;
            }
        }
        if (s > ((n) / 2)) return 1;
    }
    return 0;

}
void deal()
{
    int l = 0, r = len;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    if (r <= 0) printf("?\n");
    else{
       // printf("%d\n", r);
        write(r);
    }
}
int main()
{
    while ((scanf("%d", &n) != EOF) && (n != 0))
    {
        len = 0;
        char c[1100];
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", c);
            int k = strlen(c);
            for (int  j = 0; j < k; j++)
            {
                r[j + len] = c[j] + 200;
                x[j + len] = i;
            }
            r[k + len] = i;
            x[len + k] = 0;
            len += k + 1;
        }
        len--;
        r[len] = 0;
        if (n == 1)
        {
            for (int i = 0; i < len / 2; i++)
                printf("%c", r[i] - 200);
            printf("\n\n");
            continue;
        }

        calcsa(r, sa, len + 1, 400);
        calcheight(r, sa, len);
        deal();
        printf("\n");
    }
    return 0;
}
