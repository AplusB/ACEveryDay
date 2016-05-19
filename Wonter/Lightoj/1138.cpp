
#include <bits/stdc++.h>
using namespace std;

int n;
bool check(int mid)
{
    int cnt = 0;
    while(mid)
    {
        cnt += mid / 5;
        mid /= 5;
    }
    if(cnt >= n)
        return true;
    return false;
}
int main()
{
    int T, _case = 1;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        int left = 5, right = 2100000000;
        while(left < right)
        {
            int mid = left + ((right - left) >> 1);
            if(check(mid))
                right = mid;
            else
                left = mid + 1;
        }
        int t = left, cnt = 0;
        while(t)
        {
            cnt += t / 5;
            t /= 5;
        }
        if(cnt != n)
            printf("Case %d: impossible\n", _case++);
        else
            printf("Case %d: %d\n", _case++, left);
    }
    return 0;
}
