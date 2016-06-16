#include <bits/stdc++.h>
#define LL long long
#define PI acos(-1.0)
using namespace std;
const int N = 3e4+5;

int mark1[N],mark2[N];

void work1(int n, int mark[],int num[])
{
    stack<int>ST;
    for(int i = 0; i < n; i ++)
    {
        while(!ST.empty() &&num[ST.top()] > num[i])
        {
            mark[(int)ST.top()] = i-1;
            ST.pop();
        }
        ST.push(i);
    }
    while(!ST.empty())
    {
        mark[(int)ST.top()] = n-1;
        ST.pop();
    }
}
void work2(int n, int mark[],int num[])
{
    stack<int>ST;
    for(int i = n-1; i >= 0; i --)
    {
        while(!ST.empty() &&num[ST.top()] > num[i])
        {
            mark[(int)ST.top()] = i+1;
            ST.pop();
        }
        ST.push(i);
    }
    while(!ST.empty())
    {
        mark[(int)ST.top()] = 0;
        ST.pop();
    }
}

void solve()
{
    int n;
    int nums[N];
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        scanf("%d",&nums[i]);
    work1(n,mark1,nums);
    work2(n,mark2,nums);
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, nums[i] * (mark1[i] - mark2[i]+1));
    printf("%d\n",ans);
}


int main(void)
{
    int t,cnt = 0;

    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d: ",++cnt);
        solve();
    }
    return 0;
}
