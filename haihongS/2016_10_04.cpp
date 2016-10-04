#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=2e6+10;
const int inf=2e9+9;
const ll mod=1e9+7;
const double eps=1e-9;

int main()
{
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        printf("Case #%d: ",cas++);
        int flag=0;
        if(2*k+1<=n)
            printf("%d",n),flag=1;
        for(int i=n-1;i>=2*k+1;i--)
            printf(" %d",i);
        for(int i=1;i<=k;i++)
        {
            if(flag==0)
            {
                flag=1;printf("%d",i);continue;
            }
            printf(" %d",i);
        }
        for(int i=2*k;i>=k+1;i--)
            printf(" %d",i);
        printf("\n");

    }
    return 0;
}
