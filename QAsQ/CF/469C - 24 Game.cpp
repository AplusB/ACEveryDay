#include<bits/stdc++.h>
using namespace std;
 
string ans4[3]={"1 + 2 = 3","3 + 3 = 6","6 * 4 = 24"};
string ans5[4]={"3 - 2 = 1","5 + 1 = 6","6 * 4 = 24","1 * 24 = 24"};
string ans6[5]={"2 + 3 = 5","5 - 5 = 0","1 * 0 = 0","4 * 6 = 24","24 + 0 = 24"};
int main(){
    int n;
    cin>>n;
    if(n<=3){
        puts("NO");
    }
    else{
        puts("YES");
        if(n == 4){
            for(int i=0;i<3;i++) cout<<ans4[i]<<endl; 
        }else if(n == 5){
            for(int i=0;i<4;i++) cout<<ans5[i]<<endl; 
        }else{
            for(int i=0;i<4;i++) cout<<ans6[i]<<endl;
            for(int i=7;i<=n;i++) cout<<i<<" * 0 = 0"<<endl; 
            cout<<ans6[4]<<endl;
        }
    }
    return 0;
}
