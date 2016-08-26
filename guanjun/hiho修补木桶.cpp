#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#define ll long long
using namespace std;
const int N = 1e3+5;
const int inf =1e9+7;
int n,m,l,a[N],b[N],c[N];
int gg(int x){
  for(int i=0;i<l;i++){
    int tm=m;
    for(int j=0;j<n;j++)c[j]=a[j];
    for(int j=0;j<n;j++){
      int ip=i+j;
      if(ip>=n)ip-=n;
      if(c[ip]>=x||tm==0)continue;
      int tmp=l;
      tm--;
      while(tmp--){
        c[ip]=inf;
        ip++;
        if(ip>=n)ip-=n;
        j++;
      }
      j--;
    }
    int f=0;
    for(int j=0;j<n;j++)if(c[j]<x)f++;
    if(f==0)return 1;
  }
  return 0;
}
int main()
{
    while(cin>>n>>m>>l){
      for(int i=0;i<n;i++){
        cin>>a[i];b[i]=a[i];
      }
      int l=0,r=n-1;
      sort(b,b+n);
      int ans=0;
      while(l<=r){
        int mid=(l+r)>>1;
        if(gg(b[mid])){
          l=mid+1;
          ans=b[mid];
        }
        else r=mid-1;
      }
      cout<<ans<<endl;
    }
    return 0;
}
