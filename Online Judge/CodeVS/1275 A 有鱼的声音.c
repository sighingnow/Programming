# include <stdio.h>

/*
题目描述 Description
A ﬁsh-ﬁnder is a device used by anglers to ﬁnd ﬁsh in a lake. If the ﬁsh-ﬁnder ﬁnds a ﬁsh, it will sound an alarm. 
It uses depth readings to determine whether to sound an alarm. For our purposes, the ﬁsh-ﬁnder will decide that a ﬁsh 
is swimming past if:
fish-finder是一个神奇的装置供垂钓者使用区在护理钓鱼。如果一个f-f找到了一条鱼，他会响起声音警报。它用鱼的深度来决定是否响警报。
我们的目的就是要决定鱼是否通过，具体如下：

• there are four consecutive depth readings which form a strictly increasing sequence (such as 3 4 7 9) (which we will call 
“Fish Rising”), or
如果连续的四个深度读入是严格递增的序列，我们可以叫它 Fish Rising 。

• there are four consecutive depth readings which form a strictly decreasing sequence (such as 9 6 5 2) (which we will call 
“Fish Diving”), or
如果连续的四个深度读入是严格递减的序列，我们可以叫它 Fish Diving 。

• there are four consecutive depth readings which are identical (which we will call “Constant Depth”).
All other readings will be considered random noise or debris, which we will call “No Fish.”
Your task is to read a sequence of depth readings and determine if the alarm will sound.
如果连续的四个深度读入是一样的，那就是“Fish At Constant Depth”。如果都不是，就是“No Fish”。
输入描述 Input Description
The input will be four positive integers, representing the depth readings. Each integer will be on its own line of input.
输入会是四个正整数，代表深度读入。每个整数会占一行。
输出描述 Output Description
The output is one of four possibilities. If the depth readings are increasing, then the output should be Fish Rising. If the 
depth readings are decreasing, then the output should be Fish Diving. If the depth readings are identical, then the output should 
be Fish At Constant Depth. Otherwise, the output should be No Fish.
输出就是四种情况。
*/

int main()
{
    int f_f[4];
    int i;
    for(i = 0;i<4;i++)
        scanf("%d",&f_f[i]);
    if(f_f[0]<f_f[1] && f_f[1]<f_f[2] && f_f[2]<f_f[3])
        printf("Fish Rising");
    else if(f_f[0]>f_f[1] && f_f[1]>f_f[2] && f_f[2]>f_f[3])
        printf("Fish Diving");
    else if(f_f[0]==f_f[1] && f_f[1]==f_f[2] && f_f[2]==f_f[3])
        printf("Fish At Constant Depth");
    else
        printf("No Fish");

    return 0;
}

/*
样例输入 Sample Input
样例1：
30 10 20 20
样例2：
1 10 12 13
样例输出 Sample Output
样例1：
No Fish
样例2：
Fish Rising
数据范围及提示 Data Size & Hint
数据很小
*/
