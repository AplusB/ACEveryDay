//Codeforces Round #377 (Div. 2)
//D - Exams
#include <bits/stdc++.h>
using namespace std ;

typedef pair < int , int > pii ;
typedef long long LL ;

#define clr( a , x ) memset ( a , x , sizeof a )

const int MAXN = 100005 ;

int n , m ;
int a[MAXN] , b[MAXN] , vis[MAXN] , p[MAXN] ;

bool check ( int t ) {
	int num = 0 ;
	clr ( vis , 0 ) ;
	clr ( b , 0 ) ;
	for ( int i = t ; i >= 1 ; -- i ) {
		if ( a[i] && !vis[a[i]] ) {
			b[i] = a[i] ;
			vis[a[i]] = 1 ;
			++ num ;
		}
	}
	if ( num < m ) return 0 ;
	int cnt = 0 ;
	for ( int i = 1 ; i <= t ; ++ i ) {
		if ( !b[i] ) ++ cnt ;
		else {
			if ( p[b[i]] > cnt ) return 0 ;
			cnt -= p[b[i]] ;
		}
	}
	return 1 ;
}

void solve () {
	for ( int i = 1 ; i <= n ; ++ i ) {
		scanf ( "%d" , &a[i] ) ;
	}
	LL sum = 0 ;
	for ( int i = 1 ; i <= m ; ++ i ) {
		scanf ( "%d" , &p[i] ) ;
		sum += p[i] ;
	}
	if ( sum + m > n ) {
		printf ( "-1\n" ) ;
		return ;
	}
	int l = 1 , r = n + 1 ;
	while ( l < r ) {
		int t = l + r >> 1 ;
		if ( check ( t ) ) r = t ;
		else l = t + 1 ;
	}
	if ( r <= n ) printf ( "%d\n" , r ) ;
	else printf ( "-1\n" ) ;
}

int main () {
	while ( ~scanf ( "%d%d" , &n , &m ) ) solve () ;
	return 0 ;
}
