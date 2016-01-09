# include <stdio.h>

int main()
{
    int i,j,n;
    float k=0,t=0,gpa;
    scanf("%d",&n);
    float a[n],b[n];
    for(i=0;i<n;i++)
        scanf("%f %f",&a[i],&b[i]);
    for(i=0;i<n;i++)
    {
        t += a[i]*b[i];
        k += a[i];
    }
    printf("%.2f",t/k);

    return 0;
}
