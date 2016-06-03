#include <bits/stdc++.h>
using namespace std;

int main() {
        int n, h;
        cin >> n  >> h;
        int ret = 0;
        int x;
        for(int i = 0; i < n; i++) {
                cin >> x;
                if(x > h) ret += 2;
                else ret += 1;
        }
        cout << ret << endl;
        return 0;
}
