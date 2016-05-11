#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 8 + 3;

char chess[MAX][MAX];
bool visy[MAX];
int n, k, ans;

// x hang, y lie
void dfs(int x, int cnt)
{
    if (cnt == k) {
        ++ans;
        return;
    }
    if (x >= n) return;
    
    for (int j = 0; j < n; ++j) {
        if (chess[x][j] == '#' && visy[j] == 0) {
            visy[j] = 1;
            dfs(x+1, cnt+1);
            visy[j] = 0;
        }
    }
    dfs(x+1, cnt);
    
    return;
}

int main()
{
   while(scanf("%d%d", &n, &k) && n != -1 && k != -1) {
       ans = 0;
       memset(visy, 0, sizeof(visy));
       memset(chess, 0, sizeof(chess));
       for (int i = 0; i < n; ++i)
          scanf("%s",chess[i]);
          
       dfs(0,0);
       
       printf("%d\n", ans);
   }
    
    
    
    return 0;
}