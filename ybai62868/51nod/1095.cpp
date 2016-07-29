# include <cstdio>
# include <iostream>
# include <map>
# include <algorithm>
# include <string>
# include <cstring>
using namespace std;
char str[23];
map<string,int>mp1,mp2;
int main(void)
{
	int n; cin>>n;
	for ( int i = 0;i < n;i++ ) {
		cin>>str;
		int len = strlen(str);
		mp1[str]++;
		sort(str,str+len);
		mp2[str]++;
	}
	getchar();
	int q; cin>>q;
	for ( int i = 0;i < q;i++ ) {
		cin>>str;
		int len = strlen(str);
		int temp1 = mp1[str];
		sort(str,str+len);
		int temp2 = mp2[str];
		cout<<temp2-temp1<<endl;
	}
	


	return 0;
}
