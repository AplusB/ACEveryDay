#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <queue>
#include <cmath>
#include <set>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#define pu system("pause")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const double pi = acos(-1.0);
const int inf = 0x7fffffff;
const int mod = 1e9 + 7;

list <char> l;

char s[500010],cmd[500010];

int main()
{
    int n,m,st;
    scanf("%d%d%d",&n,&m,&st);
    scanf("%s",s);
    scanf("%s",cmd);
    for (int i = 0;s[i]; ++ i)
        l.push_back(s[i]);
    list <char> :: iterator it = l.begin();
    advance(it,st - 1);
//    printf("cur it = %c\n",*it);
    for (int i = 0;cmd[i]; ++ i)
    {
//        printf("cmd[%d] = %c it = %c\n",i,cmd[i],*it);
        if (cmd[i] == 'R')
        {
            ++ it;
            if (it == l.end())
                it = l.begin();

        }

        else if (cmd[i] == 'L')
        {

            if (it == l.begin())
                it = l.end();
            else
                -- it;
        }
        else
        {
            if (*it == '(')
            {
//                puts("1");
                int flag = 1;
                it = l.erase(it);
                while (it != l.end() && flag != 0)
                {
                    if (*it == ')')
                        -- flag;
                    else
                        ++ flag;
                    it = l.erase(it);
                }
            }
            else if (*it == ')')
            {
//                printf("2\n");
                int flag = -1;
//                printf("cur %c\n",*it);
                it = l.erase(it);
//                printf("then it = %c\n",*it);
//                printf("then cur it = %c\n",*it);
                while (it != l.begin() && flag != 0)
                {
                    -- it;

                    if (*it == ')')
                        -- flag;
                    else
                        ++ flag;
                    it = l.erase(it);

//                    printf("flag = %d %c\n",flag,*it);
                }
            }
            if (it == l.end())
                -- it;
        }
//        for (list <char> :: iterator it2 = l.begin();it2 != l.end(); ++ it2)
//            printf("%c",*it2);
//        puts("");
    }
    for (it = l.begin();it != l.end(); ++ it)
        printf("%c",*it);

    puts("");
    return 0;
}
