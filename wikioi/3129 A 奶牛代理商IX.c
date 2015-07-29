# include <stdio.h>
# include <string.h>
/*
题目描述 Description
小X从美国回来后，成为了USACO中国区的奶牛销售代理商，专门出售质优价廉的“FJ”牌奶牛，因此生意很好。还记得那个巨大的牛棚吗？
由于年久失修，牛棚被拆。她建了一个新的、现代化牛棚。这个牛棚采用数字化管理，因此每头奶牛都有一个编号i，第i头奶牛对应第i间
牛棚。由于奶牛数量十分庞大，又打乱了顺序，所以必须由你进行升序排序。
我们保证第N（2<=N<=1000000）头奶牛一定有且仅有一间牛棚住,且奶牛编号一定连续。
注意：奶牛编号是可能大于N、但一定是INT范围内的整数
*/
/*最低位优先基数排序 LsdRadixSort，（最高为优先为：MsdRadixSort）
* int *array: 待排序数组,从 index=1 开始
* int len: 待排序数组长度
* int maxlen: 最大的数的位数
*/
void LsdRadixSort(int *array, int len, int maxlen)    //此处从小到大排序, 且仅考虑正数
{
	int tmpArray[10][len+1];         //index=0 用来记录个数，此处一次性分配，较费空间，可以通过动态分配优化
	int i, j ;
	for(i = 1; i <= maxlen; ++i)
	{
		memset(tmpArray, 0, sizeof(tmpArray));
		for(j = 1; j <= len; ++j)
		{
			int tmp = *(array+j), k = i - 1;
			while(k--)                  //得到array[j]的第 i 位数（从低位算起）,存在tmp中
				tmp /= 10;
			tmp %= 10;
			tmpArray[tmp][++tmpArray[tmp][0]] = *(array+j);
		}
		int p, q, k = 1;
		for(p = 0; p < 10; ++p)
		{
			for(q = 1; q <= tmpArray[p][0]; ++q)
				array[k++] = tmpArray[p][q];
		}
	}
}

int main()
{
	int n, i, maxlen, max = 0, max_nagetive = 0, tmp;   //maxlen表示最大的数的位数,(注意初值)
	scanf("%d", &n);
	int array[n+1], array_negative[n+1];//输入数据中有负数
	int count_array = 1, count_array_negative = 1;
	for(i = 1; i <= n; ++i)
	{
		scanf("%d", &tmp);
		if(tmp >= 0)
		{
			max = max > tmp ? max : tmp;
			array[count_array++] = tmp;
		}
		else
		{
			max_nagetive = max_nagetive > (-tmp) ? max_nagetive : (-tmp);
			array_negative[count_array_negative++] = -tmp;
		}
	}

	maxlen = 1;
	while(max_nagetive /= 10)
		++maxlen;
	LsdRadixSort(array_negative, count_array_negative-1, maxlen);
	for(i = count_array_negative-1; i >= 1; --i)
		printf("-%d ", array_negative[i]);

	maxlen = 1;
	while(max /= 10)
		++maxlen;
	LsdRadixSort(array, count_array-1, maxlen);    //此处仅考虑正数,若有负数，按其绝对值排序即可实现
	for(i = 1; i < count_array; ++i)
		printf("%d ", array[i]);
	
	return 0;
}
/*
输入描述 Input Description
第一行：一个正整数N
第二行：N头奶牛编号
输出描述 Output Description
奶牛编号升序排列
样例输入 Sample Input
10
1 2 3 4 5 6 7 8 9 10
样例输出 Sample Output
1 2 3 4 5 6 7 8 9 10
数据范围及提示 Data Size & Hint
还是那句话，请搜索：奶牛代理商以获得更多信息；
我们不推荐快排，原因见样例。
如果你只读入N而不排序，试图偷懒的话，有你好看！
注意：奶牛编号是可能大于N、但一定是INT范围内的整数
{
	Build:G-308-2-F;
	副标题：回家；
	标签：这不需要！；
} 
*/