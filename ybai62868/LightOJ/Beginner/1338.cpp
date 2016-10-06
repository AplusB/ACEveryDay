# include <cstdio>
# include <iostream>
# include <string>
# include <cstring>
using namespace std;
char str1[12345],str2[12345];
int cnt1[33],cnt2[33];
int main(void)
{
    int icase = 1;
    int t; cin>>t;
    getchar();
    while ( t-- ) {
        gets(str1);
        gets(str2);
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        for ( int i = 0;i < len1;i++ ) {
            if ( str1[i]>='A'&&str1[i]<='Z' ) {
                str1[i] += 32;
            }
            cnt1[str1[i]-'a']++;
        }
        for ( int i = 0;i < len2;i++ ) {
            if ( str2[i]>='A'&&str2[i]<='Z' ) {
                str2[i] += 32;
            }
            cnt2[str2[i]-'a']++;
        }
        /*for ( int i = 0;i < 32;i++ ) {
            cout<<cnt1[i]<<" ";
        }
        cout<<endl;
        for ( int i = 0;i < 32;i++ ) {
            cout<<cnt2[i]<<" ";
        }
        cout<<endl;
        */
        int flag = 0;
        for ( int i = 0;i < 32;i++ ) {
            if ( cnt1[i] < cnt2[i] ) {
                flag = 1;
                break;
            }
        }
        printf("Case %d: ",icase++);
        if ( !flag ) puts("Yes");
        else puts("No");
        memset(cnt1,0,sizeof(cnt1));
        memset(cnt2,0,sizeof(cnt2));
    }


    return 0;
}
