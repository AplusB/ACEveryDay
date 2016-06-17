# include <stdio.h>
# include <string.h>

//恭祝胖巨和雨巨幸福的走到婚姻的殿堂
int tab[300] ;
char str[100] ;
int max_tab[300] ;


int main ()
{
    int i, j ;
    int max_row ;
    while (1)
    {
    max_row = 0 ;
    memset (tab, 0, sizeof(tab)) ;
    for (i = 0 ; i < 4 ; i++)
    {
        if (gets (str) == NULL) return 0 ;
        for (j = 0 ; str[j] ; j++)
        {
            if (str[j] >= 'A' && str[j] <= 'Z'){
                tab[str[j]]++ ;
                if (tab[str[j]] > max_row) max_row = tab[str[j]] ;
            }
        }
    }
    
    max_tab['Z'] = tab['Z'] ;
    
    for (i = 'Z'-1 ; i >= 'A'; i--)
        if (tab[i]>max_tab[i+1])
            max_tab[i] = tab[i] ;
        else max_tab[i] = max_tab[i+1] ;


    for (i = 0 ; i < max_row ; i++)
    {
        for (j = 'A' ; j <= 'Z' ; j++)
        {
            if (j != 'A') putchar (' ') ;
            if (i < max_row - tab[j]) putchar (' ') ;
            else putchar ('*') ;
            if (i < max_row - max_tab[j+1]) break ;
        }
        printf ("\n") ;
    }
    putchar ('A') ;
    for (j = 'B' ; j<='Z' ; j++) printf (" %c", j) ;
    printf ("\n") ;
    }
    return 0 ;
}
