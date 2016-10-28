//Codeforces Round #377 (Div. 2)
//A - Buy a Shovel
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=1;;i++){
        if(i*n%10==0||i*n%10==m){
            cout<<i<<endl;
            break;
        }
    }
	return 0;
}
