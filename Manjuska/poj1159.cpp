#include<iostream>
#include<cstring>
using namespace std;
#define Max 5005
char str1[Max], str2[Max];
int maxlen[2][Max];
int main()
{
	int n, i, j;
	while (cin >> n)
	{
		for (i = 1; i <= n; i++)
			cin >> str1[i];
		str1[n + 1] = '\0';
		for (i = 1; i <= n; i++)
			str2[i] = str1[n - i + 1];
		memset(maxlen, 0, sizeof(maxlen));
		int e = 0;
		for (i = 1; i <= n; i++)
		{
			e = 1 - e;
			for (j = 0; j <= n; j++)
			{
				if (str1[i] == str2[j])
					maxlen[e][j] = maxlen[1 - e][j - 1] + 1;
				else {
					int len1 = maxlen[e][j - 1];
					int len2 = maxlen[1 - e][j];
					if (len1>len2) maxlen[e][j] = len1;
					else maxlen[e][j] = len2;
				}
			}
		}
		cout << n - maxlen[e][n] << endl;
	}
	return 0;
}
