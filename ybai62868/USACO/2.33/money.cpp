/*
    ID:wikioi_bai
    LANG:C++
    PROG:money
*/

# include <iostream>
# include <fstream>
# include <cstring>
using namespace std;
 
int main(void)
{
    ifstream fin("money.in");
    ofstream fout("money.out");
 
    int v,n,p;
    long long dp[10001];
    fin>>v>>n;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for (int i=1;i<=v;i++)
    {
        fin>>p;
        for (int j=p;j<=n;j++)
            dp[j]+=dp[j-p];
    }
 
    fout<<dp[n]<<endl;
    return 0;
}
