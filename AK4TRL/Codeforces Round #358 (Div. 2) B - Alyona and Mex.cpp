//接收一个数字n，接下来是a1, a2, ..., an ，你只能对每个a进行减法操作，输出这n个数中1~最大值+1中缺少的最小数字，让这个数尽可能大。
#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++)
    scanf("%d", a + i);
  sort(a + 1, a + n + 1);
  int p = 1;
  for (int i = 1; i <= n; i ++) {
    if (a[i] >= p) p ++;
  }
  cout << p << endl;
  
  return 0;
}
