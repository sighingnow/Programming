---
title: Problem 47. Distinct primes factors
author: DHDave
date: 2015-02-17
layout: post
---

## 题目

The first two consecutive numbers to have two distinct prime factors are:

    14 = 2 × 7
    15 = 3 × 5

The first three consecutive numbers to have three distinct prime factors are:

    644 = 2^2 × 7 × 23
    645 = 3 × 5 × 43
    646 = 2 × 17 × 19

Find the first four consecutive integers to have four distinct prime factors. What is the first of these numbers?
<!--more-->

[Problem 47. Distinct primes factors](https://projecteuler.net/problem=47 "Problem 47")

## 翻译

最小的两个具有两个不同质数因子的连续整数是：

    14 = 2 × 7
    15 = 3 × 5

最小的三个具有三个不同质数因子的连续整数是：

    644 = 2^2 × 7 × 23
    645 = 3 × 5 × 43
    646 = 2 × 17 × 19

找出最小的四个具有四个不同质数因子的整数。它们之中的第一个是多少？

[题目47：找出最小的具有四个不同质数因子的四个连续整数。](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/48-47 "题目47")

## 题解

答案(answer): 134043

```python
#! /usr/bin/env python
# -*- coding: utf-8 -*-

from math import sqrt

def prime(n):
    for x in range(2, int(sqrt(n))+1):
        if n % x == 0:
            return False
    return True

def check(x):
    if prime(x):
        return 1
    k, m = 2, 0
    while x > 1:
        if x % k == 0:
            m += 1
            if m > 4:
                return m
            while x % k == 0:
                x //= k
        k += 1
    return m

if __name__ == '__main__':
    M = [0 for i in range(0, 1000000)]
    for x in range(210, 1000000):
        M[x] = check(x)
        if M[x]==4 and M[x-1]==4 and M[x-2]==4 and M[x-3]==4:
            print(x-3)
            break

# vim: set sw=4, ts=4
```
