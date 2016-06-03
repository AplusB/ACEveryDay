#include <bits/stdc++.h>
using namespace std;

int sgn(int x)
{
        return x > 0 ? 1 : (x < 0 ? -1 : 0);
}
int main() {
        int a, b, c;
        cin >> a >> b >> c;
        if(b==a || c && (b - a) % c == 0 && sgn(b-a)==sgn(c) ) {
                cout << "YES";
        } else {
                cout << "NO";
        }
        return 0;
}
