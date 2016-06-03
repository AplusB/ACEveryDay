#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main() {
        int n, h, k;
        long long ret = 0;
        cin >> n >> h >> k;
        multiset<int> st;
        for(int i = 0; i < n; i++) {
                cin >> a[i];
        }
        int stk = 0;
        for(int i = 0; i < n; i++) {
                if(stk + a[i] <= h) {
                        stk += a[i];
                } else {
                        if(stk <= k) {
                                stk = 0;
                                ret++;
                        } else {
                                ret += stk / k;
                                stk %= k;
                        }
                        if(stk + a[i] > h) {
                                ret ++ ;
                                stk = a[i];
                        } else {
                                stk += a[i];
                        }
                }
        }
        ret += (stk + k - 1) / k;
        cout << ret << endl;
        return 0;
}
