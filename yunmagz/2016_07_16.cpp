//CCCC L3-1
#include <bits/stdc++.h>
using namespace std;
#define LL long long
const double eps=1e-5;
int a[10000];
void dfs(int p,int v){
  if(a[p]==-1){
    a[p]=v;
    return;
  }
  if(v>a[p]) dfs(p<<1,v);
  else dfs((p<<1)+1,v);
}
int main() {
  int n,x;
  cin>>n;
  memset(a,-1,sizeof a);
  for(int i=0;i<n;i++){
    cin>>x;
    dfs(1,x);
  }
  int cnt=0;
  int i=1;
  for(;cnt<n;i++){
    if(a[i]!=-1){
      cnt++;
      printf("%d%c",a[i],cnt==n?'\n':' ');
    }
  }
  if(i==n+1) puts("YES");
  else puts("NO");
  return 0;
}
