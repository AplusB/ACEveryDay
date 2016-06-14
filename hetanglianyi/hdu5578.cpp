#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 2000;
const int inf = 0x3f3f3f3f;
char s[N];

int main ()
{
    int t, cas=0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", s);
        int n = strlen(s), ans = inf;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (s[i] == s[j])
                    ans = min(ans, j - i);
        if (ans == inf) ans = -1;
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}
