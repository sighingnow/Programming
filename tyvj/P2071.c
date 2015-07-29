# include <stdio.h>
# include <string.h>

/*
背景 Background
NOIP 2012 提高组 题1
描述 Description
16 世纪法国外交家 Blaise de Vigenère 设计了一种多表密码加密算法——Vigenère 密码。Vigenère 密码的加密解密算法
简单易用,且破译难度比较高,曾在美国南北战争中为南军所广泛使用。
在密码学中,我们称需要加密的信息为明文,用 M 表示;称加密后的信息为密文,用C 表示;
而密钥是一种参数,是将明文转换为密文或将密文转换为明文的算法中输入的数据,记为 k。 在 Vigenère 密码中,密钥 k 是
一个字母串, k1k2...kn。
当明文 M=m1m2...mn 时,得到的密文 C=c1c2...cn,其中 ci=mi?ki,运算?的规则如下表所示:
[图片]
Vigenère 加密在操作时需要注意:
1. ?运算忽略参与运算的字母的大小写,并保持字母在明文 M 中的大小写形式;
2. 当明文 M 的长度大于密钥 k 的长度时,将密钥 k 重复使用。
例如,明文 M=Helloworld,密钥 k=abc 时,密文 C=Hfnlpyosnd。
明文 H e l l o w o r l d
密钥 a b c a b c a b c a
密文 H f n l p y o s n d
*/

char trs(char a)           //将小写转化为大写字母 
{
	return a>='a'?a:(a + 'a' - 'A');
}
int main()
{
	char k[1500],c[1500],w[1500];
	int i,j,len1,len2;
	scanf("%s",k);
	scanf("%s",c);
	len1 = strlen(k);
	len2 = strlen(c);
	j = 0;
	for(i = len1; i < len2; i++)
	{
		k[i] = k[j];
		j ++;
		if(j == len1)
			j = 0;
	}
	for(i = 0; i < len2; i++)
	{
		if(trs(k[i]) > trs(c[i]))
			w[i] = 'z' - trs(k[i]) + trs(c[i]) - 'a' + 'a' + 1;
		else
			w[i] = trs(c[i]) - trs(k[i]) + 'a';
	}
	for(i = 0; i < len2; i++)
	{
		if(c[i] >= 'a')
			printf("%c",w[i]);
		else
			printf("%c",w[i]-'a'+'A');
	}
	
	return 0;
}

/*
输入格式 InputFormat
输入共 2 行。
第一行为一个字符串,表示密钥 k,长度不超过 100,其中仅包含大小写字母。第二行为一个字符串,表示经加密后的密文,长度
不超过 1000,其中仅包含大小写字母。
输出格式 OutputFormat
输出共 1 行,一个字符串,表示输入密钥和密文所对应的明文。
样例输入 SampleInput [复制数据]
CompleteVictory
Yvqgpxaimmklongnzfwpvxmniytm
样例输出 SampleOutput [复制数据]
Wherethereisawillthereisaway
数据范围和注释 Hint
对于 100%的数据,输入的密钥的长度不超过 100,输入的密文的长度不超过 1000,且都仅包含英文字母。
来源 Source
NOIP 2012
*/
