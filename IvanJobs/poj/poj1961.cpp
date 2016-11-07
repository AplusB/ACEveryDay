// using c++11

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
#include <utility>
#include <string>

using namespace std;


#define REP(i, n) for(int _n = n, i = 0; i < _n; i++)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define RFOR(i, b, a) for (int i = (b), _b = (a); i >= _b; i--)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define Abs(x) ((x) > 0 ? (x) :(-(x)))
#define L(fmt, ...) do {if(true) printf(fmt"\n", ##__VA_ARGS__);} while(false)

//P is input argument.
//res is output argument.
//take P and return res, res[j] means, res[0...j]'s max-prefix-suffix len.
void maxlen_prefix_suffix(string P, deque<int>& res) {
    int L = int(P.size());
    P = '.' + P; // make P starting from index 1.
    
    //reset vector res
    res.clear();
    REP(i, L + 1) { // why L + 1, because we want index starts from 1;
        res.push_back(0);
    }

    int a = 0;
    FOR(b, 2, L) {
        while (a > 0 && P[a + 1] != P[b]) {
            a = res[a];
        }

        if (P[a + 1] == P[b]) {
            a += 1;
        }

        res[b] = a;
    }

    //remove heading element, reverse index starting from 1, make it start from 0.
    res.pop_front();
}
// T is TEXT.
// P is PATTERN.
// if we cannot find any match index, return -1.
// or return the first match index.
int kmp(string T, string P) {
    // calculate KMP NEXT Array.
    deque<int> NEXT;
    maxlen_prefix_suffix(P, NEXT);

    int LT = int(T.size());
    int LP = int(P.size());

    int i = 0;
    int j = 0;

    while (i < LT) {
        int cand = i;
        while (j < LP && i < LT && T[i] == P[j]) {
            i++;
            j++;
        }
        if (j >= LP) {
            return cand;
        } else {
            if (j - 1 >= 0) {
                j = NEXT[j - 1];
            } else {
                i++;
            }
        }
    }
    return -1;
}

// res: result vector for holding indexes.
void kmp_multi(string T, string P, vector<int>& res) {
    // reset result vector
    res.clear();
    // calculate NEXT array
    deque<int> NEXT;
    maxlen_prefix_suffix(P, NEXT);

    int LT = T.size();
    int LP = P.size();

    int i = 0;
    int j = 0;

    while (i < LT) {
        //printf("i:%d\n", i);
        int cand = i;
        while (j < LP and i < LT and T[i] == P[j]) {
            i++;
            j++;
        }
        if (j >= LP) {
            //printf("%d\n", cand);
            res.push_back(cand);
            j = NEXT[LP - 1];
        } else {
            if (j - 1 >= 0) {
                j = NEXT[j - 1];
            } else {
                i++;
            }
        }
    }

}

int main() {
    
    return 0;
}
