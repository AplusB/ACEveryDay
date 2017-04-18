#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <ctime>
#include <iostream>

using namespace std;

map<string, int> aha;


int main()
{
	aha.clear();
	aha["Tetrahedron"] = 4;
	aha["Cube"] = 6;
	aha["Octahedron"] = 8;
	aha["Dodecahedron"] = 12;
	aha["Icosahedron"] = 20;
	int n;
	while (~scanf("%d", &n))
	{
		int ans = 0;
		
		for (int i = 0; i < n; i++)
		{
			string now;
			cin >> now;
			map<string, int>::iterator it;
			for (it = aha.begin(); it != aha.end(); ++it)
			{
				if (it->first == now)
				{
					ans += it->second;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
