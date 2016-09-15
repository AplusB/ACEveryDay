# include <cstdio>
# include <iostream>
# include <string>
using namespace std;
int main(void)
{
	string str; cin>>str;
	int len = str.size();
	if ( len&1 ) {
		cout<<-1<<endl;
	} 
	else{
		int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
		for ( int i = 0;i < len;i++ ) {
			if ( str[i]=='L' ) cnt1++;
			if ( str[i]=='R' ) cnt2++;
			if ( str[i]=='U' ) cnt3++;
			if ( str[i]=='D' ) cnt4++; 
		}
		int res = (abs(cnt1-cnt2)+abs(cnt3-cnt4))/2;
		cout<<res<<endl;
	}

	return 0;
}
