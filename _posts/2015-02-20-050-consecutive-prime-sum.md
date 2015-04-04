---
title: Problem 50. Consecutive prime sum
author: DHDave
date: 2015-02-20
layout: post
---

## 题目

The prime 41, can be written as the sum of six consecutive primes:
$$ 41 = 2 + 3 + 5 + 7 + 11 + 13 $$
This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.
<!--more-->
Which prime, below one-million, can be written as the sum of the most consecutive primes?

[Problem 50. Consecutive prime sum](https://projecteuler.net/problem=50 title="Problem 50")

## 翻译

41这个质数，可以写作6个连续质数之和：
$$ 41 = 2 + 3 + 5 + 7 + 11 + 13 $$
这是100以下的最长的和为质数的连续质数序列。

1000以下最长的和为质数的连续质数序列包含21个项，和为953.

找出100万以下的最长的何为质数的连续质数序列之和。

100万以下的哪个质数能够写成最长的连续质数序列？

[题目50：100万以下的哪个质数能够写成最多连续质数的和？](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/51-50100 title="题目50")

## 题解

分析：枚举连续质数的和，然后判断和是为质数。估计范围，剪枝。

答案(answer): 997651

```python
#! /usr/bin/env python
# -*- coding: utf-8 -*-

from math import sqrt

def prime(n):
    if n == 2 or n == 3:
        return True
    for x in range(2, int(sqrt(n))+1):
        if n % x == 0:
            return False
    return True

if __name__ == '__main__':
    primes = []
    for i in range(2, 1000000):
        if prime(i):
            primes.append(i)
    count, maxlen, x = len(primes), 0, 0

    for i in range(10):
        l, total = 0, 0
        seq = primes[i:]
        for j in seq:
            total += j
            l += 1
            if total > 1000000:
                break
            if total in primes and maxlen < l:
                maxlen, x = l, total
    print(x, maxlen)

# vim: set sw=4, ts=4
```
