/***************************************************
*Copyright (C):  2014  HeTao  All Rights Reserved.
*Filename:
*Author: ht
*Version:
*Created on:
****************************************************/
# include <iostream>
using namespace std;
/*
描述 Description
由文件给出N个0到100000间无序数正整数，其中1≤N≤60000，同一个正整数可能会出现多次，出现次数最多的整数称为众数。
求出它的众数及它出现的次数。
*/
int num[100001];
int main(int argc, char **argv)
{
	int n, i, temp;
	cin >> n;
	while (n--)
	{
		cin >> temp;
		num[temp] ++;
	}
	int max = 0;
	for(i = 0; i < 100001; i++)
	{
		if(max < num[i])
		{
			max = num[i];
		}
	}
	for(i = 0; i < 100001; i++)
	{
		if(num[i] == max)
			cout << i << " " << num[i] << endl;
	}

	return 0;
}

/*
输入格式 InputFormat
输入第一行是正整数的个数N，下面N行为N个正整数。
输出格式 OutputFormat
输出有若干行，每行两个数，第1个是众数，第2个是众数出现的次数，按照众数升序序列输出
样例输入 SampleInput [复制数据]
12
2
4 
2 
3 
2
5
3
7
2
3
4
3
样例输出 SampleOutput [复制数据]
2 4
3 4
*/
