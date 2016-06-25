#include <bits/stdc++.h>
using namespace std;

int a[100050];
int n;
bool Check(int mid)
{
    int pre = 0;
    for(int i = 1;i <= n;++i)
    {
        if(a[i] - pre > mid)
            return false;
        if(a[i] - pre == mid)
            --mid;
        pre = a[i];
    }
    return true;
}
int main()
{
    int T, _case = 1;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 1;i <= n;++i)
            scanf("%d", &a[i]);
        int left = 0, right = 1000000000;
        while(left < right)
        {
            int mid = left + ((right - mid) >> 1);
            if(Check(mid))
                right = mid;
            else
                left = mid + 1;
        }
        printf("Case %d: %d\n", _case++, left);
    }
    return 0;
}
