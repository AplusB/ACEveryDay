#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main() {
        int T, ca = 1;
        cin >> T;
        while(T--) {
                int n;
                string start;
                cin >> n >> start;
                printf("Case %d: ", ca++);
                if(start == "Alice") {
                        if(n % 3 == 1) {
                                puts("Bob");
                        } else {
                                puts("Alice");
                        }
                } else {
                        if(n % 3 == 0) {
                                puts("Alice");
                        } else {
                                puts("Bob");
                        }
                }
        }
        return 0;
}
