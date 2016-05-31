#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
        int T, n, k, ca = 1;
        cin >> T;
        while(T--) {
                cin >> n >> k;
                printf("Case %d:\n", ca++);
                char s[26];
                memset(s, 0, sizeof(s));
                for(int i = 0; i < n; i++) {
                        s [i] = 'A' + i;
                }
                int cnt = 0;
                do {
                        ++cnt;
                        puts(s);
                        if(cnt == k) break;
                }while(next_permutation(s, s + n));
        }
        return 0;
}
