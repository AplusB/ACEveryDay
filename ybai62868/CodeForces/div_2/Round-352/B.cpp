# include <cstdio>
# include <iostream>
# include <string>
# include <cstring>
using namespace std;
string str;
int main(void)
{
    cin>>str;
    int len = str.size();
    int posdian = 0;
    int index = 0;
    int pose = 0;
    for ( int i = 0;i < len;i++ ) {
        if ( str[i]=='.' ) posdian = i;
        if ( str[i]=='e' ) {
            pose = i;
            while ( i+1!=len ) {
                index = index*10+str[i+1]-'0';
                i++;
            }
        }
    }
    int cnt = 0;
    if ( index == 0 ) {
         if ( pose-1==posdian+1&&str[pose-1]=='0'&&index==0 ){
                cout<<str[0]<<endl;
                return 0;
         }
        for ( int i = 0;i < pose;i++ ) {
            cout<<str[i];
        }
        cout<<endl;
        return 0;
    }
    else {
        if ( str[0]=='0' ) {
            if ( pose-1==posdian+1&&str[pose-1]=='0'&&index==0 ){
                cout<<0<<endl;
                return 0;
            }
            if ( index+posdian >= pose-1 ) {
                for ( int i = 2;i < pose;i++ ) cout<<str[i];
                cnt = index+posdian-(pose-1);
                for ( int i = 0;i < cnt;i++ ) cout<<0;
                cout<<endl;
                return 0;
            }
            else {
                for ( int i = 1;i < pose;i++ ) {
                    if ( str[i]=='.' ) continue;
                    cout<<str[i];
                    if ( i==posdian+index&&i!=pose-1 )  cout<<'.';
                }
            }
        }
        else {
            if ( posdian+index >= pose-1 ) {
            cnt = (posdian+index)-pose+1;
           // cout<<" cnt = " <<cnt<<endl;
            for ( int i = 0;i < pose;i++ ) {
                if ( str[i]=='.' ) continue;
                cout<<str[i];
            }
            for ( int i = 0;i < cnt;i++ ) cout<<0;
            cout<<endl;
            return 0;
        }
        else {
            for ( int i = 0;i < pose;i++ ) {
                if ( str[i]=='.' ) continue;
                cout<<str[i];
                if ( i==posdian+index&&i!=pose-1 ) {
                    cout<<'.';
                }
            }
            cout<<endl;
            return 0;
        }
        }
    }
    return 0;
}
