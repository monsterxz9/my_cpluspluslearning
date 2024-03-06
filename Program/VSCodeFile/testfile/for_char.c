/* for_char.c */
#include <stdio.h>
int main(void)
{
    char chr;
    for (  chr = 'a'; chr <= 'z'; chr++)
    {
        printf("The askii value for %c is %d\n",chr,chr);
    }
    char a='c';
    printf("%c",a);
    
    return 0;
}