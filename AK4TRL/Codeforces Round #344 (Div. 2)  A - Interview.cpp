//暴力或
#include<cstdio>
#include<iostream>
using namespace std;
int main(){
#ifdef _CONSOLE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n;
    scanf("%d",&n);
    long long a = 0, b = 0, c;
    for(int i = 0; i < n; ++i)
        cin >> c, a |= c;
        
    for(int i = 0; i < n; ++i)
        cin >> c, b |= c;
        
    cout << a + b << endl;
    
    return 0;
}
