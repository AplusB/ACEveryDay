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
typedef long long ll;
#define MD 1000000007
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 100005;
int pre[maxn], key[maxn], ch[maxn][2], root, tot;
//父节点，键值，左右孩子0左1右，根节点，节点数量
int n;
void NewNode(int &r, int fa, int k)
{
    r = ++tot;
    pre[r] = fa;
    key[r] = k;
    ch[r][0] = ch[r][1] = 0;
}
void Rotate(int x, int kind)    //kind为1时右旋，为0左旋
{
    int y = pre[x];
    ch[y][!kind] = ch[x][kind];
    pre[ch[x][kind]] = y;
    if (pre[y])
        ch[pre[y]][ch[pre[y]][1]==y] = x;
    pre[x] = pre[y];
    ch[x][kind] = y;
    pre[y] = x;
}
void Splay(int r, int goal)
{
    while (pre[r] != goal)
    {
        if (pre[pre[r]] == goal) Rotate(r, ch[pre[r]][0]==r); //左儿子右旋右儿子左旋
        else
        {
            int y = pre[r];
            int kind = (ch[pre[y]][0] == y); //y是左儿子时kind是1，y是右儿子时kind是1
            if (ch[y][kind] == r)
            {
                Rotate(r, !kind);   //r和y左右不同时，之字形
                Rotate(r, kind);
            }
            else
            {
                Rotate(y, kind);   //r和y是一条线时，一字型
                Rotate(r, kind);
            }
        }
    }
    if (goal == 0) root = r;
}
int Insert(int k)
{
    int r = root;
    while (ch[r][key[r]<k])
    {
        //之前有过不再重复插入
        if (key[r] == k)
        {
            Splay(r, 0);
            return 0;
        }
        r = ch[r][key[r]<k];
    }
    NewNode(ch[r][key[r]<k], r, k);
    Splay(ch[r][key[r]<k], 0);
    return 1;
}
int get_small(int x)
{
    int temp = ch[x][0];
    if (temp == 0) return INF;
    while (ch[temp][1])
        temp = ch[temp][1];
    return key[temp];
}
int get_big(int x)
{
    int temp = ch[x][1];
    if (temp == 0) return INF;
    while (ch[temp][0])
        temp = ch[temp][0];
    return key[temp];
}
map<int, int> mp;

int main()
{
    //freopen("H:\\in.txt","r",stdin);
    //freopen("H:\\out.txt","w",stdout);
    while (scanf("%d", &n) != EOF)
    {
        root = tot = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int num;
            scanf("%d", &num);
            mp[num] = i;
            if (i == 1)
            {
                NewNode(root, 0, num);
                continue;
            }
            if (Insert(num) == 0) continue;
            int a = get_small(root);
            int b = get_big(root);
            if (mp[a] > mp[b]) printf("%d ", a);
            else printf("%d ", b);
        }
    }
    return 0;
}
