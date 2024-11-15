#include <stdio.h>
#include <stdlib.h>
int main()
{
    char* s;
    s=(char *)malloc(sizeof(char));
    while (scanf("%s",s)!=EOF)
    {
        int i=0;
        while (*s!='\0')
        {
            s++;
            i++;
        }
        s--;
        for (int j = 0; j < i; j++)
        {
            printf("%c",*s);
            s--;
        }
        printf(" %d\n",i);
    }
    return 0;
}
