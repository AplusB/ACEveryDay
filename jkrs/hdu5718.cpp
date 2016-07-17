#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cctype>
#include <map>
#include <queue>
#include <cmath>
#include <set>
#include <stack>
#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>
#define pu system("pause")
#define ff first
#define ss second
#define clr(x) memset(x,0,sizeof (x))
#define clrs(x) memset(x,-1,sizeof (x))
#define pt(x,y) (x).push_back(y)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const double pi = acos(-1.0);
const ll inf = 0x7fffffff;
const int mod = 1e8;
const double eps = 1e-6;

char s[10000010],s1[10000010];

int h[15];

int main()
{
    int t;
    scanf("%d",&t);
    while (t --)
    {
        scanf("%s",s);
        clr(h);
        clr(s1);
        for (int i = 0;s[i]; ++ i)
            ++ h[s[i] - '0'];
        int sum = 0;
        for (int i = 1;i <= 9; ++ i)
        {
            if (h[i] > 1)
                sum = 2;
            else if (h[i] == 1)
                ++ sum;
        }
        if (sum == 0 || sum == 1)
            puts("Uncertain");
        else
        {
            int num = 0;
            for (int i = 1;i <= 9; ++ i)
            {
                if (h[i])
                {
                    -- h[i];
                    num = i;
                    break;
                }
            }
            int k = 0;
            for (int i = 9;i >= 0; -- i)
            {
                while (h[i] --)
                {
                    s1[k ++] = i + '0';
                }
            }
            for (int i = k - 1;i >= 0; -- i)
            {
                int temp = (int)(s1[i] - '0') + num;
                if (temp >= 10)
                {
                    s1[i] = temp % 10 + '0';
                    num = temp / 10;
                }
                else
                {
                    s1[i] = temp + '0';
                    num = 0;
                }
            }
            if (num)
                printf("%d",num);
            puts(s1);
        }
    }
    return 0;
}
