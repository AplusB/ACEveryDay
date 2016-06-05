#include <bits/stdc++.h>
using namespace std;

int main()
{
        int n, m, a;
        cin >> n >> m >> a;
        int x = (n + a - 1) / a ;
        int y = (m + a - 1) / a ;
        cout << 1LL * x * y << endl;
        return 0;
}
