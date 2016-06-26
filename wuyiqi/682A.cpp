#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    long long ret = 0;
    for(int i = 1; i <= n; i++) {
        int target = ((5 - i) % 5 + 5) % 5;
        if(target && target <= m) {
            ret++;
        }
        ret += (m - target) / 5;
    }
    cout << ret << endl;
    return 0;
}
