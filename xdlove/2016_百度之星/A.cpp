/* ***********************************************
Author        :xdlove
Created Time  :2016年05月14日 星期六 13时22分41秒
File Name     :A.cpp
************************************************ */

#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 1e5 + 10;
const int mod = 9973;
char s[N];

struct Stree
{
    int val[N << 2];
    void pushup(int u)
    {
        val[u] = val[u << 1] * val[u << 1 | 1] % mod;
    }
    void build(int u,int l,int r)
    {
        if(l == r)
        {
            val[u] = (s[l] - 28 + mod) % mod;
        }
        else 
        {
            int mid = l + (r - l) / 2;
            build(u << 1,l,mid);
            build(u << 1 | 1,mid + 1,r);
            pushup(u);
        }
    }
    int query(int u,int l,int r,int x,int y)
    {
        if(x <= l && y >= r)
            return val[u];
        else 
        {
            int mid = (r - l) / 2 + l;
            int res = 1;
            if(x <= mid) res = res * query(u << 1,l,mid,x,y) % mod;
            if(y > mid) res = res * query(u << 1 | 1,mid + 1,r,x,y) % mod; 
            return res;
        }
    }
}tree;

void solve()
{
    int n,l,r,tp = 0;
    while(~scanf("%d",&n))
    {
        getchar();
        gets(s + 1);
        int len = strlen(s + 1);
        tree.build(1,1,len);
        while(n--)
        {
            scanf("%d %d",&l,&r);
            if(l > r) swap(l,r);
            if(l < 1 || r < 1 || l > len || r > len) 
            {
                printf("%d\n",tp);
                continue;
            }
            tp = tree.query(1,1,len,l,r);
            printf("%d\n",tp);
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve(); 
    return 0;
}
