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
#define Key_value ch[ch[root][1]][0]

int pre[maxn], ch[maxn][2], root, tot1;
int s[maxn], tot2;
int size[maxn];
int key[maxn];
int add[maxn];
int Min[maxn];
int rev[maxn];
int a[maxn];
int n;
//<debug>
void Treavel(int x)
{
    if (x)
    {
        Treavel(ch[x][0]);
        printf("结点：%2d: 左儿子 %2d 右儿子 %2d 父结点 %2d size = %2d\n",x,ch[x][0],ch[x][1],pre[x],size[x]);
        Treavel(ch[x][1]);
    }
}
void debug()
{
    printf("root:%d\n", root);
    Treavel(root);
}
//</debug>

void NewNode(int &r, int fa, int k)
{
    if (tot2) r = s[tot2--];
    else r = ++tot1;
    pre[r] = fa;
    ch[r][0] = ch[r][1] = 0;
    Min[r] = k;
    key[r] = k;
    rev[r] = add[r] = 0;
    size[r] = 1;
}

void Update_rev(int r)
{
    if (r == 0) return ;
    swap(ch[r][0], ch[r][1]);
    rev[r] ^= 1;
}

void Update_add(int r, int val)
{
    if (r == 0) return ;
    add[r] += val;
    key[r] += val;
    Min[r] += val;
}

void PushUp(int r)
{
    size[r] = size[ch[r][0]] + size[ch[r][1]] + 1;
    Min[r] = min(key[r], min(Min[ch[r][0]], Min[ch[r][1]]));
}

void PushDown(int r)
{
    if (rev[r])
    {
        Update_rev(ch[r][0]);
        Update_rev(ch[r][1]);
        rev[r] = 0;
    }
    if (add[r])
    {
        Update_add(ch[r][0], add[r]);
        Update_add(ch[r][1], add[r]);
        add[r] = 0;
    }
}

void Build(int &x, int l, int r, int fa)
{
    if (l > r) return ;
    int mid = (l + r) >> 1;
    NewNode(x, fa, a[mid]);
    Build(ch[x][0], l, mid - 1, x);
    Build(ch[x][1], mid + 1, r, x);
    PushUp(x);
}

void init()
{
    root = tot1 = tot2 = 0;
    ch[root][1] = ch[root][0] = pre[root] = 0;
    size[root] = 0;
    rev[root] = add[root] = 0;
    Min[root] = INF;
    NewNode(root, 0, -1);
    NewNode(ch[root][1], root, -1);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    Build(Key_value, 0, n - 1, ch[root][1]);
    PushUp(ch[root][1]);
    PushUp(root);
}

void Rotate(int x, int kind)
{
    int y = pre[x];
    PushDown(y);
    PushDown(x);  //注意x和y的顺序
    ch[y][!kind] = ch[x][   kind];
    pre[ch[x][kind]] = y;
    if (pre[y])
        ch[pre[y]][ch[pre[y]][1] == y] = x;
    pre[x] = pre[y];
    ch[x][kind] = y;
    pre[y] = x;
    PushUp(y);
}

void Splay(int r, int goal)
{
    PushDown(r);
    while (pre[r] != goal)
    {
        if (pre[pre[r]] == goal)
        {
            PushDown(pre[r]);        //有翻转操作需要先pushdown
            PushDown(r);
            Rotate(r, ch[pre[r]][0] == r);
        }
        else
        {
            PushDown(pre[pre[r]]);   //pushdown
            PushDown(pre[r]);
            PushDown(r);
            int y = pre[r];
            int kind = ch[pre[y]][0] == y;
            if (ch[y][kind] == r)
            {
                Rotate(r, !kind);
                Rotate(r, kind);
            }
            else
            {
                Rotate(y, kind);
                Rotate(r, kind);
            }
        }
    }
    PushUp(r);
    if (goal == 0) root = r;
}

int Get_kth(int r, int k)
{
    PushDown(r);
    int t = size[ch[r][0]] + 1;
    if (t == k) return r;
    if (t > k) return Get_kth(ch[r][0], k);
    else return Get_kth(ch[r][1], k - t);
}

int Get_pre(int r)
{
    PushDown(r);
    if (ch[r][0] == 0) return -1;
    r = ch[r][0];
    while (ch[r][1])
    {
        r = ch[r][1];
        PushDown(r);
    }
    return r;
}

int Get_next(int r)
{
    PushDown(r);
    if (ch[r][1] == 0) return -1;
    r = ch[r][1];
    while (ch[r][0])
    {
        r = ch[r][0];
        PushDown(r);
    }
    return r;
}



void ADD(int l, int r, int val)
{
    Splay(Get_kth(root, l), 0);
    Splay(Get_kth(root, r + 2), root);
    Update_add(Key_value, val);
    PushUp(ch[root][1]);
    PushUp(root);
}

void REVERSE(int l, int r)
{
    Splay(Get_kth(root, l), 0);
    Splay(Get_kth(root, r + 2), root);
    Update_rev(Key_value);
    PushUp(ch[root][1]);
    PushUp(root);
}

void REVOLVE(int l, int r, int T)
{
    int len = r - l + 1;
    T = (T % len + len) % len;
    Splay(Get_kth(root, r - T + 1), 0);
    Splay(Get_kth(root, r + 2), root);
    int temp = Key_value;
    Key_value = 0;
    PushUp(ch[root][0]);
    PushUp(root);
    Splay(Get_kth(root, l), 0);
    Splay(Get_kth(root, l + 1), root);
    Key_value = temp;
    pre[temp] = ch[root][1];
    PushUp(ch[root][1]);
    PushUp(root);
}

void INSERT(int x, int P)
{
    Splay(Get_kth(root, x + 1), 0);
    Splay(Get_kth(root, x + 2), root);
    NewNode(Key_value, ch[root][1], P);
    PushUp(ch[root][1]);
    PushUp(root);
}

void erase(int r)
{
    if (!r) return ;
    s[++tot2] = r;
    erase(ch[r][0]);
    erase(ch[r][1]);
}

void DELETE(int x)
{
    Splay(Get_kth(root, x), 0);
    Splay(Get_kth(root, x + 2), root);
    erase(Key_value);
    pre[Key_value] = 0;
    Key_value = 0;
    PushUp(ch[root][1]);
    PushUp(root);
}

int query(int l, int r)
{
    Splay(Get_kth(root, l), 0);
    Splay(Get_kth(root, r + 2), root);
    return Min[Key_value];
}
char op[20];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int m, l, r, num;
    while (scanf("%d", &n) != EOF)
    {
        init();
        //debug();
        scanf("%d", &m);
        while (m--)
        {
            scanf("%s", op);
            if (strcmp(op,"ADD") == 0)
            {
                scanf("%d%d%d", &l, &r, &num);
                ADD(l, r, num);
            }
            if (strcmp(op,"REVERSE") == 0)
            {
                scanf("%d%d", &l, &r);
                REVERSE(l, r);
            }
            if (strcmp(op,"REVOLVE") == 0)
            {
                scanf("%d%d%d", &l, &r, &num);
                REVOLVE(l, r, num);
            }
            if (strcmp(op,"INSERT") == 0)
            {
                scanf("%d%d", &l, &num);
                INSERT(l, num);
            }
            if (strcmp(op,"DELETE") == 0)
            {
                scanf("%d", &num);
                DELETE(num);
            }
            if (strcmp(op,"MIN") == 0)
            {
                scanf("%d%d", &l, &r);
                printf("%d\n", query(l, r));
            }
        }
    }
    return 0;
}

