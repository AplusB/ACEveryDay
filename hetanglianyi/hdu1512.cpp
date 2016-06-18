#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>

using namespace std;

#define N 1000010
int key[N], l[N], r[N], d[N], root[N];
int fa[N];
int n, m, tot = 0;
int init(int x)
{
    key[++tot] = x;
    l[tot] = r[tot] = d[tot] = 0;
    return tot;
}

int mergeheap(int x, int y)
{
    if((!x)|| (!y)) return y + x;
    if(key[x] < key[y]) swap(x, y);
    r[x] = mergeheap(r[x], y);
    if(d[l[x]] < d[r[x]]) swap(l[x], r[x]);
    d[x] = d[r[x]] + 1;
    return x;
}

int top(int x)
{
    return key[x];
}

int pop(int x)
{
    return mergeheap(l[x], r[x]);
}

int insert(int x, int y)
{
    return mergeheap(x, init(y));
}



int findfa(int a)
{
    return (fa[a] == a ? a : fa[a] = findfa(fa[a]));
}

bool unions(int a,int b)
{
    fa[findfa(a)] = findfa(b);
}

int main()
{
    while(scanf("%d", &n) != EOF)
    {

        for(int i = 0;i <= n;i++)
            fa[i] = i;
        tot = 0;
        for(int i = 1; i <= n; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            root[i] = 0;
            root[i] = insert(root[i], tmp);
        }
        scanf("%d" ,&m);
        for(int i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            if(findfa(a) == findfa(b)) printf("-1\n");
            else
            {
                int x,y;
                a = findfa(a), b = findfa(b);

                x = top(root[a]);
                root[a] = pop(root[a]);
                root[a] = insert(root[a], x/2);

                y = top(root[b]);
                root[b] = pop(root[b]);
                root[b] = insert(root[b], y/2);

                root[b] = mergeheap(root[a], root[b]);
                unions(a, b);

                printf("%d\n", top(root[b]));
            }
        }
    }
    return 0;
}
