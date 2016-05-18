#include <cstdio>

long long Get(int n) 
{
    return 1LL * (1 + 2 * n - 1) * n / 2;
}
int main()
{
    int T, ca = 1;
    scanf("%d", &T);
    while(T--) {
        long long s;
        scanf("%lld", &s);
        int l = 1, r = (int) 1e9;
        int best = - 1;
        while(l <= r) {
            int mid = l + r >> 1;
            long long sum = Get(mid);
            if(sum < s) {
                l = mid + 1;
            } else {
                best = mid;
                r = mid - 1;
            }
        }
        long long pre = Get(best - 1);
        int x = -1, y = -1;
        if(best & 1) {
            if(pre + best >= s) {
                x = best;
                y = s - pre;
            } else {
                y = best;
                x = best - (s - pre - best);
            }
        } else {
            if(pre + best >= s) {
                x = s - pre;
                y  = best;
            } else {
                x = best;
                y = best - (s - pre - best);
            }
        }
        printf("Case %d: %d %d\n", ca++, x, y);
    }
    return 0;
}
