#include <iostream>
#include <cstdio>
#include <cstdlib>
#define NUM 50000
#define read(x) {char ch;\
	            x=0;\
                while((ch=getchar())>'9'||ch<'0');\
                x=ch-'0';\
	            while((ch= getchar())<='9'&&ch>='0')\
					x=x*10+ch-'0';\
	            }

using namespace std;
/*
题目描述 Description
动物王国中有三类动物 A,B,C，这三类动物的食物链构成了有趣的环形。A吃B，B吃C，C吃A。 　　
现有N个动物，以1－N编号。每个动物都是A,B,C中的一种，但是我们并不知道它到底是哪一种。 　　
有人用两种说法对这N个动物所构成的食物链关系进行描述： 　　
第一种说法是“1 X Y”，表示X和Y是同类。 　　
第二种说法是“2 X Y”，表示X吃Y.
此人对N个动物，用上述两种说法，一句接一句地说出K句话，这K句话有的是真的，有的是假的。当一句话满足下列三条之一时，这句话就是假话，
否则就是真话。
1） 当前的话与前面的某些真的话冲突，就是假话； 　　
2） 当前的话中X或Y比N大，就是假话； 　　
3） 当前的话表示X吃X，就是假话。 　　
你的任务是根据给定的N（1<=N<=50,000）和K句话（0<=K<=100,000），输出假话的总数。
*/

int find(int x, int *uset)
{
	if(x != uset[x])
		uset[x] = find(uset[x], uset);
	return uset[x];
}

void unionSet(int x, int y, int *uset, int *rank)
{
	if((x = find(x, uset)) == (y = find(y, uset)))
		return;
	if(rank[x] > rank[y])
		uset[y] = x;
	else
		uset[x] = y;
	if(rank[x] == rank[y])
		rank[y]++;
}

//开 3 倍的数组，分别为：本身，食物, 以之为食物的
int main(int argc, char **argv)
{
	int n, k;
	cin >> n >> k;
	int uset[3 * NUM + 1], rank[3 * NUM + 1] = {0};

	for(int i = 0; i <= 3 * NUM; ++i)
		uset[i] = i;

	int D, x, y, sum = 0;

	while(k--)
	{
		read(D); read(x); read(y);

		if(x > n || y > n || (D == 2 && x == y))//假话
		{
			sum ++;
			continue;
		}

		int rx = find(x, uset);
		int ry = find(y, uset);
		int rxn = find(x + NUM, uset);
		int ryn = find(y + NUM, uset);
		int rxn2 = find(x + 2 * NUM, uset);
		int ryn2 = find(y + 2 * NUM, uset);

		if(D == 1)
		{
			if(rx != ryn && ry != rxn)//真话，同类的两个互不为食物
			{
				unionSet(x, y, uset, rank);
				unionSet(x + NUM, y + NUM, uset, rank);
				unionSet(x + 2 * NUM, y + 2 * NUM, uset, rank);
			}
			else
			{
				sum++;
			}
		}

		if(D == 2)
		{
			
			if(rx == ry || ryn == rx)//假话
			{
				sum ++;
			}
			else//真话
			{
				unionSet(ry, rxn, uset, rank);
				unionSet(ryn, rxn2, uset, rank);
				unionSet(ryn2, rx, uset, rank);
			}
		}
	}
	cout << sum;
	
	return 0;
}

/*
输入描述 Input Description
第一行是两个整数N和K，以一个空格分隔。 　　
以下K行每行是三个正整数D，X，Y，两数之间用一个空格隔开，其中 D 表示说法的种类。 　　
若D=1，则表示X和Y是同类。 　　
若D=2，则表示X吃Y。
输出描述 Output Description
只有一个整数，表示假话的数目。
样例输入 Sample Input
100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5
样例输出 Sample Output
3
数据范围及提示 Data Size & Hint
输入文件  
对7句话的分析 100 7
1 101 1　　假话
2 1 2　　  真话
2 2 3　　  真话
2 3 3　　  假话
1 1 3　　  假话
2 3 1　　  真话
1 5 5　　  真话
NOI 2001 食物链(eat)
*/