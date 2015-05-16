---
title: Problem 38. Pandigital multiples
author: DHDave
date: 2015-02-08
layout: post
---

## 题目

Take the number 192 and multiply it by each of 1, 2, and 3:

    192 × 1 = 192
    192 × 2 = 384
    192 × 3 = 576

By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)
<!--more-->
The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?

[Problem 38. Pandigital multiples](https://projecteuler.net/problem=38 "Problem 38")

## 翻译

将192与1,2,3分别相乘得到：

    192 × 1 = 192
    192 × 2 = 384
    192 × 3 = 576

将这三个乘积连接起来我们得到一个1到9的pandigital数， 192384576。我们称 192384576是192和 (1,2,3)的连接积。

通过将9与1,2,3,4和5相乘也可以得到pandigital数：918273645，这个数是9和(1,2,3,4,5)的连接积。

用一个整数与1,2, ... , n（n大于1）的连接积构造而成的1到9pandigital数中最大的是多少？

[题目38：最大的能够通过一个固定数与1,2,3，...相乘得到的1到9pandigital数是多少？](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/39-3812319pandigital "题目38")

## 题解

分析：首先，要找最大的数，那么用来拼接的项应当尽量少，n大于1，那么最少两项。枚举即可。

答案(answer): 932718654

```python
#! /usr/bin/env python
# -*- coding: utf-8 -*-

if __name__ == '__main__':
    ans = 0
    for x in range(3334, 10000):
        s = str(str(x)+str(x*2))
        if '0' not in s and len(s)==9 and len(set(s)) == 9:
            ans = int(s)
    print(ans)

# vim: set sw=4, ts=4
```
