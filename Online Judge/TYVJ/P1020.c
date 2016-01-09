# include <stdio.h>
# include <math.h>

int prime(int a)
{
    int i,t;
    t = (int)sqrt(a);
    for(i=2;i<=t+1;i++)
        if(a%i == 0)
            return 0;
    return 1;
}

int main()
{
    int n,i,j,t,m;
    scanf("%d",&n);
    int m_ax[n],a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>1)
        {
            for(j=2;j<=a[i];j++)
            {
                if(a[i]%j == 0)
                    if(prime(j) == 1)
                        m_ax[i] = j;
            }
        }
        else
            m_ax[i] = 1;
    }
    m=m_ax[0],t=0;
    for(i=0;i<n;i++)
        if(m<m_ax[i])
        {
            m=m_ax[i];
            t=i;
        }
    printf("%d",a[t]);
    return 0;
}
