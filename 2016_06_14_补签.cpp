#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        double sum1 = 0.0, sum2 = 0.0, ans;
        for(int i = 1; i < m; i++){
            scanf("%d", &a[i]);
            sum1 += a[i];
            sum2 += a[i] * a[i];
        }
        for(int i = m; i <= n; i++){
            scanf("%d", &a[i]);
            sum1 += a[i] - a[i - m];
            sum2 += a[i] * a[i] - a[i - m] * a[i - m];
            ans = sqrt((sum2 - sum1 * sum1 / m) / (m - 1.0));
            printf("%.9lf\n", ans);
        }
    }
    return 0;
}

