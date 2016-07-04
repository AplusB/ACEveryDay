#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>

#define M 100000

using namespace std;

int b[M], h[M];
int cnt;

int main()
{
	int n;
	while(cin >> n)
	{
		memset(b,0,sizeof(b));
		memset(h,0,sizeof(h));
		cnt = 0;

		for(int i=0; i<n; i++)
		{
			cin >> b[i];
			for(int j=0; j<=cnt; j++)
			{
				if(b[i] < h[j])         //有拦截系统可以拦截则更新上限值
				{
					h[j] = b[i];
					break;
				}
				else if(j == cnt)		//没有拦截系统可以拦截
				{
					h[++cnt] = b[i];	//新建拦截系统
					break;
				}
			}
			sort(h,h+cnt);         //尽可能使用上限值小的拦截
		}

		cout << cnt << endl;
	}
	return 0;
}
