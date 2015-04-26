---
title: Problem 34. Digit factorials
author: DHDave
date: 2015-02-04
layout: post
---

## 题目

145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.
<!--more-->
[Problem 34. Digit factorials](https://projecteuler.net/problem=34 "Problem 34")

## 翻译

145 是一个奇怪的数字, 因为 1! + 4! + 5! = 1 + 24 + 120 = 145.

找出所有等于各位数字阶乘之和的数字之和。

注意: 因为 1! = 1 和 2! = 2 不是和的形式，所以它们不算在内。

[题目34：找出所有等于各位数阶乘之和的数字之和。](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/35-34 "题目34")

## 题解

不难分析出一个上界为 2540160，再枚举判断即可。

答案(answer): 40730

```python
#! /usr/bin/env python
# -*- coding: utf-8 -*-

def fact(n):
    ans = 1
    while n > 1:
        ans *= n
        n -= 1
    return ans

if __name__ == '__main__':
    ans = 0
    for i in range(3, 2540160):
        if i == sum([fact(int(j)) for j in str(i)]):
            print(i)
            ans += i
    print(ans)

# vim: set sw=4, ts=4
```
