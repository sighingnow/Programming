# include <stdio.h>

int swap(int *a,int *b)
{
    int c;
    if(*a > *b)
        c=*a,*a=*b,*b=c;
}
int main()
{
    int N,i,j,k,t;
    scanf("%d",&N);
    int num[N];
    for(i = 0;i < N;i ++)
        scanf("%d",&num[i]);
    for(i = 0;i<N;i++)
    {
        for(j = i+1; j<N; j++)
            swap(&num[i],&num[j]);
    }
    t = 1;
    for(i = 1;i<N;i++)
        if(num[i] != num[i-1])
            t ++;
    printf("%d\n%d ",t,num[0]);
    for(i =1;i<N;i++)
        if(num[i] != num[i-1])
            printf("%d ",num[i]);

    return 0;
}
