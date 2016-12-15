#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn=1e7+9;
const int inf=2e9+9;

char num[maxn];

int main()
{
    int cas=1;
    while(~scanf("%s",num))
    {
        printf("Case #%d: ",cas++);
        ll x1,x2;
        x1=x2=0;
        int len=strlen(num);
        for(int i=0;i<len;i++)
        {
            ll tmp=num[i]-'0';
            x1=x1*10+tmp;
            x2=x2*10+tmp;
            x1%=73;
            x2%=137;
        }
        if(x1==0 && x2==0)
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;
}
