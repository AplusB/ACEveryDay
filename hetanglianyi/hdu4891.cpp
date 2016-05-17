#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n;

int main()
{
    string s, t;
    while (scanf("%d",&n)!=EOF)
    {
        getchar();
        s = "";
        for (int i = 1; i <= n; i++)
        {
            getline(cin, t);
            s = s + t;
        }

        long long re = 1;
        int l = s.length();
        int cnt1 = 1, flag = 1, cnt2 = 2;
        for (int i = 0;i < l; i++)
        {
            if (s[i] == '{')
            {
                flag = 0;
            }
            else if (s[i] == '}')
            {
                re *= cnt1;
                if (re > 100000) break;
                flag = 1;
                cnt1 = 1;
            }
            else if (s[i] == '$')
            {
                flag =- 1 * flag;
            }

            if (flag == 0)
            {
                if (s[i] == '|') cnt1++;
            }
            if (flag == -1)
            {
                if (s[i] == ' ' && s[i+1] == ' ') cnt2++;
                else if (s[i] == ' ')
                {
                    re *= cnt2;
                    cnt2 = 2;
                }

                if (re > 100000) break;
            }
        }

        if (re > 100000) printf("doge\n");
        else printf("%I64d\n", re);
    }
    return 0;
}
