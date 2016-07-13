//578A - A Problem about Polyline
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PII pair<int,int>
map<string, vector<int> > p;
char s[15];
int main()
{
	int n,m;
	cin>>n>>m;
	if(m>n) puts("-1");
	else printf("%.9lf\n",(n+m)/2.0/((n+m)/(2*m)));
    return 0;
}
