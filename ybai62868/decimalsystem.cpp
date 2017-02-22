# include <cstdio>
# include <iostream>
# include <cmath>
# include <cstring>
# include <string>
using namespace std;
int main(void)
{
	int n;
	while ( scanf("%d",&n)!=EOF ) {
		int res = 0;
		getchar();
		while ( n-- ) {
			string str; cin>>str;
		int pos1 = 0, pos2 = 0;
		for ( int i = 0;i < str.size();i++ ) {
			if ( str[i]=='(' ) {
				pos1 = i+1;
				for ( int j = i;j < str.size();j++ ) {
					if ( str[j]==')' ) {
						pos2 = j-1;
						break;
					}
				}
			}
		}
		if ( pos2-pos1 == 1 ) {
			int temp = 0;
			for ( int i = 0;i < pos1-1;i++ ) {
				temp+=(str[i]-'0');
				temp*=10;
			}
			temp/=10;
			res+=temp;
		}
		else {
			int temp = 0;
			int index = 0;
			int tt = str[pos1]-'0';
			// cout<<"tt = "<<tt<<endl;
			for ( int i = pos1-2;i>=0;i-- ) {
				 temp += pow(tt,index)*(str[i]-'0');
				 index++;
			}
			res+=temp;
		}

		}
		printf("%d\n",res);
	}

	return 0;
}
