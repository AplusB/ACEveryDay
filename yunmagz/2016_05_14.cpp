//坑爹之星！！！
//1001
#include <bits/stdc++.h>
using namespace std;
const int N=1010;
const int MOD=9973;
char s[100010];
int p[100010];
int find(int x)
{
    int k=MOD-2,ans=1;
    while(k)
    {
        if (k&1) ans=ans*x%MOD;
        x=x*x%MOD;
        k>>=1;
    }
    return ans;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        scanf("%s",s);
        int l=strlen(s);
        p[0]=1;
        for(int i=1;i<=l;i++){
            p[i]=((s[i-1]-28)*p[i-1])%MOD;
        }
        while(n--){
            int l,r;
            scanf("%d%d",&l,&r);
            cout<<p[r]*find(p[l-1])%MOD<<endl;
        }
    }
    return 0;
}
//1002
import java.io.*;
import java.util.*;
import java.math.BigInteger; 
public class Main {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        BigInteger[] a = new BigInteger[220];  
        a[1]=BigInteger.ONE;
        a[2]=BigInteger.ONE.add(BigInteger.ONE);
        for(int i=3;i<=200;i++)
            a[i]=a[i-1].add(a[i-2]);
        int n;
        while(in.hasNext()){
            n=in.nextInt();
            System.out.println(a[n]);
        }
    }
}
//1004
#include <bits/stdc++.h>
using namespace std;
const int N=1010;
const int MOD=1000000007;
string s;
map<string,int>mp;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        sort(s.begin(),s.end());
        cout<<mp[s]<<endl;
        mp[s]++;
    }
    return 0;
}
