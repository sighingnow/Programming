# include <stdio.h>
# include <string.h>

int main()
{
    char ch1[120],ch2[120];
    int i,j,m,n,flag=0,t;
    scanf("%s %s",&ch1,&ch2);
    m = strlen(ch1);
    n = strlen(ch2);
    for(i = 0; i < m; i++)
    {
        t = i + 1;
        if(ch2[0] == ch1[i])
        {
            for(j = 1; ; j++)
            {
                if(ch1[i+1] == ch2[j])
                    i++;
                else
                {
                    flag = 0;
                    break;
                }
                if(j == n-1)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 1)
        {
            printf("%d",t);
            return 0;
        }
    }
    return 0;
}
