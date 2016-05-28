//n个数，最大合成数为m
//现在求出 除了给出的n个数外，其他能合成m的数有多少个，分别为哪几个
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int n, m;
int a[100005];
vector<int> ans;
set<int> S;
int main(){
#ifdef _CONSOLE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		S.insert(a[i]);
	}
	
	for(int i = 1; m ; i++){
		if(S.count(i))
		    continue;
		
		if(m >= i)
		    ans.push_back(i), m -= i;
		else break;
	}
	
	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); ++i)
	    printf("%d ", ans[i]);

	return 0;
}
