---
title: Problem 10. Summation of primes
author: DHDave
date: 2015-01-10
layout: post
---

## 题目
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

[Problem 10. Summation of primes](https://projecteuler.net/problem=10 title="Problem 10")
<!--more-->
## 翻译
10以下的质数的和是2 + 3 + 5 + 7 = 17.

找出两百万以下所有质数的和。

[题目10：计算两百万以下所有质数的和](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/11-10 title="题目10")

## 题解(Python)
```python
#! /usr/bin/env python
# -*- coding: utf-8

prime = [True]*2000000

def solve():
    prime[1:4] = [False, True, True]
    for i in range(1, 2000000):
        if prime[i] == True:
            k = i + i
            while k < 2000000:
                try:
                    prime[k] = False
                except:
                    print(k, i)
                k += i
    ans = 0
    for i in range(1, 2000000):
        if prime[i] == True:
            ans += i
    return ans
    

if __name__ == '__main__':
    ans = solve()
    print(ans)

# vim: set sw=4, ts=4
```

