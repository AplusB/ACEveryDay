#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <functional>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 9;
const ll inf = 1e9 + 9;

int isprime(int x);

int main()
{
	//std::ios::sync_with_stdio(false);
	int n;
	while (~scanf("%d", &n) && n)
	{
		int cnt = 0;
		for (int i = 2; i <= n / 2; i++)
		{
			if (isprime(i) && isprime(n - i) && i!=n-i)
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;

}

int isprime(int x)
{
	if (x == 1 || x==0) return 0;
	for (int i = 2; i*i <= x; i++)
	{
		if (x%i == 0) return 0;
	}
	return 1;
}
