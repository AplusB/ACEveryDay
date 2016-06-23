#include <bits/stdc++.h>
using namespace std;

int main() {
        int n;
        cin >> n;
        int ret = 0; int s;
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for(int i = 0; i < n; i++) {
                cin >> s;
                if(s == 4) ret++;
                if(s == 1) cnt1++;
                if(s == 2) cnt2++;
                if(s == 3) cnt3++;
        }
        ret += cnt3;
        if(cnt1 >= cnt3) cnt1 -= cnt3;
        else cnt1 = 0;
        ret += cnt2 / 2;
        cnt2 %= 2;
        ret += cnt1 / 4;
        cnt1 %= 4;
        if(cnt1 + cnt2 * 2 > 4) ret += 2;
        else if(cnt1 + cnt2*2) ret ++;
        cout << ret << endl;
        return 0;
}
