#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
const int N = (1 << 17);
char s[60];
bool b[N];
int f[N];
bool check(int x, int len)
{
    char tmp[60];
    int t = 0;
    for(int i = 0; i < len; i++)
        if((x >> i) & 1) tmp[t++] = s[i];

    for(int i = 0; i < t / 2; i++)
        if(tmp[i] != tmp[t-1-i]) return false;
    return true;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        memset(b, 0, sizeof(b));
        scanf("%s", s);
        int len = strlen(s);
        int maxn = (1 << len) - 1;
        for(int i = 1; i <= maxn; i++)
        {
            b[i] = check(i, len);
        }

        memset(f, 0x3f7f7f7f, sizeof(f));
        f[0] = 0;
        for(int i = 1; i <= maxn; i++)
        for(int j = i; j != 0; j = (j - 1) & i)
            if(b[j]) f[i] = min(f[i], f[i ^ j] + 1);
        printf("%d\n", f[maxn]);

    }
    return 0;
}
