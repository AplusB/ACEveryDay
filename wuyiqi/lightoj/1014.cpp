#include <cstdio>
#include <vector>
#include <algorithm>

int main()
{
    int T, ca = 1;
    scanf("%d", &T);
    while(T--) {
        int P, L;
        scanf("%d%d", &P, &L);
        int n = P - L;
        std::vector<int> ret;
        for(int i = 1; 1LL * i * i <= n; i++) {
            if(n % i == 0) {
                if(i > L)
                    ret.push_back(i);
                if(i != n/i) {
                    if(n / i > L)
                        ret.push_back(n/i);
                }
            }
        }
        std::printf("Case %d:", ca++);
        sort(ret.begin(), ret.end());
        if(ret.size() == 0) puts(" impossible");
        else {
            for(int i = 0; i < ret.size(); i++) {
                printf(" %d", ret[i]);
            }
            puts("");
        }
    }
    return 0;
}
