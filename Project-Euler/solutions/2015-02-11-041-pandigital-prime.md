---
title: Problem 41. Pandigital prime
author: DHDave
date: 2015-02-11
layout: post
---

## 题目

We shall say that an _n-digit_ number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest _n-digit_ pandigital prime that exists?
<!--more-->
[Problem 41. Pandigital prime](https://projecteuler.net/problem=41 "Problem 41")

## 翻译

如果一个数字将1到n的每个数字都使用且只使用了一次，我们将其称其为一个n位的pandigital数。例如，2143是一个4位的pandigital数，并且是一个质数。

最大的n位pandigital质数是多少？

[题目41：最大的n位pandigital质数是多少？](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/42-41npandigital "题目41")

## 题解

分析：

观察累加和的特点：

```
1 1
2 3
3 6
4 10
5 15
6 21
7 28
8 36
9 45
```

猜测n的值为7（判断累加和能否被3整除）,开始枚举7位数的全排列。同时，因为要找最大的，所以从大往小找。

答案(answer): 7652413

```python
#! /usr/bin/env python
# -*- coding: utf-8 -*-

import itertools
import math

def isprime(n):
    for x in range(2, int(math.sqrt(n))+1):
        if n % x == 0:
            return False
    return True


if __name__ == '__main__':
    for x in itertools.permutations([7,6,5,4,3,2,1]):
        t = 0
        for i in x:
            t = t*10+i
        if isprime(t):
            print(x)
            break

# vim: set sw=4, ts=4
```
