#include <bits/stdc++.h>
using namespace std;

int main() {
        int a, b, c;
        cin >> a >> b >> c;
        if(b==a || c && (b - a) % c == 0 && (b - a) >= 0) {
                cout << "YES";
        } else {
                cout << "NO";
        }
        return 0;
}
