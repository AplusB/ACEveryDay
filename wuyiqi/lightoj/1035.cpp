#include <cstdio>
#include <map>
#include <iostream>
using namespace std;

int main() {
        int T, ca = 1;
        cin >> T;
        while(T--) {
                int n;
                cin >> n;
                printf("Case %d: %d =", ca++, n);
                map<int, int> mp;
                for(int i = 2; i <= n; i++) {
                        int num = i;
                        for(int j = 2; j * j <= num; j++) if(num % j == 0){
                                while(num % j == 0) {
                                        num /= j;
                                        mp[j]++;
                                }
                        }
                        if(num > 1) {
                                mp[num]++;
                        }
                }
                bool flag=true;
                for(map<int, int> :: iterator it = mp.begin(); it != mp.end(); ++it) {
                        if(!flag) {
                                printf(" *");
                        }
                        printf(" %d (%d)", it->first, it->second);
                        flag = false;
                }
                puts("");
        }
        return 0;
}
