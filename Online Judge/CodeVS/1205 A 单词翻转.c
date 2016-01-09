# include <stdio.h>
# include <string.h>

int main()
{
    char f[1000];
    int i,j,k,t;
    gets(f);
    k = strlen(f);
    t = k;
    for(i = k-1; i >= 0; i--)
    {
        if(f[i] == ' ')
        {
            for(j = i+1;j<t;j++)
                printf("%c",f[j]);
            t = i;
            printf(" ");
        }
    }
    for(j = 0;j < t;j++)
        printf("%c",f[j]);

    return 0;
}
