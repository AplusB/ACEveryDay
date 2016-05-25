#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <climits>
#include <ctime>
#define LL long long
using namespace std;
const int N = 1000005;

bool isprime[N];
int primelist[100000];
int suffix[N];

void Eular()
{
    memset(isprime,true,sizeof(isprime));
    int primecount = 0;
    isprime[1] = false;
    for(int i = 2; i <= N; i++)
    {
        if(isprime[i])
        {
            primecount++;
            primelist[primecount] = i;
        }
        for(int j = 1; j <= primecount; j++)
        {
            if( i * primelist[j] > N) break;
            isprime[i*primelist[j]] = false;
            if(i % primelist[j] == 0) break;
        }
    }
    suffix[0] = 0;
    for(int i = 1; i <= N; i++)
    {
        suffix[i] = suffix[i-1] + (isprime[i] == true?1:0);
    }
}


int main(void)
{
    int n;
    Eular();
    scanf("%d",&n);
    printf("%d\n",suffix[n]);
    return 0;
}
