#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 10000;
const int INF = 0x3f3f3f3f;

int main()
{
    int n;
    int s[MAX];
    while (scanf("%d", &n) != EOF) {
        int ans = 0, x;

        while (n--) {
            scanf("%d", &x);
            int minn = INF;
            int tmp;
            bool flag = false;
            for (int j = 0; j < ans; ++j) {
                if (s[j] >= x && minn > s[j] - x) {
                    minn = s[j] - x;
                    flag = true;
                    tmp = j;
                }
            }
            if (!flag) {
                s[ans] = x;
                ++ans;
            }
            else s[tmp] = x;
            
        }
        printf("%d\n", ans);
    }
    
    return 0;
}