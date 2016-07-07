#include <bits/stdc++.h>
using namespace std;

unsigned long long sanci[1000100];
int main()
{
    for(int i = 1; i <= 1000000; i++) {
        sanci[i] = 1LLU*i*i*i;
    }
    unsigned long long m;
    cin >> m;
    unsigned long long l = 1, r = 1LLU << 63 - 1, best = 0, value = 0;
    while(l <= r) {
        unsigned long long mid = l + r >> 1;
        unsigned long long tmp = 0;
        for(int i = 2; sanci[i] <= mid && i <= 1000000; i++) {
            unsigned long long lim = mid / sanci[i];
            tmp += lim;
            if(tmp > m) {
                break;
            }
        }
        if(tmp >= m) {
            best = mid;
            value = tmp;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if(value == m)
        cout << best << endl;
    else
        cout << -1 << endl;
    return 0;
}
