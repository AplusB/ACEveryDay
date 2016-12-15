#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>

using namespace std;
typedef long long ll;
const int maxn=2e6+9;
const int inf=2e9+9;


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if(n<=m)
        {
            printf("first\n");
            continue;
        }
        if(n%(m+1)==0)
            printf("second\n");
        else
            printf("first\n");

    }
    return 0;
}
