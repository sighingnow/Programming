#include<stdio.h>
#include<string.h>

int main()
{
    int i,s,j,t=0,m,n;
    char a[10000],b[10000];
    int c[10001],d[10001],e[10001];
    for(i=0;i<10001;i++)
    {
        c[i]=0;
        d[i]=0;
        e[i]=0;
    }
    scanf("%s %s",&a,&b);
    m=strlen(a);
    n=strlen(b);
    s=m>n?m:n;
    for(i=0;i<m;i++)
        c[i]=a[m-1-i]-48;
    for(i=0;i<n;i++)
        d[i]=b[n-1-i]-48;
    for(i=0;i<=s;i++)
    {
        if((c[i]+d[i]+t)>9)
        {
            e[i]=c[i]+d[i]+t-10;
            t=1;
        }
        else
        {
            e[i]=c[i]+d[i]+t;
            t=0;
        }
        /*中间求 e[i] 的过程可改为
        e[i]=(c[i]+d[i]+t)%10;
        t=(c[i]+d[i]+t)/10;*/
    }
    if(e[s]!=0)
        for(i=s;i>=0;i--)
            printf("%d",e[i]);
    else
        for(i=s-1;i>=0;i--)
            printf("%d",e[i]);
    return 0;
}
/*最后的输出也可以这样改：
for(j=10000;j>=0;j--)           //千万注意，此处j初值为10000，而不是10001，因为e[10001]是不存在的
    if(e[j] != 0)
    break;
printf("%d\n",j);
system("pause");
for(i=j;i>=0;i--)
    printf("%d",e[i]);
    return 0;
}
*/

