# include <stdio.h>

int main()
{
    int n,i,j,m_ax=0,s_um=0;
    scanf("%d",&n);
    char a[n][25],d[n],e[n];
    int b[n],c[n],f[n],s[n];
    for(i=0;i<n;i++)
    {
        s[i] = 0;
        for(j=0;j<25;j++)
            a[i][j]='0';
    }
    for(i = 0; i < n; i++)
        scanf("%s %d %d %c %c %d",a[i],&b[i],&c[i],&d[i],&e[i],&f[i]);
    for(i=0;i<n;i++)
    {
        if(b[i]>80 && f[i]>0)
            s[i] += 8000;
        if(b[i]>85 && c[i]>80)
            s[i] += 4000;
        if(b[i]>90)
            s[i] += 2000;
        if(b[i]>85 && e[i] == 'Y')
            s[i] += 1000;
        if(c[i]>80 && d[i] == 'Y')
            s[i] += 850;
    }
    for(i=0;i<n;i++)
        s_um += s[i];
    for(i=0;i<n;i++)
        m_ax = s[i]>m_ax?s[i]:m_ax;
    for(i=0;i<n;i++)
    {
        if(m_ax == s[i])
        {
            j=0;
            while(a[i][j]!= '0')
            {
                printf("%c",a[i][j]);
                j++;
            }
            printf("\n%d\n",s[i]);
            printf("%d",s_um);
            return 0;
        }
    }
    return 0;
}
