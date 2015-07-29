//高精度乘法
#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,k,s,t,m,n,op;
    char a[20001],b[20001];
    int c[20001],d[20001],f[40001];
    scanf("%s %s",&a,&b);
    m=strlen(a);
    n=strlen(b);
    for(i=0;i<m;i++)
        c[i]=a[m-1-i]-48;
    for(i=0;i<n;i++)
        d[i]=b[n-1-i]-48;

    for(i=0;i<m+n;i++)
        f[i]=0;             //作用：给f[i]赋初值，为 0；
    /*也可调用<string.h>中的memset函数，写为：
    memset(f,0,sizeof(f));
    25 25*/
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            f[i+j]=f[i+j]+d[i]*c[j];    //从竖式乘法中找到的规律
    for(i=0;i<m+n;i++)            //利用：任意两数的的积的位数小于等于这两个数的位数之和
        if(f[i]>9)
        {
            f[i+1]=f[i+1]+f[i]/10;
            f[i]=f[i]%10;
        }
    /*上述求积的过程也可写为：（时间复杂度大）
    for(i=0;i<n;i++)
    {
        k=i;
        t=0;
        for(j=0;j<m;j++)
        {
            op=c[j]*d[i]+t+f[k];
            f[k]=op%10;
            t=op/10;
            k++;
        }
        f[k]=t;
    }
    */
    for(j=m+n-1;j>=0;j--)
        if(f[j]!=0)
        break;
    for(i=j;i>=0;i--)
        printf("%d",f[i]);
    return 0;
}
