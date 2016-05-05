/* ***********************************************
Author        :xdlove
Created Time  :2016年05月05日 星期四 20时59分59秒
File Name     :2016_05_05_51nod_1391.cpp
 ************************************************ */

//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
const int N = 5e4 + 5;
vector<int> vec;
int c[N << 1];

struct Node
{
    int x,y;
    void read()
    {
        scanf("%d %d",&x,&y);
    }
    void make_id()
    {
        x = get_id(x);
        y = get_id(y);
    }
    int get_id(int x)
    {
        return lower_bound(vec.begin(),vec.end(),x) - vec.begin() + 1;
    }
    bool operator < (const Node &a) const 
    {
        if(x != a.x) return x < a.x;
        return y < a.y;
    }
}p[N];

void add(int x,int n)
{
    while(x <= n)
    {
        c[x]++;
        x += x & -x;
    }
}

int get_sum(int x,int n)
{
    int s = 0;
    while(x > 0)
    {
        s += c[x];
        x -= x & -x;
    }
    return s;
}

void solve()
{
    int n; 
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        p[i].read();
        vec.push_back(p[i].x);
        vec.push_back(p[i].y);
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for(int i = 0; i < n; ++i) p[i].make_id();
    sort(p,p + n);
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        int tp = get_sum(p[i].y,vec.size());
        ans += i - tp;
        add(p[i].y,vec.size());
    }
    cout << ans << endl;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}
