#include <cstdio>


const int  N = 5000010;
unsigned long long euler[N];
void init()
{
    for(int i = 0; i < N; i++) euler[i] = i;
    for(int i = 2; i < N; i++) {
        if(euler[i] == i) {
            for(int j = i; j < N; j += i) {
                euler[j] = euler[j] / i * (i - 1);
            }
        }
    }
    for(int i = 2; i < N; i++) {
        euler[i] = euler[i - 1] + 1LL * euler[i] * euler[i];
    }
}
int main()
{
    init();
    int T, ca = 1;
    scanf("%d", &T);
    while(T--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("Case %d: %llu\n", ca++, euler[b] - euler[a - 1]);
    }
    return 0;
}
