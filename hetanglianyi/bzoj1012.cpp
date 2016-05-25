#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <vector>
using namespace std;
int m, d;
int tree[1000000];
void Insert(int p, int l, int r,int x, int num)
{
    if (l == r)
    {
        tree[p] = num;
        return;
    }
    int mid = (l+r) / 2;
    if (x <= mid) Insert(p*2, l, mid, x, num);
    else Insert(p*2+1, mid+1, r, x, num);
    tree[p] = max(tree[p*2], tree[p*2+1]);
}
int Find(int p, int l, int r, int x, int y)
{
    if (x <= l && r <= y)
    {
        return tree[p];
    }
    int mid = (l+r) / 2;
    if (mid >= y) return Find(p*2, l, mid, x, y);
    if (mid < x) return Find(p*2+1, mid+1, r, x, y);
    return max(Find(p*2, l, mid, x, mid) , Find(p*2+1, mid+1, r, mid+1, y));
}
int main()
{
    scanf("%d%d", &m, &d);
    int tot = 0, t = 0;
    memset(tree, 0, sizeof(tree));
    for (int i = 1; i <= m; i++)
    {
        char s[10];
        int x;
        scanf(" %s %d", s, &x);
        if (s[0] == 'A')
        {
             ++tot;
            Insert(1, 1, m, tot, ((long long)t+x) %d);

        }
        else
        {
            //cout << tot-x+1<<' '<<tot <<endl;
            t = Find(1, 1, m, tot-x+1, tot);
            printf("%d\n", t);
        }
//        for (int j = 1; j <= 10; j++) cout <<tree[j]<<' ';
//        cout << endl;
    }
    return 0;
}
