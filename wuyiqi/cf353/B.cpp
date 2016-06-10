#include <bits/stdc++.h>
using namespace std;

int n;
bool F(int x) {
        return 1 <= x && x <= n;
}
int main() {
        int a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        int ret = 0;
        for(int i = 1; i <= n; i++) {
                int x = i + a - d;
                int y = i + b - c;
                int z = i + a + b - c - d;
                if(F(x) && F(y) && F(z) ) {
                        ret++;
                }
        }
        cout << 1LL * ret * n << endl;
        return 0;
}
