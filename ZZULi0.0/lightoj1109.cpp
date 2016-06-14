#include <bits/stdc++.h>
#define LL long long
#define PI acos(-1.0)
using namespace std;

struct nodes
{
    int th,nums;
    bool operator <(const nodes &b) const
    {
        if(nums == b.nums)
        return th > b.th;
        else return nums < b.nums;
    }
}lists[2000];

void init()
{
    for(int i = 1; i <= 1000; i++)
        lists[i].th = i,lists[i].nums = 0;

    for(int i = 1; i <= 1000; i++)
    {
        for(int j = i+i; j <= 1000; j += i)
            lists[j].nums++;
    }
    sort(lists+1,lists+1001);
}
void solve()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",lists[n].th);
}

int main(void)
{
    int t,cnt = 0;
    init();
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d: ",++cnt);
        solve();
    }
    return 0;
}
