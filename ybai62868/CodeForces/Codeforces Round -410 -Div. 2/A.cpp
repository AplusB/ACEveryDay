# include <cstdio>
# include <iostream>
# include <string>
# include <cstring>
using namespace std;
int main(void)
{
	string str; cin>>str;
	int len = str.size();
	int res = 0;
	for ( int i = 0;;i++ ) {
		if ( i >= len-i-1 ) break; 
		if ( str[i]!=str[len-i-1] ) res++;
	}
	if ( len&1 ) {
		if ( res==0 || res==1 ) puts("YES");
		else puts("NO");
	}
	else {
		if ( res==0||res > 1 ) puts("NO");
		else puts("YES");
	}
	return 0;
}
