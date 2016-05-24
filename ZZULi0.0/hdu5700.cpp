#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define LL long long
using namespace std;
const int N =  1e5+5;
LL suffix[N];
int nums[N];
multiset<int>mset;
vector<int>vec[N];
int main(void)
{
    int n,m,k;
    while(scanf("%d %d %d",&n,&k,&m) != -1)
    {
        suffix[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&nums[i]);
            suffix[i] = suffix[i-1] + nums[i];
            vec[i].clear();
        }


        for(int i = 0; i < m; i++)
        {
            int l,r;
            scanf("%d %d",&l,&r);
            vec[l].push_back(r);
        }

        mset.clear();
        LL ans = 0;
        for(int i = 1; i <= n; i++)
        {
            mset.insert(vec[i].begin(),vec[i].end());

            while((int)mset.size() > k)
            {
                mset.erase(mset.begin());
            }
            if( (int)mset.size() == k && *mset.begin() >= i)
                ans = max(ans,suffix[*mset.begin()] - suffix[i-1]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
