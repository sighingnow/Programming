---
title: Problem 40. Champernowne's constant
author: DHDave
date: 2015-02-10
layout: post
---

## 题目

An irrational decimal fraction is created by concatenating the positive integers:

$$ 0.123456789101112131415161718192021... $$

It can be seen that the 12th digit of the fractional part is 1.
<!--more-->
If dn represents the nth digit of the fractional part, find the value of the following expression.

$$ d_1 \times d_10 \times d_100 \times d_1000 \times d_10000 \times d_100000 \times d_1000000 $$

[Problem 40. Champernowne's constant](https://projecteuler.net/problem=40 "Problem 40")

## 翻译

将正整数连接起来可以得到一个无理小数：

$$ 0.123456789101112131415161718192021... $$

可以看出小数部分的第12位是1。

如果用dn表示这个数小数部分的第n位，找出如下表达式的值：

$$ d_1 \times d_10 \times d_100 \times d_1000 \times d_10000 \times d_100000 \times d_1000000 $$

[题目40：找出这个无理数的小数部分的第n位。](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/41-40n "题目40")

## 题解

分析：

不难推出如下的序列：

```
1-9: 9                           ----    9
10-99: 90*2 = 180                -----   189
100-999: 900*3 = 2700            -----   2889
1000-9999: 9000*4 = 36000        -----   38889
10000-99999: 90000*5 = 450000    -----   488889
100000-999999: 9000000*6 = 54000000
```

计算一下位数，便不难得出：

```
d_1 = 1
d_10 = 1
d_100 = 5
d_1000 = 3
d_10000 = 7
d_100000 = 2
d_1000000 = 1
```

相乘：得`210`。

答案(answer): 210

