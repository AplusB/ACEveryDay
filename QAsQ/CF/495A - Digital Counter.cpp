#include<bits/stdc++.h>
using namespace std;

int wei[10] = {2,7,2,3,3,4,2,5,1,2};

int main(){
    int x;
    cin>>x;
    cout<<wei[x%10] * wei[x/10]<<endl;
}
