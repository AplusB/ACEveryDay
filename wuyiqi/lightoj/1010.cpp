#include <cstdio>
#include <algorithm>
int main()
{
    int T, ca = 1;
    scanf("%d", &T);
    while(T--) {
        int n , m;
        scanf("%d%d", &n, &m);
        if(n > m) std::swap(n, m);
        int ret = -1;
        if(n == 1) {
            ret = m;
        }
        if(n == 2) {
            ret = 2 * (m / 4 * 2 + std::min(2, m % 4));
        }
        if(n >= 3) {
            ret = (n * m + 1) / 2;
        }
        printf("Case %d: %d\n", ca++, ret);
    }
    return 0;
}
