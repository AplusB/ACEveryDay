#include <iostream>
#include <cstdio>
#include <bitset>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
	{
        int n, cnt = 0;
		cin >> n;
        for(int i = (1<<(n-1)); i < (1<<n); ++i)
		{
			//初始化一个bitset作为i的副本
            bitset<32> t(i);
			//t.count()为t中置为1的二进制位的个数
            cnt += t.count();
        }
        cout << cnt << endl;
    }
    return 0;
}
