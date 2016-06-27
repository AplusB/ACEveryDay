#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> P;
stack < P > st;
long long l[30050];
long long arr[30050];
long long r[30050];
int main()
{
    long long T;
    long long _case = 1;
    scanf("%lld", &T);
    while(T--)
    {
        while(st.size())
            st.pop();
        long long n;
        scanf("%lld", &n);
        for(long long i = 1; i <= n; i++)
        {
            scanf("%lld", &arr[i]);
            l[i] = r[i] = i;
        }
        arr[n + 1] = INT_MIN;
        for(long long i = 1; i <= n + 1; i++)
        {
            if(st.size() == 0 || arr[i] >= st.top().first)
                st.push(make_pair(arr[i], i));
            else
            {
                while(st.size() && arr[i] < st.top().first)
                {
                    l[i] = l[st.top().second];
                    r[st.top().second] = i - 1;
                    st.pop();
                }
                st.push(make_pair(arr[i], i));
            }
        }
        long long ans = 0;
        for(long long i = 1; i <= n; i++)
            ans = max(ans, arr[i] * (r[i] - l[i] + 1));
        printf("Case %lld: %lld\n", _case++, ans);
    }
    return 0;
}
