# include <cstdio>
# include <iostream>
# include <cmath>
# include <algorithm>
using namespace std;
# define MAX 12345
typedef long long LL;
struct node{
	int l,r;
}a[MAX];
int cmp ( const struct node & a, const struct node & b ){
	if ( a.r == b.r ) return a.l < b.l;
	return a.r < b.r;
}
int main(void)
{
	int n; cin>>n;
	for ( int i = 0;i < n;i++ ){
		cin>>a[i].l>>a[i].r;
	}
	sort(a,a+n,cmp);
	int res = 0;
	int tmp = 1;
	for ( int i = 0;i < n;i++ ){
		tmp = 1;
		for ( int j = i+1;j < n;j++ ){
			if ( a[i].r > a[j].l ){
				tmp++;
			}
		}
		res = max(res,tmp);
	}
	cout<<res<<endl;
	return 0;
}
