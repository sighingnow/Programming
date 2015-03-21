---
title: Problem 23. Non-abundant sums
author: DHDave
date: 2015-01-23
layout: post
---

## 题目

A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

[Problem 23. Non-abundant sums](https://projecteuler.net/problem=23 title="Problem 23")

## 翻译

如果一个数的所有真因子之和等于这个数，那么这个数被称为完全数。例如，28的所有真因子之和为1 + 2 + 4 + 7 + 14 = 28，所以28是一个完全数。

如果一个数的所有真因子之和小于这个数，称其为不足数，如果大于这个数，称其为过剩数。

12是最小的过剩数，1 + 2 + 3 + 4 + 6 = 16。因此最小的能够写成两个过剩数之和的数字是24。经过分析，可以证明所有大于28123的数字都可以被写成两个过剩数之和。但是这个上界并不能被进一步缩小，即使我们知道最大的不能表示为两个过剩数之和的数字要比这个上界小。

找出所有不能表示为两个过剩数之和的正整数之和。

[题目23：算出所有不能写成两个过剩数之和的正整数之和。](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/24-23 title="题目23")

## 题解

答案(answer): 4179871

```python
#! /usr/bin/env python
# -*- coding: utf-8 -*-

bound = 28123
flag = [False for i in range(0, bound+1)]
number = []

def calNum(n):
    adds = 0
    for i in range(1, n):
        if n % i == 0:
            adds += i
    if adds > n:
        number.append(n)

if __name__ == '__main__':
    for i in range(2, bound+1):
        calNum(i)
    for i in number:
        for j in number:
            try:
                flag[i+j] = True
            except:
                pass
    ans = 0
    for i in range(0, bound+1):
        if not flag[i]:
            ans += i
    print(ans)

# vim: set sw=4, ts=4
```
