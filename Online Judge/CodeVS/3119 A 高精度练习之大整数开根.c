#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
/*
题目描述 Description
给出一个正整数n，求n开根号后的整数部分的值。n的位数不超过1000位。
*/
int * multi(int *num, int *ans, int numlen, int &anslen, int x)
{
	memset(ans, 0, sizeof(ans));
	anslen = numlen;
	for(int i = 0; i < numlen; ++i)
	{
		ans[i] = num[i] * x;
	}
	int tmp = 0;
	for(int i = 0; i < numlen; ++i)
	{
		ans[i] = ans[i] + tmp;
		tmp = ans[i] / 10;
		ans[i] %= 10;
	}
	while(tmp)
	{
		ans[anslen++] = tmp % 10;
		tmp /= 10;
	}
	while(anslen > 0 && !ans[anslen-1])//防止全部被乘成 0
		--anslen;
	if(!anslen)
		++anslen;
	return ans;
}

void sub(int *x, int *y, int &xlen, int ylen)//x-y,结果存在 x 中
{
	for(int i = 0, j = 0; i < xlen && j < ylen; ++i, ++j)
	{
		if(x[i] >= y[j])
			x[i] -= y[j];
		else
		{
			x[i] = x[i] + 10 - y[j];
			x[i+1]--;
		}
	}
	for(int i = xlen; i >= 0; --i)
	{
		if(x[i] > 0)
		{
			xlen = i + 1;
			break;
		}
	}
}

int cmp(int *num, int *tmp, int numlen, int tmplen)
{
	if(tmplen < numlen)
		return 1;
	if(tmplen > numlen)
		return 0;
	for(int i = numlen-1; i >= 0; --i)
	{
		if(num[i] < tmp[i])
			return 0;
		if(num[i] > tmp[i])
			return 1;
	}
	return 1;
}

int main()   //手动开方算法
{
	char s[1500];
	scanf("%s", s);

	int ans[600] = {0}, div[600] = {0}, num[600] = {0}, tmp[600], tmpans[600];
	int anslen = 0, divlen = 0, numlen = 0, tmplen = 0, slen = 0, tmpanslen = 0;
	int posi = 0, temp;
	slen = strlen(s);

	for(int i = 0; i < slen; ++i)
		s[i] -= '0';
	
	if(slen & 1)
	{
		temp = s[posi++];
	}
	else
	{
		temp = s[0] * 10 + s[1];
		posi = 2;
	}

	ans[anslen++] = sqrt(temp);
	if(ans[0] * ans[0] != temp)
	{
		temp -= ans[0] * ans[0];
		while(temp)
		{
			num[numlen++] = temp % 10;
			temp /= 10;
		}
	}

	while(posi < slen)
	{
		for(int i = 0; i < anslen; ++i)//反转
		{
			tmpans[anslen-1-i] = ans[i];
		}
		tmpanslen = anslen;

		multi(tmpans, div, tmpanslen, divlen, 20);
		
		numlen += 2;
		if(numlen > 2)
		{
			for(int i = numlen - 1; i >= 2; --i)
				num[i] = num[i-2];
		}
		num[1] = s[posi];
		num[0] = s[posi+1];
		for(int i = 9; i >=0; --i)
		{
			div[0] = i;
			multi(div, tmp, divlen, tmplen, i);
			if(cmp(num, tmp, numlen, tmplen))//tmp < num
			{
				ans[anslen++] = i;
				break;
			}
		}

		sub(num, tmp, numlen, tmplen);
		posi += 2;
	}

	for(int i = 0; i < anslen; ++i)
	{
		printf("%d", ans[i]);
	}
	return 0;
}
/*
输入描述 Input Description
读入一个不超过1000位的正整数n。
输出描述 Output Description
输出所求答案
样例输入 Sample Input
17
样例输出 Sample Output
4
数据范围及提示 Data Size & Hint
n为不超过1000位的正整数 满足  1 <= n <10^1000
*/