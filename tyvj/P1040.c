/*
描述 Description
给出一个表达式,其中运算符仅包含+,要求求出表达式的最终值
*/

# include <stdio.h>
# include <string.h>
# define max(a,b) ((a)>=(b)?(a):(b))
 
void add(int x[],int y[],int m,int n)    //求和
{
    int i,k,t;
    t = 0;
    for(i = 0;i <= max(m,n); i++)
    {
        k = (x[i] + y[i] + t);
        t = k / 10;
        x[i] = k % 10;
    }
}

int main()
{
    char s[1501];
	int d1[1500]={0},d2[1500]={0},d3[1500]={0};    //d3[]用于中转输入的数（数组倒置）
    char op;
    int i,j,k,m,n;
    scanf("%s",s);
    j = 0;
    m = 0;
    n = 0;
    while(1)
    {
 		op = s[j];
        if(op == '\0')
        {
            for(i = 0; i < n; i++)   //倒置
                d2[i] = d3[n-1-i];
            add(d1,d2,m,n);
            break;
        }
        else
        {
            if(op == '+')
            {
                for(i = 0; i < n; i++)    //倒置
                    d2[i] = d3[n-1-i];
                add(d1,d2,m,n);
                m = max(m,n);
                for(i = 0; i <= n; i++)
                	d2[i] = 0;
                n = 0;
            }
            else
            {
                d3[n] = op - '0';
                n ++;
            }
        }
   		j++;
    }
    for(k = max(m,n)+1; k>=0; k--)   //寻找非零最高位
        if(d1[k] != 0)
            break;
    for(i = k; i >= 0; i--)
        printf("%d",d1[i]);

    return 0;
}

/*
输入格式 InputFormat
仅一行，即为表达式
输出格式 OutputFormat
仅一行，既为表达式算出的结果
样例输入 SampleInput [复制数据]
1+1
样例输出 SampleOutput [复制数据]
2
数据范围和注释 Hint
表达式总长度<=1500
*/
