#include <stdio.h>
#include <string.h>

const int N = 8800;
int num[N],cnt[N << 1];

void solve()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i = 0; i < n; ++i)
        {
            scanf("%d",&num[i]);
        }
        for(int i = 0; i < n; ++i)
        {
            if(i) putchar(' ');
            memset(cnt,0,sizeof cnt);
            int temp = 0,ans = 0;
            cnt[0] = 1;
            for(int j = i + 1; j < n; ++j)
            {
                if(num[j] > num[i]) temp++;
                else temp--;
                if(temp >= 0) cnt[temp]++;
                else cnt[-temp + n]++;
            }
            ans += cnt[0];
            temp = 0;
            for(int j = i - 1; j >= 0; --j)
            {
                if(num[j] > num[i]) temp++;
                else temp--;
                if(temp > 0) ans += cnt[temp + n];
                else ans += cnt[-temp];
            }
            printf("%d",ans);
        }
        puts("");
    }
}

int main()
{
    solve();
    return 0;
}
