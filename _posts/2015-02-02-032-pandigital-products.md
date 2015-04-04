---
title: Problem 32. Pandigital products
author: DHDave
date: 2015-02-02
layout: post
---

## 题目

We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.
<!--more-->
Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

**HINT**: <small>Some products can be obtained in more than one way so be sure to only include it once in your sum.</small>

[Problem 32. Pandigital products](https://projecteuler.net/problem=32 title="Problem 32")

## 翻译

如果一个n位数使用了1到n中每个数字且只使用了一次，我们称其为pandigital。例如，15234这个五位数，是1到5pandigital的。

7254是一个不寻常的数，因为：39 × 186 = 7254这个算式的乘数，被乘数和乘积组成了一个1到9的pandigital组合。

找出所有能够组合成1到9pandigital的乘法算式中乘积的和。

**提示**: <small>有的乘积数字能够被多个乘法算式得到，所以在计算时要记得只计算它们一次。</small>

[题目32：找出所有能写成pandigital数字乘积的数字之和](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/33-32pandigital title="题目32")

## 题解

答案(answer): 45228

```python
#! /usr/bin/env python
# -*- coding: utf-8 -*-

def calc(a, b):
    cnt = [0 for i in range(0, 10)]
    for e in [a, b, a*b]:
        for t in str(e):
            cnt[int(t)] += 1
    if cnt[0] != 0:
        return False
    for i in range(1, 10):
        if cnt[i] != 1:
            return False
    return True

if __name__ == '__main__':
    ans = {}
    for a in range(1, 10000):
        for b in range(a+1, 10000):
            if str(a).__len__() + str(b).__len__() + str(a*b).__len__() > 9:
                break
            if calc(a, b):
                ans[a*b] = 1
    print(sum(ans.keys()))

# vim: set sw=4, ts=4
```
