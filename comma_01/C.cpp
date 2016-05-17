#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX = 180 + 3;

struct node {
  int x, y, z;
  int dp;  
};

bool cmp (node a, node b)
{
    if (a.x < b.x) return true;
    if (a.x == b.x && a.y < b.y) return true;
    return false;
}

int main()
{
    int n, iCase = 0;
    while (scanf("%d", &n) != EOF, n) {
        node s[MAX];
        int l, c, r, cnt = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &l, &c, &r);
            s[cnt++] = (node){l,c,r,r};
            s[cnt++] = (node){l,r,c,c};
            s[cnt++] = (node){c,l,r,r};
            s[cnt++] = (node){c,r,l,l};
            s[cnt++] = (node){r,l,c,c};
            s[cnt++] = (node){r,c,l,l};
        }
        
        sort(s, s+cnt, cmp);
        //cout << cnt << endl;
        /*
        for (int i = 0; i < cnt; ++i) {
            cout << s[i].x << " " << s[i].y << " " << s[i].z << endl;
        }
        */
        int ans = 0;
        for (int i = 1; i < cnt; ++i) {
            for (int j = 0; j < i; ++j) {
                if (s[i].x > s[j].x && s[i].y > s[j].y)
                    s[i].dp = max(s[j].dp + s[i].z, s[i].dp);
            }
            ans = max(ans, s[i].dp);
        }
        
        printf("Case %d: maximum height = %d\n", ++iCase, ans);
    }
    
    return 0;
}