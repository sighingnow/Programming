---
title: Problem 49. Prime permutations
author: DHDave
date: 2015-02-19
layout: post
---

## 题目

The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.
<!--more-->
What 12-digit number do you form by concatenating the three terms in this sequence?

[Problem 49. Prime permutations](https://projecteuler.net/problem=49 title="Problem 49")

## 翻译

1487, 4817, 8147这个序列，每个比前一个递增3330，而且这个序列有两个特点：1. 序列中的每个数都是质数。2. 每个四位数都是其他数字的一种排列。

1，2，3位组成的三个质数的序列中没有具有以上性质的。但是还有另外一个四位的递增序列满足这个性质。

如果将这另外一个序列的三个数连接起来，组成的12位数字是多少？

[题目49：找出由互为排列的4位数质数组成的序列。](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/50-494 title="题目49")

## 题解

分析：枚举四位质数，然后再枚举差值。

答案(answer): 296962999629

```python
#! /usr/bin/env python
# -*- coding: utf-8 -*-

from math import sqrt
from itertools import permutations

def prime(n):
    for x in range(2, int(sqrt(n))+1):
        if n % x == 0:
            return False
    return True

if __name__ == '__main__':
    primes = []
    for i in range(1000, 10000):
        if prime(i):
            primes.append(i)
    for k in primes:
        for diff in range(1, (10000-k)//2):
            if set(str(k))==set(str(k+diff))==set(str(k+2*diff)) \
                    and k+diff in primes and k+2*diff in primes:
                print(k, k+diff, k+2*diff)

# vim: set sw=4, ts=4
```
