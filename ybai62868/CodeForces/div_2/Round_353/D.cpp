# include <cstdio>
# include <iostream>
# include <map>
# include <algorithm>
using namespace std;
int a[100004];
int main(void)
{
	int n; cin>>n;
	for (int i = 0; i<n; i++) cin>>a[i];
	map<int, int> mp;
	mp[INT_MAX] = mp[a[0]] = 0;
	for (int i = 1; i<n; i++)
	{
		map<int, int>::iterator it = mp.lower_bound(a[i]);
		int id_fa = it->second;
		int fa = a[id_fa];
		printf("%d%c", fa, " \n"[i==n-1]);
		it->second = i;
		mp[a[i]] = i;
	}
	return 0;
}
