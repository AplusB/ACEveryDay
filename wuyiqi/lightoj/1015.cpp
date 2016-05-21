#include <cstdio>

int main()
{
    int T, ca = 1;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        int ret = 0;
        for(int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if(x >0) ret+=x;
        }
        printf("Case %d: %d\n", ca++, ret);
    }
    return 0;
}
