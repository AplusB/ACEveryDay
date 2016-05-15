#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define endl '\n'
 
using namespace std;
 
const int MAXN = 25;
char temp[2][MAXN];
int a[2];
 
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        temp[0][0] = temp[1][0] = '\0';
             
        a[0] = 1;
        a[1] = 0;
        int index = 0;
        int flag = 0;
        scanf("%s",temp[flag]);
         
        while(scanf("%s",temp[flag ^ 1]) && strcmp(temp[flag ^ 1],"END") != 0)
        {
            if(strcmp(temp[flag ^ 1],temp[flag]) == 0)
            {
                a[index ^ 1]++;
                index = index ^ 1;
            }
            else a[index]++;
             
            flag ^= 1;
        }
         
        cout << a[0] * a[1] << endl;
    }
    return 0;
}
