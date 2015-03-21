---
title: Problem 37. Truncatable primes
author: DHDave
date: 2015-02-07
layout: post
---

Problem 37. Truncatable primes
--------------------------------

## 题目

The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

[Problem 37. Truncatable primes](https://projecteuler.net/problem=37 title="Problem 37")

## 翻译

3797这个数很有趣。它本身是质数，而且如果我们从左边不断地裁去数字，得到的仍然都是质数：3797,797,97,7。而且我们还可以从右向左裁剪：3797,379,37,3，得到的仍然都是质数。

找出全部11个这样从左向右和从右向左都可以裁剪的质数的和。

注意：2,3,5和7不被认为是可裁剪的质数。

[题目37：找出所有11个可以双向裁剪的质数。](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/38-3711 title="题目37")

## 题解

答案(answer): 748317

```python
#! /usr/bin/env python
# -*- coding: utf-8 -*-

isprime = [True for i in range(0, 1000000)]

def precess():
    isprime[0:2] = [False, False]
    for i in range(2, 1000000):
        if isprime[i]:
            n = i + i
            while n < 1000000:
                isprime[n] = False
                n += i

def trunc(n):
    m, n = len(str(n)), str(n)
    for i in range(0, m):
        if not isprime[int(n[i:m])] or not isprime[int(n[0:i+1])]:
            return False
    return True

if __name__ == '__main__':
    cnt, ans, start = 0, 0, 11
    precess()
    while cnt < 11:
        if isprime[start] and trunc(start):
            cnt += 1
            ans += start
        start += 2 # ignore all evens.
    print(ans)

# vim: set sw=4, ts=4
```
