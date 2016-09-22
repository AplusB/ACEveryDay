//SRM
//250 - Initials
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define x first
#define y second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e7+7;
const double eps=1e-9;
const int inf=0x3f3f3f3f;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}



class Initials
{
public:
    string getInitials(string name)
    {
        string a="";
        int n=SZ(name);
        if(name[0]!=' ') a.pb(name[0]);
        for(int i=0;i<n;i++){
            if(name[i]==' '&&i+1<n)
                a.pb(name[i+1]);
        }

        return a;
    }
};
//500 - RepeatStringEasy
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define x first
#define y second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e7+7;
const double eps=1e-9;
const int inf=0x3f3f3f3f;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}


#define N 55 /*×Ö·û´®³¤¶È*/

int dp[N][N];

int LCS(string s1,string s2)
{
	int i,j,len1,len2;
	len1 = SZ(s1);
	len2 = SZ(s2);
	dp[0][0] = 0;
	for(i=1;i<=len1;i++) dp[i][0] = 0;
	for(i=1;i<=len1;i++) dp[0][i] = 0;
	for (i=1;i<=len1;i++)
	{
		for (j=1;j<=len2;j++)
		{
			if(s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1]+1;
			else if(dp[i-1][j]>dp[i][j-1])
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = dp[i][j-1];
		}
	}
	return dp[len1][len2];
}
class RepeatStringEasy
{
public:
    int maximalLength(string s)
    {
        int ans=0;
        int n=SZ(s);
        for(int i=1;i<n;i++){
//            cout<<s.substr(0,i)<<" "<<s.substr(i,n-i)<<endl;
            ans=max(ans,LCS(s.substr(0,i),s.substr(i,n-i)));
        }

        return ans*2;
    }
};
