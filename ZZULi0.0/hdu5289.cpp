#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#define LL long long
using namespace std;
const int N = 1e5+5;
int nums[N];
void solve()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 0; i < n; i++)
        scanf("%d",&nums[i]);

    deque<int>Ma,Mi;
    while(!Ma.empty()) Ma.pop_back();
    while(!Mi.empty()) Mi.pop_back();
    LL ans = 0;
    int i,j;
    for(i = 0, j = 0; i < n; i++)
    {
        while(!Ma.empty() && nums[i] > Ma.back()) Ma.pop_back();
        Ma.push_back(nums[i]);

        while(!Mi.empty() && nums[i] < Mi.back()) Mi.pop_back();
        Mi.push_back(nums[i]);

        while(!Ma.empty() && !Mi.empty() && (Ma.front() - Mi.front() >= k) )
        {
            ans += (i - j);
            if(Ma.front() == nums[j]) Ma.pop_front();
            if(Mi.front() == nums[j]) Mi.pop_front();
            j++;
        }

    }
    while(j < n)
    {
        ans += (i - j);
        j++;
    }
    printf("%lld\n",ans);
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        solve();
    }
    return 0;
}
