#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#define endl '\n'

using namespace std;

const int MAXN = 105;

char str[MAXN];

int main()
{
	while(scanf("%s",str) == 1)
	{
		int i = 0,mark1 = -1,mark2,f1,f2,f3;
		
		f1 = 1,f2 = 1,f3 = 1;
		
		while((str[i] > '9' || str[i] <= '0'))
		{
			if(str[i] == '-')
			{
				i++;
				continue;
			}
			if(str[i] == '.')
			{
				mark1 = i;
				break;
			}
			if(str[i] == 'e')
			{
				mark2 = i;
				break;
			} 
			str[i] = -1;
			i++;
		}
		
		if(str[i] <= '9' && str[i] > '0')
		{
			f3 = 0;
		}
		
		while(str[i] != 'e')
		{
			if(str[i] == '.')mark1 = i;
			i++;
		}
		mark2 = i;
		//cout << str[mark2] << endl;
		
		//cout << mark1 << endl;
		int j;
		for(j = i - 1;j > mark1 && mark1 != -1;j--)
		{
			if(str[j] > '0' && str[j] <= '9')
			{
				f2 = 0;
				break;
			}
			str[j] = -1;
		}
		if(f2 && !f3)str[mark1] = -1;
		
		
		int l = strlen(str) - 1;
		for(i = mark2 + 1;str[i];i++)
		{
			if(str[i] == '+')
			{
				str[i] = -1;
				continue;
			}
			if(str[i] == '0' && f1)
			{
				str[i] = -1;
				continue;
			}
			if(str[i] > '0' && str[i] <= '9')
			{
				f1 = 0;
				break;
			}
		}
		
		int f4 = 0,f5 = 1;
		//cout << f3 << endl; 
		if(f3)cout << 0;
		for(i = 0;str[i];i++)
		{
			if(str[i] == -1)continue;
			if(str[i] == '.')f4 = 1;
			if(f4 && str[i] >= '0' && str[i] <= '9')f5 = 0;
			if(str[i] == 'e' && f4 && f5)cout << 0;
			cout << str[i];
		}
		if(f1)cout << 0;
		cout << '\n';
	}
	return 0;
} 
