//从第a个位置开始左右走，并记录在不超过范围内的允许值
//反正就是模拟走一波= =
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int t[105];
int main(){
#ifdef _CONSOLE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n, a;
    cin >> n >> a;
    a--;
    for(int i = 0; i < n; ++i)
        cin >> t[i];
    int ans=0, i = 0;
    while(1){
        int x = a - i, y = a + i;
        if (x < 0)
            x = y;
        if (y >= n)
            y = x;
        if (x == y && (x < 0 || y >= n)) break;
        if (t[x] && t[y]){
            ans+=2;
            if (x == y)
                ans--;
        }
        i++;
    }
    cout << ans << endl;
  
    return 0;
}
