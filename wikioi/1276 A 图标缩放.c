//file:
# include <stdio.h>

/*
题目描述 Description
You have been asked to take a small icon that appears on the screen of a smart telephone and scale it up so it looks bigger on a 
regular computer screen.
你被要求把手机上的小图标变成电脑上的大的。
 
The icon will be encoded as characters (x and *) in a 3 × 3 grid as follows:
小图标是：

*x*
  xx
*  *
Write a program that accepts a positive integer scaling factor and outputs the scaled icon. A scaling factor of k means that each 
character is replaced by a k × k grid consisting only of that character.
写一个程序把它每一个字符都变成k*k的
输入描述 Input Description
The input will be a positive integer k such that k < 25.
输入会是一个正整数k，k<25。
输出描述 Output Description
The output will be 3k lines, which represent each individual line scaled by a factor of k and repeated k times. A line is scaled by 
a factor of k by replacing each character in the line with k copies of the character.
输出会是3k行，详见样例。
*/

int main()
{
    char ch[9]={'*','x','*',' ','x','x','*',' ','*'};
    int k,i,j,t,s;
    scanf("%d",&k);
    s = 0;
    while(s < 9)
    {
        for(i= 1;i<=k;i++)
        {
            for(j=s;j<s+3;j++)
            {
                for(t=1;t<=k;t++)
                    printf("%c",ch[j]);
            }
            printf("\n");
        }
        s += 3;
    }

    return 0;
}

/*
样例输入 Sample Input
3
样例输出 Sample Output
***xxx***
***xxx***
***xxx***
      xxxxxx
      xxxxxx
      xxxxxx
***     ***
***     ***
***     ***
数据范围及提示 Data Size & Hint
按照题目要求的缩进
*/
