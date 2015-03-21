---
title: Problem 21. Amicable numbers
author: DHDave
date: 2015-01-21
layout: post
---

Problem 21. Amicable numbers
---------------------------

## 题目

Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.

[Problem 21. Amicable numbers](https://projecteuler.net/problem=21 title="Problem 21")

## 翻译

d(n)定义为n 的所有真因子（小于 n 且能整除 n 的整数）之和。

如果 d(a) = b 并且 d(b) = a, 且 a ≠ b, 那么 a 和 b 就是一对相亲数（amicable pair），并且 a 和 b 都叫做亲和数（amicable number）。

例如220的真因子是 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 和 110; 因此 d(220) = 284. 284的真因子是1, 2, 4, 71 和142; 所以d(284) = 220.

计算10000以下所有亲和数之和。

[题目21：计算10000以下所有相亲数之和](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/22-2110000 title="题目21")

## 题解

答案(answer): 15813

```python
#! /usr/bin/env python
# -*- coding: utf-8 -*-

cnt = [0 for i in range(0, 10001)]

def getCnt(number):
    for i in range(1, number):
        if number % i == 0:
            cnt[number] += i
    return cnt[number]

if __name__ == '__main__':
    for i in range(2, 10000):
        getCnt(i)
    ans = 0
    for i in range(2, 10000):
        try:
            if i == cnt[cnt[i]] and i != cnt[i]:
                print(i, cnt[i])
                ans += i
        except:
            pass
    print(ans//2)

# vim: set sw=4, ts=4
```
