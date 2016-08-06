#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <iostream>
using namespace std;

char a[105], b[105];
int n;

char change(char c){
	switch(c){
		case 'p':
		case 'b': return 'p';
		case 'i':
		case 'e': return 'i';
		default: return c;
	}
}

int main()
{
	freopen("in.txt", "r",stdin);
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		getchar();
		scanf("%s", a);
		scanf("%s", b);
		bool ans = 1;
		int j = 0;
		for(j=0; a[j] != '\0' && b[j] != '\0'; j++){
			if(isupper(a[j])) a[j] = tolower(a[j]);
			if(isupper(b[j])) b[j] = tolower(b[j]);
			a[j] = change(a[j]);
			b[j] = change(b[j]);
			if(a[j] != b[j]){
				ans = 0;
				break;
			}
		}
		if(!(a[j] == '\0' && b[j] == '\0')) ans = 0;
		printf("%s\n", ans ? "Yes" : "No");
	}
	return 0;
}
