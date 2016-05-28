#include <bits/stdc++.h>
using namespace std;

double p[222];
double dp[222][222];
int main() {
        int T, ca = 1;
        cin >> T;
        while(T--) {
                int N, K;
                cin >> N >> K;
                for(int i = 0; i < N; i++) {
                        cin >> p[i];
                }
                sort(p, p + N);
                double ret = 0;
                for(int pre = 0; pre <= N; pre++) {
                        for(int last = 0; last + pre <= N; last++) if((pre+last)%2==0 && (pre + last) == K){
                                vector<double> select;
                                for(int i = 0; i < pre; i++) {
                                        select.push_back(p[i]);
                                }
                                for(int i = N - last; i < N; i++) {
                                        select.push_back(p[i]);
                                }
                                for(int i = 0; i <= K; i++) {
                                        for(int j = 0; j <= K; j++) {
                                                dp[i][j] = 0;
                                        }
                                }
                                dp[1][1] = select[0];
                                dp[1][0] = 1.0 - select[0];
                                for(int i = 1; i < K; i++) {
                                        for(int j = 0; j <= i; j++) {
                                                dp[i + 1][j + 1] += dp[i][j] * select[i];
                                                dp[i + 1][j] += dp[i][j] * (1.0 - select[i]);
                                        }
                                }
                                if(dp[K][K / 2] > ret) {
                                        ret = dp[K][K / 2];
                                } 
                        }
                }
                printf("Case #%d: %.9f\n", ca++, ret);
        }
        return 0;
}
