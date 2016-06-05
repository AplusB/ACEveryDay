#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cmath>
#define N 2000010
using namespace std;
char s[2000];
long long has[2000][2000];
int f[2000][2000];
int rp = 1313;
int mod = 100000007;
struct ty
{
    long long num[2000];
}sum1[2000], sum2[2000];
int main()
{
    scanf("%s", s);
    int l = strlen(s);
    for (int i = 0;  i < l ; i++)
        has[i][i] = s[i], f[i][i] = 1;;
    for (int i = 1;  i < l ; i++)
    for (int j = 0;  j + i < l ; j++)
    {
        int k = i+j;
        has[j][k] = (has[j][k-1] * rp + s[k]) % mod;
    }
    for (int i = 2; i <= l; i++)
    for (int j = 0;  j + i-1 < l ; j++)
    {
        int k = i+j-1;
        int maxn = i / 2;
        f[j][k] = 1;
        for (int len = 1; len <= maxn; len++)
        {
            if (i % len != 0) continue;
            int time = i  /len;
           // cout <<i <<' '<<j <<' '<<k <<":"<< len << ' ' <<time <<endl;
            if (has[k-len+1][k] == has[k-len-len+1][k-len] && f[j][k-len] == time-1)
            {
                f[j][k] = time;
                break;
            }
        }
    }
//    for (int i = 0; i < l; i++)
//    {
//        for (int j = 0;j < l; j++ )
//            cout << f[i][j]<<' ';
//        cout << endl;
//    }
    for (int i = 0; i < l; i++)
    {
        sum1[i] = sum1[i-1];
        for (int j = 0; j <= i; j++)
        {
            sum1[i].num[f[j][i]]++;
        }
    }

    for (int i = l-1; i >= 0; i--)
    {
        //sum2[i] = sum2[i+1];
        for (int j = l-1; j >= i; j--)
            sum2[i].num[f[i][j]]++;
    }
    long long re = 0;
    for (int i = 0; i < l-1; i++)
        for (int j = 1; j <= l; j++)
        {
            //cout <<i <<' '<<j<<' '<< sum1[i].num[j] <<' '<< sum2[i+1].num[j]<<endl;
            re += (sum1[i].num[j] * sum2[i+1].num[j]);
        }
    cout << re << endl;
	return 0;
}
