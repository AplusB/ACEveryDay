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
const int maxn = 1e6 + 7;
const double eps = 1e-8;
const double PI = acos(-1.0);
string n, m;
map<string, string> ans;

string change(int op, string s)
{
    if (op == 0)
    {
        for (int i = 0; i < 4; i++)
            swap(s[i], s[7-i]);
    }
    else if (op == 1)
    {
        char t = s[3];
        for (int i = 2; i >= 0; i--)
            s[i+1] = s[i];
        s[0] = t;
        t = s[4];
        for (int i = 4; i <= 6; i++)
            s[i] = s[i+1];
        s[7] = t;
    }
    else if (op == 2)
    {
        char t1 = s[1], t2 = s[2];
        char t5 = s[5], t6 = s[6];
        s[1] = t6, s[2] = t1;
        s[5] = t2, s[6] = t5;
    }
    return s;
}

void bfs()
{
    queue<string> q;
    q.push("12345678");
    ans["12345678"] = "";
    while (!q.empty())
    {
        string now = q.front();
        q.pop();
        //cout << now << endl;
        for (int i = 0; i < 3; i++)
        {
            string nxt = change(i, now);
            if (!ans.count(nxt))
            {
                ans[nxt] = ans[now] + (char)('A' + i);
                q.push(nxt);
            }
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    bfs();
    while (cin >> n >> m)
    {
        map<char, char> to;
        for (int i = 0; i < 8; i++)
            to[n[i]] = (char)(i + '1');
        string fun = "";
        for (int i = 0; i < 8; i++)
            fun += to[m[i]];
        cout << ans[fun] << endl;
    }
    return 0;
}
