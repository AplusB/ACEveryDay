#include <cstdio>
#include <cstring>
#include <algorithm>
int a[1010];
int divisors[1010];

int cmp(int a, int b) {
    return divisors[a] < divisors[b] || divisors[a] == divisors[b] && a > b;
}

int main() {
    int T, ca = 1;
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= i; j++) {
            if(i % j == 0) {
                divisors[i]++;
            }
        }
        a[i] = i;
    }
    std::sort(a + 1, a + 1000 + 1, cmp);
    scanf("%d",&T);
    while(T--) {
        printf("Case %d: ", ca++);
        int n;
        scanf("%d", &n);
        printf("%d\n", a[n]);
    }
    return 0;
}
