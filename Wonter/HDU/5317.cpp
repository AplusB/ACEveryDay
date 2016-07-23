#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

bool isPrime[1000001];
int cnt[1000001];
int sum[1000001][8];
void Init()
{
    fill(isPrime, isPrime + 1000001, true);
    for(int i = 2; i <= 1000000; ++i)
    {
        if(!isPrime[i])
            continue;
        ++cnt[i];
        for(int j = i + i; j <= 1000000; j += i)
        {
            isPrime[j] = false;
            ++cnt[j];
        }
    }
    for(int i = 2; i <= 1000000; ++i)
        for(int j = 1; j <= 7; ++j)
            sum[i][j] = sum[i - 1][j] + (cnt[i] == j ? 1 : 0);
}
int main()
{
    Init();
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        int cnt[8] = {0};
        for(int i = 1; i <= 7; ++i)
            cnt[i] = sum[r][i] - sum[l - 1][i];
        if(cnt[7] >= 2)
            printf("7\n");
        else if(cnt[6] >= 2)
            printf("6\n");
        else if(cnt[5] >= 2)
            printf("5\n");
        else if(cnt[4] >= 2)
            printf("4\n");
        else if(cnt[3] >= 2 || (cnt[3] && cnt[6]))
            printf("3\n");
        else if(cnt[2] >= 2 ||
                (cnt[2] && cnt[4]) ||
                (cnt[2] && cnt[6]) ||
                (cnt[4] && cnt[6]))
            printf("2\n");
        else
            printf("1\n");
    }
    return 0;
}
