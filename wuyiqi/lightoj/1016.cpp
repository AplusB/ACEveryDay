#include <cstdio>
#include <algorithm>
struct PT
{
        int x, y;
        void in() {
                scanf("%d%d", &x, &y);
        }
        bool operator < (const PT &cmp) const {
                return y < cmp.y;
        }
}p[50010];
int main() {
        int T, ca = 1;
        scanf("%d", &T);
        while(T--) {
                printf("Case %d: ", ca++);
                int n,w;
                scanf("%d%d", &n, &w);
                for(int i = 0; i < n; i++) {
                        p[i].in();
                }
                std::sort(p, p + n);
                int ret = 0;
                for(int i = 0; i < n; i++) {
                        int j = i;
                        while(j + 1 < n && p[j + 1].y-p[i].y<=w) {
                                j++;
                        }
                        ret++;
                        i = j;
                }
                printf("%d\n", ret);
        }
        return 0;
}
