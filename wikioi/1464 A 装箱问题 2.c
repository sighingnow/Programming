//filename:

# include <stdio.h>
/*
题目描述 Description
一个工厂制造的产品形状都是长方体，它们的高度都是h，长和宽都相等，一共有六个型号，他们的长宽分别为1*1, 2*2, 3*3, 4*4, 5*5, 6*6。
这些产品通常使用一个 6*6*h 的长方体包裹包装然后邮寄给客户。因为邮费很贵，所以工厂要想方设法的减小每个订单运送时的包裹数量。
他们很需要有一个好的程序帮他们解决这个问题从而节省费用。现在这个程序由你来设计。
输入描述 Input Description
输入文件包括几行，每一行代表一个订单。每个订单里的一行包括六个整数，中间用空格隔开，分别为1*1至6*6这六种产品的数量。输入文件将以
6个0组成的一行结尾。
*/
int t;

int main(void)
{
	int num[6];
	int i;
	while(1)
	{
		scanf("%d %d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
		if(num[0] == 0 && num[1] == 0 && num[2] == 0 && num[3] == 0 && num[4] == 0 && num[5] == 0)
		{
			break;
		}
		else
		{
			t = 0;
			for(i = 5; i >= 0; i--)
			{
				if(i == 5)
				{
					t += num[5];
				}
				else if(i == 4)
				{
					t += num[4];
					num[0] -= (11 * num[4]);
				}
				else if(i == 3)
				{
					if(num[3] > 0)
                    {
                        t += num[3];
                        if(num[1] > 5 * num[3])
                        {
                            num[1] -= (5 * num[3]);
                        }
                        else
                        {
                            num[0] -= (20 * num[3] - 4 * num[1]);
                            num[1] = 0;
                        }
                    }
				}
				else if(i == 2)
				{
					if(num[2] > 0)
					{
						if(num[2] % 4 != 0)
                        {
                            t += (num[2] / 4 + 1);
                            num[2] = num[2] % 4;
                            switch (num[2])
                            {
                                case 1:
                                {
                                    if(num[1] > 5)
                                    {
                                        if(num[1] > 5)
                                        {
                                            num[1] -= 5;
                                            num[0] -= 7;
                                        }
                                        else
                                        {
                                            num[0] -= (27 - num[1] * 4);
                                            num[1] = 0;
                                        }
                                    }
                                    else
                                    {
                                        num[0] -= (27 - 4 * num[1]);
                                        num[1] = 0;
                                    }
                                    break;          //注意要加break;
                                }
                                case 2:
                                {
                                    if(num[1] > 3)
                                    {
                                        num[0] -= 6;
                                        num[1] -= 3;
                                    }
                                    else
                                    {
                                        num[0] = (18 - 4 * num[1]);
                                        num[1] = 0;
                                    }
                                    break;
                                }
                                case 3:
                                {
                                    if(num[1] > 0)
                                    {
                                        num[0] -= 5;
                                        num[1] -= 1;
                                    }
                                    else
                                    {
                                        num[0] = (9 - 4 * num[1]);
                                        num[1] = 0;
                                    }
                                    break;
                                }
                            }
                        }
                        else
                        {
                            t += num[2] / 4;
                        }
					}
				}
				else if(i == 1)
				{
					if(num[1] > 0)
					{
						if(num[1] % 9 != 0)
                        {
                            t += (num[1] / 9 + 1);
                            num[1] %= 9;
                            num[0] -= (36 - num[1] * 4);
                        }
                        else
                        {
                            t += num[1] / 9;
                        }
					}
				}
				else if(i == 0)
				{
					if(num[0] > 0)
						t += num[0];
				}
			}
			printf("%d\n", t);
		}
	}

	return 0;
}

/*
输出描述 Output Description
除了输入的最后一行6个0以外，输入文件里每一行对应着输出文件的一行，每一行输出一个整数代表对应的订单所需的最小包裹数。
样例输入 Sample Input
0 0 4 0 0 1
7 5 1 0 0 0
0 0 0 0 0 0
样例输出 Sample Output
2
1
数据范围及提示 Data Size & Hint
数据范围很小，模拟即可
*/

