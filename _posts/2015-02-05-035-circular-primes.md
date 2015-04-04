---
title: Problem 35. Circular primes
author: DHDave
date: 2015-02-05
layout: post
---

## 题目

The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?
<!--more-->
[Problem 35. Circular primes](https://projecteuler.net/problem=35 title="Problem 35")

## 翻译

我们称197为一个循环质数，因为它的所有轮转形式: 197, 971和719都是质数。

100以下有13个这样的质数: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 和97.

100万以下有多少个循环质数？

[题目35：100万以下有多少个循环质数？](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/36-35100 title="题目35")

## 题解

答案(answer): 212

```python
#! /usr/bin/env python
# -*- coding: utf-8 -*-

isprime = [True for i in range(0, 1000000)]
flag = [False for i in range(0, 1000000)]

def precess():
    isprime[0:2] = [False, False]
    for i in range(2, 1000000):
        if isprime[i]:
            n = i + i
            while n < 1000000:
                isprime[n] = False
                n += i

def rotate(n):
    m, n = len(str(n)), str(n)
    for i in range(0, m):
        k = int(n[i:m]+n[0:i])
        flag[k] = True
        if not isprime[k]:
            return False
    return True

if __name__ == '__main__':
    cnt = 0
    precess()
    for i in range(2, 1000000):
        if rotate(i):
            cnt += 1
    print(cnt)
# vim: set sw=4, ts=4
```
