#include <cstdio>
#include <iostream>
using namespace std;

#define LLD "%lld"
int main()
{
    int T, ca = 1;
    scanf("%d", &T);
    while(T--) {
        long long W;
        scanf(LLD,  &W);
        long long ret = 1;
        while(W % 2 == 0) {
            ret *= 2;
            W /= 2;
        }
        printf("Case %d: ",ca++);
        if(ret == 1 || W == 1) {
            cout << "Impossible" << endl;
        } else {
            cout << W  << " " << ret << endl;
        }
    }
    return 0;
}
