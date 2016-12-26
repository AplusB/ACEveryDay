# include <cstdio>
# include <iostream>
# include <string>
# include <stack>
# include <cstring>
using namespace std;
stack<string>set_back;
stack<string>set_forward;
void work()
{
	string cur = "http://www.lightoj.com/";
	string str;
	while ( cin>>str ) {
		if ( str[0]=='Q' ) {
			break;
		}
		if ( str[0]=='V' ) {
			string s; cin>>s;
			cout<<s<<endl;
			set_back.push(s);
			while ( !set_forward.empty() ) {
				set_forward.pop();
			}
			cur = s;
		}
		if ( str[0]=='B' ) {
			if ( set_back.empty() ) cout<<"Ignored"<<endl;
			else {
				set_forward.push(cur);
				cur = set_back.top();
				set_back.pop();
				cout<<cur.c_str()<<endl;
			}
		}
		if ( str[0]=='F' ) {
			if ( set_forward.empty() ) cout<<"Ignored"<<endl;
			else {
				set_back.push(cur);
				cur = set_forward.top();
				set_forward.pop();
				cout<<cur.c_str()<<endl;
			}
		}
	}
}
int main(void)
{
	int t; cin>>t;
	int icase = 1;
	while ( t-- ) {
		printf("Case %d:\n",icase++);
		work();
		while ( !set_forward.empty() ) {
			set_forward.pop();
		}
		while ( !set_back.empty() ) {
			set_back.pop();
		}
	}
	return 0;
}
