#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int fa[1000100], v[1000100];
int findfa(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = findfa(fa[x]);
}
int main()
{
    scanf("%d", &n);
    for (int i= 1; i <= 10001; i++)
        fa[i] = i, v[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        int fx = findfa(x);
        int fy = findfa(y);
        if (fx == fy) v[fx] = 1;
        else{
            if (fx < fy) swap(fx, fy);
            v[fy] = 1;
            fa[fy] = fx;
        }
    }
    for(int i = 1; i <= 10001;i++)
	    if(!v[i])
        {
            printf("%d",i-1);
            break;
        }
    return 0;
}
