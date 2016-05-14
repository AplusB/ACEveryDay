#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<bitset>
#include<math.h>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N=1000010;
const int MAX=1000000100;
const int mod=100000000;
const int MOD1=1000000007;
const int MOD2=1000000009;
const double EPS=0.00000001;
typedef long long ll;
const ll MOD=998244353;
const int INF=1000000010;
typedef double db;
typedef unsigned long long ull;
char s[35],t[35];
struct trie{
    int g,k,w,siz,d[35],val[N],tr[N][26];
    void trie_clear() {
        memset(val,0,sizeof(val));
        siz=0;memset(tr,0,sizeof(tr));
    }
    void trie_insert(char *ch) {
        w=0;val[0]++;
        while (*ch!='\0'&&tr[w][*ch-'a']) { w=tr[w][*ch-'a'];val[w]++;ch++; }
        while (*ch!='\0') { tr[w][*ch-'a']=++siz;w=siz;val[w]++;ch++; }
    }
    void trie_delete(char *ch) {
        k=w=0;d[k]=0;
        while (*ch!='\0'&&tr[w][*ch-'a']) { w=tr[w][*ch-'a'];d[++k]=w;ch++; }
        if (*ch!='\0') return ;
        g=val[d[k]];val[0]-=g;*ch--;
        for (int i=k;i;i--) {
            val[d[i]]-=g;
            if (!val[d[i]]) tr[d[i-1]][*ch-'a']=0;
            ch--;
        }
    }
    int find_s(char *ch) {
        w=0;
        while (*ch!='\0'&&tr[w][*ch-'a']) { w=tr[w][*ch-'a'];ch++; }
        if (*ch=='\0') return 1;
        return 0;
    }
}K;
int main()
{
    int i,n;
    scanf("%d", &n);
    K.trie_clear();
    for (i=1;i<=n;i++) {
        scanf("%s%s", s, t);
        if (s[0]=='i') K.trie_insert(t);
        else if (s[0]=='d') K.trie_delete(t);
            else {
                if (K.find_s(t)) printf("Yes\n");
                else printf("No\n");
            }
    }
    return 0;
}
