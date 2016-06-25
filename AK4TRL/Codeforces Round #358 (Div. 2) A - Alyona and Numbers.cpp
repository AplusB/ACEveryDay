//寻找1-n，1-m中的x y，使得（x+y）%5==0
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll n, m, ans = 0;
  cin >> n >> m;
  ll x = n / 5, y = m / 5;
  for (int i = 1; i <= 5; ++i)
    for (int j = 1; j <= 5; ++j)
      if ((i + j) % 5 == 0)
        ans += (x + (n % 5 >= i)) * (y + (m % 5 >= j));
        
  cout << ans << endl;
  
  return 0;
}
