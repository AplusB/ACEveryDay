#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 10003;

struct point
{
    int num;
    int cnt;
};

bool prime[MAX] = {true}, vis[MAX]; 

void init(){    //对素数打表    
    for(int i = 1000, j; i <= MAX; i++){  
        for(j = 2; j < i; j++)  
            if (i % j == 0){  
                prime[i] = false;  
                break;  
            }  
        if (j == i) prime[i] = true;  
    }  
}  


int bfs(int s, int e)
{
    queue<point> q;
    point ss;
    ss.num = s, ss.cnt = 0;
    q.push(ss);
    vis[ss.num] = true;
    
    while (!q.empty()) {
        point tmp = q.front();
        q.pop();
        //cout << "e  " << e << " tmp" << tmp.num << endl;
        if (tmp.num == e) return tmp.cnt;
  
        int t[4];
        t[0] = tmp.num / 1000;
        t[1] = (tmp.num % 1000) / 100;
        t[2] = (tmp.num % 100) / 10;
        t[3] = tmp.num % 10;
        //printf("ttt%d%d%d%d\n", t[0],t[1],t[2],t[3]);
        
        for (int i = 0; i < 4; ++i) {
            int tp = t[i];
            for (int j = 0; j < 10; ++j) {   
                t[i] = j;
                point res;
                res.num = t[0] * 1000 + t[1] * 100 + t[2] * 10 + t[3];
                if (prime[res.num] && t[i] != tp && !vis[res.num]) {
                    vis[res.num] = true; // 注意剪枝防止每次都访问40遍
                    res.cnt = tmp.cnt + 1;
                    q.push(res);
                }
            }
            t[i] = tp;
        }
    }
    return -1;
}

int main()
{
    init();
    int n;
    scanf("%d", &n);
    while (n--) {
        memset(vis, false, sizeof(vis));
        int s,e;
        scanf("%d%d", &s, &e);
        int ans = bfs(s,e);
        if (ans == -1) printf("Impossible\n");
        else printf("%d\n", ans);
    }
    
    return 0;
}