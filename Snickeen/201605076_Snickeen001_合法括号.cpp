/*
//记笔记记笔记
  Problem Description
    小冬认为的合法括号序列跟别人不一样。长度为n的括号序列，
    只要任意前缀中左括号的数量减去右括号的数量小于等于a且大于等于0就是合法的。
    小冬想知道长度为n的合法序列有多少。
  Input
    输入n，a.（1<=a<=n<=1000）
  Output
    输出合法序列MOD 10^9+7
  Sample Input
    1 1
    2 2
  Sample Output
    1
    2
*/

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
typedef long long LL;
int ff[1011][1011],n,m,t,s,r,i,j,k,l;
LL ans,MOD=1e9+7;
int main()
{
    while(scanf("%I64d %I64d",&n,&m)!=EOF){
        memset(ff,0,sizeof(ff));
        ff[1][1]=1;m=min(m,n);
        for(i=2;i<=n;i++){
            ff[0][i]=ff[1][i-1]%MOD;
            for(j=1;j<m;j++){
                ff[j][i]=ff[j-1][i-1]+ff[j+1][i-1];
                ff[j][i]%=MOD;
            }
            ff[m][i]=ff[m-1][i-1]%MOD;
        }
        for(i=0;i<=m;i++)ans+=ff[i][n],ans%=MOD;
        printf("%I64d\n",ans);
    }
    return 0;
}
