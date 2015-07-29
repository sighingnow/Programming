# include <stdio.h>
# include <string.h>
/*
题目描述 Description
Rocky山脉有n个山峰，一字排开，从西向东依次编号为1, 2, 3, ……, n。每个山峰的高度都是不一样的。编号为i的山峰高度为hi。
小修从西往东登山。每到一座山峰，她就回头观望自己走过的艰辛历程。在第i座山峰，她记录下自己回头能看到的山峰数si。
何谓“能看到”？如果在第i座山峰，存在j<k<i，hj<hk，那么第j座山峰就是不可见的。除了不可见的山峰，其余的山峰都是可见的。
回家之后，小修把所有的si加起来得到S作为她此次旅行快乐值。现在n座山峰的高度都提供给你了，你能计算出小修的快乐值吗？
*/
int main()       //分析：不能用DP，用栈实现，每读入一座山的高，若栈顶元素比它大就入栈，否则删减栈的元素直到栈顶大于等于新读入的山的高
{
	int n, i, top, temp;
	long long sum = 0;
	scanf("%d", &n);
	int stack[n];      //用stack[]实现栈
	scanf("%d", &stack[0]);
	top = 1;
	for(i = 1; i < n; i++)        //最后一座山的高不影响结果
	{
		scanf("%d", &temp);
		sum += top;
		while(top >= 1 && temp > stack[top-1])
		{
			top--;
		}
		stack[top++] = temp;
	}
	printf("%lld\n", sum);  //windows环境下为 I64d
	
	return 0;
}

/*
输入描述 Input Description
第一行一个整数n(n<=15000)。
第i+1(1<=i<=n)行是一个整数hi（hi<=10^9）。
输出描述 Output Description
仅一行：快乐值。
样例输入 Sample Input
5
2
1
3
5
9
样例输出 Sample Output
5
数据范围及提示 Data Size & Hint
说明：s1=0, s2=1, s3=2, s4=1, s5=1。
*/
