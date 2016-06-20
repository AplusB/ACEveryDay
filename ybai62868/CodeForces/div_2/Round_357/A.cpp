# include <cstdio>
# include <iostream>
using namespace std;
# define MAX 123
string str[MAX];
int num1[MAX],num2[MAX];
int main(void)
{
    int n; cin>>n;
    int flag = 0;
    for ( int i = 0;i < n;i++ ){
        cin>>str[i]>>num1[i]>>num2[i];
        if ( num1[i] >= 2400 && num1[i] < num2[i] ){
            flag = 1;
        }
    }
    if ( flag ) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}
