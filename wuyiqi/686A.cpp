#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int ret = 0;
    long long tot = x;
    for(int i = 0; i < n; i++) {
        string a;
        int b;
        cin >> a >> b;
        if(a[0] == '+') {
            tot += b;
        } else {
            if(tot >= b) tot -= b;
            else ret++;
        }
    }
    cout << tot << " " << ret ;
    return 0;
}
