#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int y, m, d, b = 0;
        scanf("%d%d%d", &y, &m, &d);
        if(d == 30 && (m == 9 || m == 11)) printf("YES\n");
        else if((m + d) % 2 )printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
