/*
    ID:wikioi_bai
    LANG:C++
    PROG:prefix
*/
#include <fstream>
#include <string.h>
#include <map>
using namespace std;
map<int,int> M;
char a[200001];
bool f[200001];
int main()
{
    ifstream cin("prefix.in");
    ofstream cout("prefix.out");
    char a1[15]; long long len,q,tot;
    while(cin>>a1 && strcmp(a1,".")!=0)
    {
        len=strlen(a1);
        q=0;
        for(int i=len-1;i>=0;i--)
            q=q*171+a1[i];
        M[q]=1;
    }
    char c;
    tot=0;
    f[0]=1;
    while(cin>>c)
    {
        if(!(c>='A' && c<='Z')) continue;
        a[++tot]=c;
        q=0;
        for(int i=1;i<=10;i++)
        {
            if(tot-i<0) break;
            q=q*171+a[tot-i+1];
            if(M.find(q)!=M.end() && f[tot-i])
            {
                f[tot]=1;
                break;
            }
        }
    }
    for(int i=tot;i>=0;i--)
    {
        if(f[i] || i==0)
        { 
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
