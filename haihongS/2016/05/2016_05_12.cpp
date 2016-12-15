#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn=1e5+9;
const int inf=1e9+9;

struct II
{
    int h,a;
}num[maxn];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++) scanf("%d%d",&num[i].h,&num[i].a);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                if(num[i].h==num[j].a)
                    cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}

