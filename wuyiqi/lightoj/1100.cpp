#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int cnt[1024], a[100010];
int main() {
    int T, ca = 1;
    scanf("%d", &T);
    while(T--) {
        int n, q, l, r;
        scanf("%d%d", &n, &q);
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        printf("Case %d:\n", ca++);
        for(int i = 0; i < q; i++) {
            scanf("%d%d", &l, &r);
            if(r - l > 1000) {
                puts("0");
            } else {
                memset(cnt, 0, sizeof(cnt));
                int mi = 1000;
                for(int j = l; j <= r; j++) {
                    cnt[a[j]]++;
                    if(cnt[a[j]] > 1) {
                        mi = 0;
                        break;
                    }
                }
                if(mi == 0) {
                    puts("0");
                    continue;
                }
                int pre = -1;
                for(int j = 1; j <= 1000; j++) {
                    if(cnt[j] > 1) {
                        mi = 0;
                        break;
                    }
                    if(cnt[j]) {
                        if(pre != -1) {
                            mi = min(mi, j - pre);
                        }
                        pre = j;
                    }
                }
                printf("%d\n", mi);
            }
        }
    }
    return 0;
}
