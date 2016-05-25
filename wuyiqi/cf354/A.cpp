#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    int p1=-1, p2=-1;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(x == 1) {
            p1 = i;
        }
        if(x == n) {
            p2 = i;
        }
    }
    if(p1 > p2) swap(p1, p2);
    cout << max(n - 1 - p1, p2);
    return 0;
}
