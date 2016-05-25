#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
int x;
int main()
{
    int t, cas = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &x);
        printf("Case #%d:\n", ++cas);
        printf("*");
        for (int i = 1; i <= 12; i++)printf("-");
        printf("*\n");
        x = x / 10;
        for (int i = 1; i <= 10 - x; i++)
        {
            printf("|");
            for (int i = 1; i <= 12; i++)printf(".");
            printf("|\n");

        }
        for (int i = 10 - x + 1; i <= 10; i++)
        {
            printf("|");
            for (int i = 1; i <= 12; i++)printf("-");
            printf("|\n");
        }
        printf("*");
        for (int i = 1; i <= 12; i++)printf("-");
        printf("*\n");
    }
    return 0;
}
