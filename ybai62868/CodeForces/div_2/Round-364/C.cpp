# include <cstdio>
# include <iostream>
# include <cstring>
# include <string>
# define MAX 112345
using namespace std;
# define inf 99999999
int cnt[MAX];
string str;
int main(void)
{
	int n; cin>>n;
	cin>>str;
	int len = 0, ans = 0;
	int l = 0, sum = 0;
	for ( int i = 0;i < n;i++ ){
		len++;
		if ( !cnt[str[i]-'A'] ){
			ans = len;
		}
		cnt[str[i]-'A']++;
		while ( cnt[str[l]-'A'] >= 2 ){
			cnt[str[l]-'A']--;
			l++;
			len--;
		}
		ans = min(ans,len);
	}
	cout<<ans<<endl;
	return 0;
}
