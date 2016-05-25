#include <bits/stdc++.h>
using namespace std;

int n, k;
int Get(string s)
{
    vector<int> pos;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a') {
            pos.push_back(i);
        }
    }
    if(pos.size() <= k) {
        return n;
    } else {
        int ret = 0;
        for(int i = k - 1; i < pos.size(); i++) {
            int right = n - 1;
            if(i + 1 < pos.size() ) {
                 right = pos[i + 1] - 1;
            }
            int left = 0;
            if(i - k >= 0) {
                 left = pos[i - k] + 1;
            }
            if(right - left + 1 > ret) {
                ret = right - left + 1;
            }
        }
        return ret;
    }
}
int main()
{
    cin >> n >> k;
    string s;
    cin >> s;

    int ret = Get(s);
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a') {
            s[i] = 'b';
        } else {
            s[i] = 'a';
        }
    }
    ret = max(ret, Get(s));
    cout << ret << endl;
    return 0;
}
