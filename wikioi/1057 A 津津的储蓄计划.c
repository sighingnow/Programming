# include <stdio.h>

int main()
{
    int charge[12];
    int i,j,k,t,s,last;
    for(i=0;i<12;i++)
        scanf("%d",&charge[i]);
    t = 0,s=0;
    for(i=0;i<12;i++)
    {
        if(charge[i] > t+300)
        {
            printf("-%d",i+1);
            return 0;
        }
        else
        {
            k = (int)((t+300-charge[i])/100);
            s = s + k;
            t = t+300-charge[i] - k*100;
        }
    }
    printf("%d",t+s*120);

    return 0;
}
