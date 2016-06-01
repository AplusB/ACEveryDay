#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000 + 3;

struct Interval {
    int sta, end, eff;
    
    bool operator < (const Interval& i) const {
        return sta < i.sta;
    }
};

Interval interval[MAX];
int dp[MAX];

int main()
{
    int n,m,r;
    cin >> n >> m >> r;
    for (int i = 0; i < m; ++i) {
        cin >> interval[i].sta >> interval[i].end >> interval[i].eff;
        interval[i].end += r;
    }
    sort(interval, interval + m);
    
    for (int i = 0; i < m; ++i) {
        dp[i] = interval[i].eff;
        for (int j = 0; j < i; ++j) {
            if (interval[i].sta >= interval[j].end) {
                dp[i] = max(dp[i], dp[j] + interval[i].eff);
            }
        }
    }
    
    cout << *max_element(dp, dp + m) << endl;
    
    return 0;
}